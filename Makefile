NAME		=	graph

CC			=	c++

#CPPFLAGS		+=	-Wall -Wextra -Werror -g -MMD

SRC_FILES	=	main.cpp

SRC_DIR		=	src

SRC			=	$(addprefix $(SRC_DIR)/,$(SRC_FILES))

OBJ_DIR		=	obj

OBJ			=	$(addprefix $(OBJ_DIR)/,$(SRC_FILES:.cpp=.o))

DEP			=	$(addprefix $(OBJ_DIR)/,$(SRC_FILES:.cpp=.d))

###############
GRAPH_FILES=	Graph.cpp\
				GraphAlgorithms.cpp

GRAPH_DIR	=	src/Graph
SRC			+=	$(addprefix $(GRAPH_DIR)/,$(GRAPH_FILES))
GRAPH_OBJ_DIR=	obj/Graph
OBJ			+=	$(addprefix $(GRAPH_OBJ_DIR)/,$(GRAPH_FILES:.cpp=.o))
DEP			+=	$(addprefix $(GRAPH_OBJ_DIR)/,$(GRAPH_FILES:.cpp=.d))
###############


INC_DIR		=	include
CPPFLAGS	+=	-I$(INC_DIR)

all: $(NAME)

-include $(DEP)

objdirs:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(GRAPH_OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

$(NAME): objdirs $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re objdirs
