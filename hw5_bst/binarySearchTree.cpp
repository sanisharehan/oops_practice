// Homework#5: Implementation of basic BST(Binary Search Tree).
// Inplement simple insert and print values functions.

#include <iostream>
using namespace std;

// Define struct Node
template <typename T>
struct node {
	T val;
	node* left;
	node* right;
};

// Define a class BST
template <typename T>
class BSTree {
private:
	node<T> *root;

private:
	// Function to insert a new value in the BST while maintaining the property of BST
	void insertValRec(T val, node<T>* inRoot) {
		node<T> * temp = new node<T>;
		temp->val = val;
		temp->left = NULL;
		temp->right = NULL;

		// If the input val < root_val, insert to left of root
		if (val < inRoot->val) {
			if (inRoot->left == NULL) {
				cout << "Node value " << val << " added to the left" << endl;
				inRoot->left = temp;
			}
			else {
				insertValRec(val, inRoot->left);
			}
		}
		// If the input val > root_val, insert to right of root
		else if (val > inRoot->val) {
			if (inRoot->right == NULL) {
				cout << "Node value " << val << " added to the right" << endl;
				inRoot->right = temp;
			}
			else {
				insertValRec(val, inRoot->right);
			}
		}
		return;
	}

	// Function for recursively printing tree values
	void printTree(node <T>* rootNode) {
		if (rootNode == NULL) {
			return;
		}
		cout << rootNode->val << "\t";
		printTree(rootNode->left);
		printTree(rootNode->right);
		return;
	}

public:
	// Constructor for inititalizing root to NULL;
	BSTree<T>() {
		root = NULL;
	}

	node<T>* getRoot() {
		return root;
	}

	void printRoot() {
		cout << "The root node value is: " << root->val << endl;
	}

	// Function for inserting a new value to the BST
	void insertVal(T val) {
		node<T> * temp = new node<T>;
		temp->val = val;
		temp->left = NULL;
		temp->right = NULL;

		// If the BST is empty, create a node as new root with given value
		if (root == NULL) {
			root = temp;
			cout << "New root node added with val " << val << endl;
			return;
		}
		// Call the helper function
		insertValRec(val, root);
	}

	// Function to print all values of a BST(in any order)
	// Think about one node at a time, print its value, move to its left link
	// then right link and keep calling the function recursively
	void printTreeValues() {
		if (root == NULL) {
			cout << "BST has no values" << endl;
			return;
		}
		cout << "Printing BST values" << endl;
		printTree(root);
		return;
	}

};

int main(int argc, char *argv[]) {
	BSTree<int> newTree;
	newTree.insertVal(80);
	newTree.insertVal(90);
	newTree.insertVal(70);
	newTree.insertVal(75);
	newTree.insertVal(100);
	newTree.insertVal(60);
	newTree.printRoot();
	newTree.printTreeValues();
	return 0;
}
