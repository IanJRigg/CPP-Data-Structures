################################################################################
# Makefile for the data structures project

# Compile Output Directories
LIB_DIR        := ./libraries

MAIN           := main

# Library Source Directories
BTREE          := ./btree
RBTREE         := ./rbtree
GRAPH          := ./graph
HASHTABLE      := ./hashtable
QUEUE          := ./queue
STACK          := ./stack

# Static Lib Files
BTREE_LIB      := $(LIB_DIR)/btree.a
RBTREE_LIB     := $(LIB_DIR)/rbtree.a
GRAPH_LIB      := $(LIB_DIR)/graph.a
HASHTABLE_LIB  := $(LIB_DIR)/hashtable.a
QUEUE_LIB      := $(LIB_DIR)/queue.a
STACK_LIB      := $(LIB_DIR)/stack.a

# Library Object Directories
BTREE_OBJ      := $(BTREE)/.obj
RBTREE_OBJ     := $(RBTREE)/.obj
GRAPH_OBJ      := $(GRAPH)/.obj
HASHTABLE_OBJ  := $(HASHTABLE)/.obj
QUEUE_OBJ      := $(QUEUE)/.obj
STACK_OBJ      := $(STACK)/.obj

# 

INCLUDE_FLAGS  := -Wall -Wextra -Werror -fstack-protector-all -std=c++11 -O3

MAIN_INCLUDE_FLAGS := $(INCLUDE_FLAGS) -I$(BTREE)

VPATH := $(BTREE)



################################################################################
# Generic GNU Make Targets

.PHONY: all
all: $(BTREE_LIB)
	$(CXX) main.cc -o $(MAIN) $(MAIN_INCLUDE_FLAGS) $(BTREE_LIB)

.PHONY: clean
clean:
	@rm -rf $(LIB_DIR)
	@rm -f  ./**/*.o
	@rm -f  $(MAIN)



################################################################################
# Binary Tree Compilation

# Binary Tree Constants
BTREE_FILES         := $(shell find $(BTREE) -name "*.cc")
BTREE_OBJECTS       := $(addsuffix .o, $(basename $(BTREE_FILES)))
BTREE_INCLUDE_FLAGS := $(INCLUDE_FLAGS) -I$(BTREE)

$(BTREE_LIB): $(BTREE_OBJECTS) $(LIB_DIR)
	$(AR) -r $@ $<

$(BTREE)/%.o: %.cc
	$(CXX) $(BTREE_INCLUDE_FLAGS) -c $< -o $@





################################################################################
# Miscelaneous directory rules

$(LIB_DIR):
	@mkdir $@