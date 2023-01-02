#include "s21_graph_algorithms.h"

int *GraphAlgorithms::breadthFirstSearch(Graph &matrix, int startVertex) {
    int **graph = matrix.getGraph();
    int size = matrix.getSize();
    Queue<int> queue;
    queue.init();
    int visit_pos = 0;
    int j = 0;
    int i = 0;
    int *visited = new int[size];
    while (i < size)
    {
        visited[i] = -1;
        i++;
    }
    visited[visit_pos] = startVertex;
    visit_pos++;

    while (j < size)
    {
        if(graph[startVertex][j] != 0 && !isVisited(visited, size, j))
            queue.push(j);
        j++;
    }
    int visit;
    while (!queue.empty())
    {
        j = 0;
        visit = queue.pop();
        if(!isVisited(visited, size, visit)) {
            visited[visit_pos] = visit;
            visit_pos++;
        }
        while (j < size) {
            if (graph[visit][j] != 0 && !isVisited(visited, size, j))
                queue.push(j);
            j++;
        }
    }
    j = 0;
    while (visited[j] != -1 && j < size)
        j++;
    result_size = j;
    int *result = new int[j];
    for(int k = 0; k < j; k++)
        result[k] = visited[k];
    return result;
}

int *GraphAlgorithms::depthFirstSearch(Graph &matrix, int startVertex) {
    int **graph = matrix.getGraph();
    int size = matrix.getSize();
    Stack<int>stack;
    stack.init();
    int i = 0;
    int visit_pos = 0;
    int j = 0;
    int *visited = new int[size];
    while (i < size)
    {
        visited[i] = -1;
        i++;
    }
    visited[visit_pos] = startVertex;
    visit_pos++;
    while (j < size)
    {
        if(graph[startVertex][j] != 0 && !isVisited(visited, size, j))
            stack.push(j);
        j++;
    }
    int visit;
    while (!stack.empty())
    {
        j = 0;
        visit = stack.pop();
        if(!isVisited(visited, size, visit)) {
            visited[visit_pos] = visit;
            visit_pos++;
        }
        while (j < size) {
            if (graph[visit][j] != 0 && !isVisited(visited, size, j))
                stack.push(j);
            j++;
        }
    }
    j = 0;
    while (visited[j] != -1 && j < size)
        j++;
    result_size = j;
    int *result = new int[j];
    for(int k = 0; k < j; k++)
        result[k] = visited[k];
    return result;
}

bool GraphAlgorithms::isVisited(int *visited, int size, int vertex)
{
    int i = 0;
    while (i < size)
    {
        if(visited[i] == vertex)
            return true;
        i++;
    }
    return false;
}



int GraphAlgorithms::getShortestPathBetweenVertices(Graph &matrix, int vertex1, int vertex2){
    int **graph = matrix.getGraph();
    int size = matrix.getSize();
    int visited[size];
    int min_size[size];
    int tmp;
    int min;
    int min_index;
    for(int i = 0; i < size; i++)
    {
        visited[i] = 1;
        min_size[i] = INT_MAX;
    }
    min_size[vertex1] = 0;
    min_index = 0;
    while (min_index < INT_MAX)
    {
        min_index = INT_MAX;
        min = INT_MAX;
        for (int i = 0; i < size; i++) {
            if ((visited[i] == 1) && (min_size[i] < min))
            {
                min = min_size[i];
                min_index = i;
            }
        }
        if(min_index != INT_MAX)
        {
            for(int i = 0; i < size; i++)
            {
                if(graph[min_index][i] > 0)
                {
                    tmp = min + graph[min_index][i];
                    if (tmp < min_size[i]) {
                        min_size[i] = tmp;
                    }
                }
            }
            visited[min_index] = 0;
        }
    }
    return min_size[vertex2];
}

int** GraphAlgorithms::getShortestPathsBetweenAllVertices(Graph &matrix){
    int **graph = matrix.getGraph();
    int size = matrix.getSize();
    int **new_matrix;
    new_matrix = new int *[size];
    for(int i = 0; i < size; i++)
    {
        new_matrix[i] = new int [size];
    }

    for(int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            new_matrix[i][j] = graph[i][j];
        }
    }

    if (!checkMatrix(new_matrix, size))
        return nullptr;
    int max = getMatrixSum(new_matrix, size);
    for(int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if(new_matrix[i][j] == 0)
                new_matrix[i][j] = max;
        }
    }
    for(int k = 0; k < size; k++) {
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                if (new_matrix[i][j] >= new_matrix[i][k] + new_matrix[k][j])
                    new_matrix[i][j] = new_matrix[i][k] + new_matrix[k][j];
            }
        }
    }
    for(int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
             if(new_matrix[i][j] == max)
                 new_matrix[i][j] = 0;
        }
    }

    return (new_matrix);
}

long GraphAlgorithms::getMatrixSum(int **matrix, int size) {
    long value = 0;
    for(int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            value += matrix[i][j];
        }
    }
    return value;
}

bool GraphAlgorithms::checkMatrix(int **matrix, int size) {
    long value;
    value = getMatrixSum(matrix, size);
    if (value > INT_MAX)
        return false;
    return true;
}


