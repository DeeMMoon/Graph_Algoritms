#ifndef GRAPH_STACK_H
#define GRAPH_STACK_H

#include <iostream>
#include <stdexcept>

template <typename T>
class Stack{
private:
    struct Node
    {
        T data;
        Node *next;
    };
    Node *root;
public:
    Stack() : root(nullptr){}
    void init()
    {
        Stack<T>();
    };
    void push(const T& value)
    {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = root;
        root = newNode;
    }

    bool empty() const
    {return !root;}

    T pop()
    {
        if (empty())
            throw std::length_error("Stack is empty");
        Node *delNode = root;
        T value = delNode->data;
        root = delNode->next;
        delete delNode;
        return value;
    }

    const T& peek()
    {
        if(empty())
            throw std::length_error("Stack is empty");
        return root->data;
    };

    ~Stack(){
        while (!empty())
            this->pop();
    }
};
#endif
