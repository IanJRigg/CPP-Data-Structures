# Makefile for the data structures project

# Compile Output Directories
LIB_DIR        := ./libraries

# Library Source Directories
BTREE          := ./btree
RBTREE         := ./rbtree
GRAPH          := ./graph
HASHTABLE      := ./hashtable
QUEUE          := ./queue
STACK          := ./stack

RBTREE_LIB     := btree.a
GRAPH_LIB      := graph.a
HASHTABLE_LIB  := hashtable.a
QUEUE_LIB      := queue.a
STACK_LIB      := stack.a

# Library Object Directories
BTREE_OBJ      := $(BTREE)/.obj
RBTREE_OBJ     := $(RBTREE)/.obj
GRAPH_OBJ      := $(GRAPH)/.obj
HASHTABLE_OBJ  := $(HASHTABLE)/.obj
QUEUE_OBJ      := $(QUEUE)/.obj
STACK_OBJ      := $(STACK)/.obj

MAIN      := main
BTREE_LIB := $(LIB_DIR)/btree.a

BTREE_FILES   := $(shell find $(BTREE) -name "*.cc")
BTREE_OBJECTS := $(addsuffix .o, $(basename $(BTREE_FILES)))

INCLUDE_FLAGS := -I$(BTREE)

VPATH := $(BTREE)

.PHONY: all
all: $(BTREE_LIB)
	$(CXX) main.cc -o $(MAIN) $(INCLUDE_FLAGS) -L$(LIB_DIR)

.PHONY: clean
clean:
	@rm -rf $(EXECUTABLE_DIR)

$(LIB_DIR):
	@mkdir $@

$(BTREE_LIB): btree/binary-tree.o
	@echo $(BTREE)
	@echo $(BTREE_OBJECTS)
	$(AR) rvs $@ $^

btree/binary-tree.o: binary-tree.cc
	$(CXX) $(INCLUDE_FLAGS) -c $< -o $@