#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;

#include <sstream>
using std::ostringstream;

#include <memory>
using std::unique_ptr;

#include <utility>
using std::pair;

// code for the TreeNode class here

#include <algorithm>
using std::max;

template<typename T>
class TreeNode{

public:

    T data; // the data type is template argument

    unique_ptr<TreeNode<T> > leftChild = nullptr;
    unique_ptr<TreeNode<T> > rightChild = nullptr;

    TreeNode<T> * parent;









    // constructor that takes an item of data, stores it in the node & sets the parent pointer to nullptr as a sensible default
    TreeNode(T dataIn)
    : data(dataIn),
	  parent(nullptr) {}

    void setParent(TreeNode<T> * parentIn) {
    	cout << "about to set parent";
    	parent = parentIn;
    }

    void setLeftChild(TreeNode* child) {
    	//stores child in the left unique_ptr by calling reset() on it
    	leftChild.reset(child); //deletes what it used to point to, now points to what I've just given it. Deletes what it used to be pointing to.
		child->parent=this; //?? make child's parent pointer point to this?
    	//the member variables are public, so are getters unnecessary?
    }

    // Write an analogous function setRightChild for setting the right child of the node.
    void setRightChild(TreeNode* child) {
    	//stores child in the left unique_ptr by calling reset() on it
    	rightChild.reset(child); //deletes what it used to point to, now points to what I've just given it. Deletes what it used to be pointing to.
    	//sets the parent pointer of the child to point to 'this'

		child->parent=this; //??
        }

	void write(ostream & o) const {

    	if (leftChild) {
        	leftChild->write(o); // ?
    	}
    		o << " "
		<< data
		<< " ";
    	if (rightChild) {
		rightChild->write(o); // ?
    	}

    }





    /*int balanceFactor() {
    	return maxDepth(root->leftChild) - maxDepth(root->rightChild)
    }*/

	int maxDepth() {
		//find depth of left and right subtrees
		//maxDepth is the greater of these + 1

		if (!(leftChild && rightChild)) { //empty
			//return 0; // to become 1 when 1 is added...
			return 1;
		}


		//if tree/subtree has left child
		int leftDepth = leftChild->maxDepth();
		//if tree/subtree has right child
		int rightDepth = rightChild->maxDepth();

		return max(leftDepth, rightDepth) + 1;
	}

};





template<typename T> //  This should use the Node class you have written so far
class TreeNodeIterator {

	TreeNode<T> * treeNodePointer;

public:

	//constructor for the advanced part
	TreeNodeIterator(TreeNode<T> * treenode) {
	cout << "TreeNodePointer constructor";
	treeNodePointer = treenode;
	}

    T & operator*() {
        return treeNodePointer->data;
    }

    bool operator==(const TreeNodeIterator<T> & otherIterator) {
    	return otherIterator.treeNodePointer == treeNodePointer;
    }

    bool operator!=(const TreeNodeIterator<T> & otherIterator) {
    	return otherIterator.treeNodePointer != treeNodePointer;
    }

    void operator++() {
    	//treeNodePointer = treeNodePointer->next;

    	//if there's a left subtree, visit it
    	if (treeNodePointer -> leftChild != nullptr){
    		cout << "entered if where pointer isnt left child\n";
    		treeNodePointer->leftChild.get();
    		ostringstream s;
    		treeNodePointer->write(s);
    		cout << s.str();
    	}

    	//any parent bigger it will always be the edge case
    	//it can never be a left
		//possibility its first right
		//if has parent which is smaller redo all checks, on the parent.
		//continue going up parents until find one bigger

    	//visit center
    		//treeNodePointer = treeNodePointer->data;

    	//if there's a right subtree, visit it
    	if (treeNodePointer -> rightChild != nullptr) {
    		treeNodePointer->rightChild.get();
    	}

    	//Algorithm Inorder(tree)
    	 //  1. Traverse the left subtree, i.e., call Inorder(left-subtree)
    	 //  2. Visit the root.
    	 //  3. Traverse the right subtree, i.e., call Inorder(right-subtree)

    	//core dump usually means trying to access something while the vector is null
    	//cout all the steps walk through.
    }



};

// do not edit below this line

#endif

