# Makefile for the data structures project

# Compile Output Directories
EXECUTABLE_DIR := ./executables
LIB_DIR        := ./libraries

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

MAIN      := $(EXECUTABLE_DIR)/main
BTREE_LIB := $(LIB_DIR)/btree.a

BTREE_FILES   := $(shell find $(BTREE) -name "*.cc")
BTREE_OBJECTS := $(addsuffix .o, $(basename $(BTREE_FILES)))

INCLUDE_FLAGS := -I$(BTREE)

VPATH := $(BTREE)


.PHONY: all
all: $(LIBS) $(EXECUTABLE_DIR)
	$(CXX) main.cc -o $(MAIN) $(INCLUDE_FLAGS)  -lbtree

.PHONY: clean
clean:
	@rm -rf $(EXECUTABLE_DIR)


$(LIB_DIR):
	@mkdir $@



$(BTREE): $(BTREE_OBJECTS)
	$(AR) rvs $@ $^

$(BTREE_LIB)/%.o: %.cc
	$(CXX) -c $< $(INCLUDE_FLAGS) -o $@


$(EXECUTABLE_DIR):
	@mkdir $@