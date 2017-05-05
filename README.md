# C++ Data Structures Implementations
The following repository is used for tracking various C++ Data Structures.

### Currently planned data structures:
1. Linked List
2. Stack
3. Queue
4. Binary Tree

### Possible future additions:
1. Red Black Tree
    - Current inheritance solution isn't going to work, the root node of the BST is a shared pointer whose template class is the binary node, which doesn't include the color of the node. The easiest solution is to just re-use the code from the binary tree with modifications accounting for the color of the node.  This currently remains an indefinite TODO.


