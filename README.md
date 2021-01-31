# Binary Search Trees

A Binary Search Tree template class. 

Note that I implement the functionality myself, without using too many additional data structures from the standard library.  I have added `#include <memory>` for `std::unique_ptr`, `#include <utility>` for `std::pair`, and `#include <iostream>`.

## Making a tree node

In the file `treenode.h` is a template class `TreeNode` that represents a node in a binary search tree.  It has four `public` member variables:

- The `data` stored in that node.  The type of this should be a template argument.
- A unique_ptr<TreeNode> for the left child of the node;
- A unique_ptr<TreeNode> for the right child of the node;
- A pointer to the parent of the node (NB not a unique_ptr)

You should then be able to write, e.g:

`someNode->write(cout);`  

...to be able to print the subtree starting at some node to screen. 

To test the code, compile and run TestTreeNode.cpp.  A Makefile has been provided, run:

`make TestTreeNode`  

...at the command line.  This makes four tree nodes, linked to each other, then prints out the tree.

## Making a tree

In the file `tree.h` is a template class BinarySearchTree.  This uses the `TreeNode` class.

### write

The function `write` takes an `ostream` reference and calls `write` on the root of the tree.

### insert

The function `insert` takes an item of data and inserts it into the tree:

- If the data is not already in the tree, it should make a node and add this in the correct place
- If something equal to the data is already in the tree, it shouldn't make any new nodes, and shouldn't change any of the existing nodes.

In both cases, it should return a `TreeNode*`, pointing to the node containing the data.

For each node, if it has a left child, then `left->data < data`, and if it has a right child, then `data < right->data`.

### find

The function `find` takes an item of data and traverses the Binary Search Tree to see if the data is in the tree.

If it is, it returns a `TreeNode*` pointing to the node containing the data.

If it is not in the tree, it returns `nullptr`

To test this code, compile and run TestTree.cpp.  A Makefile has been provided, run:

`make TestTree` 

...at the command line.

## TreeMap

### KeyValuePair

In the file `treemap.h`, the incomplete class `KeyValuePair` defines a class that holds a key--value pair that will be used to make a map.

### TreeMap

In the file `treemap.h`, the class `TreeMap` defines a class that holds a tree of key--value pairs.

The function `find` takes a Key, makes a KeyValuePair from it, and calls `find` on the tree to see if a match can be found.  If it can be found, it returns a pointer to the *data* inside the tree node found by find (a `KeyValuePair<Key,Value>*`). If not, returns nullptr.

To test this code, compile and run TestTreeMap.cpp.  A Makefile has been provided, run:

`make TestTreeMap`  

...at the command line.

# Binary Search Trees, Further

## An iterator

In `treenode.h` is a template class `TreeNodeIterator` that is an iterator over a binary search tree. This steps through the tree in ascending order.

## maxDepth

In `TreeNode` is a function maxDepth that returns the maximum depth of the subtree rooted at that node. If the TreeNode has no children, it has depth 1.  Otherwise, its depth is 1 + the maximum of either the depth of its left child, or the depth of its right child.

In `BinarySearchTree` is a function maxDepth that returns the maxDepth of the root (or 0 for an empty tree).

## AVL trees

In the worst case, when using a Binary Search Tree, the data is adding in ascending order, giving the following tree:

`A`  
`.\`  
`..B`  
`...\`  
`....C`  

That is, the depth of the tree is the same as the number of elements.  What we ideally want is a balanced tree, where the depth of the tree is *log(N)* in the number of elements, N.

AVL trees rebalance the tree every time a node is inserted.  This is done by computing the *balance factor* of that node.  It is computed as:

`balanceFactor(node) = maxDepth(left node) - maxDepth(right node)`

If this balance factor is ever 2, or -2, the tree beneath that node needs to be rebalanced: it is much deeper on one side than the other.  

To become rebalanced, an AVL tree performs one of four operations.  These performed where needed in `insert` in the BinarySearchTree class.  

### Left rotation

If a node becomes unbalanced, when a node is inserted into the right subtree of its right child, then we perform a left rotation. Each of these nodes now have a balance factor of 0, so it is balanced again.

### Right rotation

If a node becomes unbalanced when a node is inserted into the left subtree of its left child, then we perform a right rotation.  

### Left-Right rotation

If a node becomes unbalanced when a node is inserted into the right subtree of its left child, then we perform a left-right rotation. 

### Right-left rotation

One scenario left: a node becomes unbalanced when a node is inserted into the left subtree of its right child, then we perform a right-left rotation.  

To test this code, compile and run TestTreeD.cpp.  A Makefile has been provided, run:

`make TestTreeD`  

...at the command line.
