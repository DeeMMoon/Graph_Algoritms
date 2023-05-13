NAME					= programm

LIB_DIR					= lib
GRAPH_LIB				= $(LIB_DIR)/s21_graph.a
ALGOS_LIB				= $(LIB_DIR)/s21_graph_algorithms.a

APP_DIR					= app
APP_SRCS				= $(shell find $(APP_DIR) -name "*.cpp")
APP_OBJS				= $(patsubst %.cpp, %.o, $(APP_SRCS))
APP_D_FILES				= ${patsubst %.cpp, %.d, ${APP_SRCS}}

CONTANIERS_DIR			= containers
STACK_LIB_DIR			= $(CONTANIERS_DIR)/stack
QUEUE_LIB_DIR			= $(CONTANIERS_DIR)/queue
STACK_LIB				= $(STACK_LIB_DIR)/stack.a
QUEUE_LIB				= $(QUEUE_LIB_DIR)/queue.a

## s21_graph.h static library sources
GRAPH_DIR				= graph
GRAPH_HEADERS_DIR		= $(GRAPH_DIR)/includes
GRAPH_INCLUDES			= -I$(GRAPH_HEADERS_DIR)
GRAPH_SRCS				:= $(shell find $(GRAPH_DIR) -name "*.cpp")
GRAPH_OBJS				= $(patsubst %.cpp, %.o, $(GRAPH_SRCS))
GRAPH_D_FILES			= ${patsubst %.cpp, %.d, ${GRAPH_SRCS}}

## s21_graph_algorithms.h static library sources
ALGOS_DIR				= graph_algorithms
ALGOS_HEADERS_DIR		= $(ALGOS_DIR)/includes $()
ALGOS_INCLUDES			= -I$(ALGOS_HEADERS_DIR) $(GRAPH_INCLUDES)
ALGOS_SRCS				:= $(shell find $(ALGOS_DIR) -name "*.cpp")
ALGOS_OBJS				= $(patsubst %.cpp, %.o, $(ALGOS_SRCS))
ALGOS_D_FILES			= ${patsubst %.cpp, %.d, ${ALGOS_SRCS}}

CC				= clang++
CFLAGS			= -Werror -Wall -Wextra -std=c++17 #-fsanitize=address,undefined -fno-sanitize-recover -fstack-protector -g -O0
AR				= ar -rcs

all:	$(NAME)

$(LIB_DIR):
		mkdir $(LIB_DIR)

libs: $(ALGOS_LIB) $(GRAPH_LIB) $(STACK_LIB) $(QUEUE_LIB)

$(GRAPH_DIR)/%.o: $(GRAPH_DIR)/%.cpp
		$(CC) $(CFLAGS) -c $(GRAPH_INCLUDES) $< -o $@ -MMD

$(GRAPH_LIB): $(GRAPH_OBJS) $(LIB_DIR)
		$(AR) $(GRAPH_LIB) $(GRAPH_OBJS)

$(STACK_LIB): $(STACK_LIB_DIR)
		make -C $(STACK_LIB_DIR)

$(QUEUE_LIB): $(QUEUE_LIB_DIR)
		make -C $(QUEUE_LIB_DIR)

$(ALGOS_DIR)/%.o: $(ALGOS_DIR)/%.cpp $(STACK_LIB) $(QUEUE_LIB) $(GRAPH_LIB)
		$(CC) $(CFLAGS) $(ALGOS_INCLUDES) -I$(STACK_LIB_DIR) -I$(QUEUE_LIB_DIR) $< -c -o $@ -MMD

$(ALGOS_LIB): $(ALGOS_OBJS) $(LIB_DIR) $(STACK_LIB) $(QUEUE_LIB)
		$(AR) $(ALGOS_LIB) $(ALGOS_OBJS)


$(NAME): $(GRAPH_LIB) $(ALGOS_LIB) $(STACK_LIB) $(QUEUE_LIB) $(APP_SRCS)
		$(CC) $(CFLAGS) $(APP_SRCS) $(APP_INCLUDES) $(ALGOS_INCLUDES) \
		-o $(NAME) $(GRAPH_LIB) $(ALGOS_OBJS) #graph_algorithms/GraphAlgorithms.o

clean:
		@rm -f $(GRAPH_OBJS) $(ALGOS_OBJS) $(APP_OBJS) \
		$(APP_D_FILES) $(GRAPH_D_FILES) $(ALGOS_D_FILES) $(GRAPH_LIB) $(ALGOS_LIB) \
		$(STACK_LIB) $(QUEUE_LIB)
		make -C $(STACK_LIB_DIR) clean
		make -C $(QUEUE_LIB_DIR) clean

fclean: clean
		@rm -rf $(NAME) $(LIB_DIR) $(STACK_LIB) $(QUEUE_LIB)

re:		fclean all

style: 	
		clang-format -i app/*.cpp 
		clang-format -i containers/stack/*.cpp 
		clang-format -i containers/stack/*.h 
		clang-format -i containers/queue/*.cpp 
		clang-format -i graph/includes/*.h 
		clang-format -i graph/*.cpp 
		clang-format -i graph_algorithms/includes/*.h 
		clang-format -i graph_algorithms/*.cpp 
		clang-format -n app/*.cpp 
		clang-format -n containers/stack/*.cpp 
		clang-format -n containers/stack/*.h 
		clang-format -n containers/queue/*.cpp 
		clang-format -n graph/includes/*.h 
		clang-format -n graph/*.cpp 
		clang-format -n graph_algorithms/includes/*.h 
		clang-format -n graph_algorithms/*.cpp 

test:
	make -C ../tests
	# cd ../tests && ${MAKE}

include $(wildcard $(APP_D_FILES) $(GRAPH_D_FILES) $(ALGOS_D_FILES))

.PHONY: all clean test s21_graph.a s21_graph_algorithms.a fclean re
