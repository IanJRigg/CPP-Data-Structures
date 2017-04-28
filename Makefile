################################################################################
# Makefile for the data structures project

# Compile Output Directories
MAIN           := main

# Library Source Directories
BTREE          := ./btree
RBTREE         := ./rbtree
GRAPH          := ./graph
HASHTABLE      := ./hashtable
QUEUE          := ./queue
STACK          := ./stack
LLIST          := ./llist
TEST           := ./test


TEST_FILES := $(shell find $(TEST) -name "*.cc")
TEST_OBJS  := $(addsuffix .o, $(basename $(TEST_FILES)))

INCLUDE_FLAGS  := -Wall -Wextra -Werror -fstack-protector-all -std=c++11 -O3

MAIN_INCLUDE_FLAGS := $(INCLUDE_FLAGS) \
                      -I$(TEST)

TEST_INCLUDE_FLAGS := $(INCLUDE_FLAGS) \
                      -I./             \
                      -I$(BTREE)       \
                      -I$(RBTREE)      \
                      -I$(LLIST)       \
                      -I$(STACK)       \
                      -I$(QUEUE)       \
                      -I$(TEST)


################################################################################
# Generic GNU Make Targets

.PHONY: all
all: test

.PHONY: test
test: $(TEST_OBJS)
	g++ main.cc $^ -o $(MAIN) $(MAIN_INCLUDE_FLAGS)

.PHONY: clean
clean:
	@rm -rf $(LIB_DIR)
	@rm -f  ./**/*.o
	@rm -f  $(MAIN)

%.o : %.cc
	$(info $(TEST_OBJS))
	$(CXX) $(TEST_INCLUDE_FLAGS) -c $< -o $@