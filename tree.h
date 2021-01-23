#ifndef TREE_H
#define TREE_H

#include "treenode.h"

template<typename T>
class BinarySearchTree {

private:
	unique_ptr<TreeNode<T> > root; // should contain a pointer to the root TreeNode
	//bool alreadyInTree = false;
	//bool isInsert = false;

public:

	void write(ostream & o) const {

		root->write(o);

	}

	//find should be const
	//insert needs to be non const

	TreeNode<T>* insertSearch(TreeNode<T> * currentNode, const T & dataToInsert) {


		cout << "before data is inserted";
		cout << "is dataToInsert < currentNode->data? ... " << (dataToInsert < currentNode->data) << "\n";
		if (dataToInsert < currentNode->data) {
			// Search for left child of currentNode:
			if (currentNode->leftChild) { // is there a left child?
				insertSearch(currentNode->leftChild.get(), dataToInsert); // search further!
			}
			else {
				// DATA NOT YET IN TREE!

				TreeNode<T> * insertNode = new TreeNode<T>(dataToInsert);

				currentNode -> setLeftChild(insertNode);

				return insertNode; // return a pointer to it

			}
		}

		else if (currentNode->data < dataToInsert) {
			// Search for right child of currentNode:
			if (currentNode->rightChild) { // is there a right child?
				insertSearch(currentNode->rightChild.get(), dataToInsert); // search further!
			}
			else {
				// DATA NOT YET IN TREE!

				TreeNode<T> * insertNode = new TreeNode<T>(dataToInsert);

				currentNode -> setRightChild(insertNode);

				return insertNode; // return a pointer to it
			}
		}

		else {
			// NODE HERE ALREADY
			return currentNode;
		}
	}

	TreeNode<T> * insert(T dataToInsert) {

		if (root) {
			insertSearch(root.get(), dataToInsert);
		}

		else {
		// insert it!
			root.reset(new TreeNode<T>(dataToInsert));
			return root.get(); // return a pointer to it
		}

	}


	//find should be const
	//insert needs to be non const

	TreeNode<T>* findSearch(TreeNode<T> * currentNode, const T & dataToFind) const {

		if (dataToFind < currentNode->data) {
			// Search for left child of currentNode:
			if (currentNode->leftChild) { // is there a left child?
				return findSearch(currentNode->leftChild.get(), dataToFind); // search further!
			}
			else {
				// DATA NOT IN TREE!
				return nullptr;
			}
		}
		else if (currentNode->data < dataToFind) {
			// Search for right child of currentNode:
			if (currentNode->rightChild) { // is there a right child?
				return findSearch(currentNode->rightChild.get(), dataToFind); // search further!
			}
			else {
				// DATA NOT IN TREE!
				return nullptr;
			}
		}
		else {
			// NODE IS HERE
			return currentNode;
		}
	}

	TreeNode<T> * find(const T & dataToFind) const {


		if (root) {
			return findSearch(root.get(), dataToFind);
		}
		else {
			return nullptr;
		}

	}




	//function which complete the first part of an inorder traversal
    TreeNodeIterator<T> begin() {

    	cout << "before begin function in BinarySearchTree";

    	//Function to visit nodes in Inorder

    	//if(node.data == NULL) return;

    	if (!root) return TreeNodeIterator<T>(nullptr);

		TreeNode<T> * farLeft;
    	while (root->leftChild) {

    		farLeft = root->leftChild.get(); // USE GET
    	}

    	return TreeNodeIterator<T>(farLeft);

    	//Algorithm Inorder(tree)
    	 //  1. Traverse the left subtree, i.e., call Inorder(left-subtree)
    	 //  2. Visit the root.
    	 //  3. Traverse the right subtree, i.e., call Inorder(right-subtree)
    }


    TreeNodeIterator<T> end() {
    	cout << "before end function in BinarySearchTree";
    	return TreeNodeIterator<T>(nullptr);
    }

    //for BinarySearchTree
	int maxDepth() {
		if (!root) { //empty
			//return 0; // to become 1 when 1 is added...
			return 1;
		}

		root->maxDepth(); //call function through the unique_ptr
	}

    /*void insert(TreeNode<T> treenode) {
        int balanceFactor = maxDepth(root->leftChild) - maxDepth(root->rightChild)

    	if (balanceFactor < -1 || balanceFactor > 1 ) {
    		rebalance();
    	}

    }

    int balanceFactor() {
    	return maxDepth(root->leftChild) - maxDepth(root->rightChild)
    }

    void rebalance() {
    	//balanceFactor(node) = maxDepth(left node) - maxDepth(right node)
    	int balanceFactor = maxDepth(root->leftChild) - maxDepth(root->rightChild)

    	if(balanceFactor > 0) { // balance factor is positive, then head to the left subtree

    			//if depth of left node is positive
				if (root->leftChild.balanceFactor() > 0) {
					//LL rotation function
				}

    			//if depth of left node is negative
				else if (root->rightChild.balanceFactor() < 0) {
					//LR rotation function
				}
    	}

		else if(balanceFactor < 0) { // balance factor is negative, then head to the left subtree

			//if depth of right node is positive
			if (root->leftChild.balanceFactor() > 0) {
				//RL rotation function
			}

			//if depth of right node is negative
			else if (root->rightChild.balanceFactor() < 0) {
				//RR rotation function
			}
		}

    }*/

};


// do not edit below this line

#endif

