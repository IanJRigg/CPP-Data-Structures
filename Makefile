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

# Library Object Directories
BTREE_OBJ      := $(BTREE)/.obj
RBTREE_OBJ     := $(RBTREE)/.obj
GRAPH_OBJ      := $(GRAPH)/.obj
HASHTABLE_OBJ  := $(HASHTABLE)/.obj
QUEUE_OBJ      := $(QUEUE)/.obj
STACK_OBJ      := $(STACK)/.obj

INCLUDE_FLAGS  := -Wall -Wextra -Werror -fstack-protector-all -std=c++11 -O3

MAIN_INCLUDE_FLAGS := $(INCLUDE_FLAGS) -I$(BTREE)

VPATH := $(BTREE)



################################################################################
# Generic GNU Make Targets

.PHONY: all
all:
	g++ main.cc -o $(MAIN) $(MAIN_INCLUDE_FLAGS) $(BTREE_LIB)

.PHONY: clean
clean:
	@rm -rf $(LIB_DIR)
	@rm -f  ./**/*.o
	@rm -f  $(MAIN)

################################################################################
# Miscelaneous directory rules

$(LIB_DIR):
	@mkdir $@