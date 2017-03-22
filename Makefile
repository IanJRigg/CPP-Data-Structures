# Makefile for the data structures project
CXX := g++

# Compile Output Directories
LIB_DIR        := ./libraries

# Library Source Directories
BTREE          := ./btree
RBTREE         := ./rbtree
GRAPH          := ./graph
HASHTABLE      := ./hashtable
QUEUE          := ./queue
STACK          := ./stack

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

MAIN      := main
BTREE_LIB := $(LIB_DIR)/btree.a

BTREE_FILES   := $(shell find $(BTREE) -name "*.cc")
BTREE_OBJECTS := $(addsuffix .o, $(basename $(BTREE_FILES)))

INCLUDE_FLAGS := -I$(BTREE)

VPATH := $(BTREE)

.PHONY: all
all: $(BTREE_LIB)
	$(CXX) main.cc -o $(MAIN) $(INCLUDE_FLAGS) $(BTREE_LIB)

.PHONY: clean
clean:
	@rm -rf $(LIB_DIR)
	@rm -f  ./**/*.o
	@rm -f $(MAIN)

$(BTREE_LIB): $(BTREE_OBJECTS) $(LIB_DIR)
	$(AR) -r $@ $<

$(BTREE)/%.o: %.cc
	$(CXX) $(INCLUDE_FLAGS) -c $< -o $@

$(LIB_DIR):
	@mkdir $@