//
// Homework#10 (a): Implement a tree as a linked list. A linked list is similar to a tree except that 
// we only keep links in one direction. Hence, for every node in a tree, if we make either left/right link == NULL,
// this would become similar to a linked list.
// Include the following functions:
// a. insert(val v)
// b. deleteRoot()
// c. deleteLastNode()
// d. createNewRoot(val v)
// e. printVal()
// f. returnRoot()
// g. returnLastNode()
// h. getSize()
//

#include <iostream>
using namespace std;

template <typename T>
struct Node {
	T val;
	Node<T> *left;
	Node<T> *right = NULL;
};

template <typename T>
class BinaryTreeLikeLinkedList {
private:
	Node<T> *root;

	// Function to insert a new value in the BST while maintaining the property of BST
	void insertValRec(Node<T> *newVal, Node<T>* inRoot) {
		// New value is always inserted to the left and right is always NULL
		if (inRoot->left == NULL) {
			cout << "Node value " << newVal->val << " added to the left" << endl;
			inRoot->left = newVal;
		}
		else {
			insertValRec(newVal, inRoot->left);
		}
		return;
	}

	// Helper function for deleting last node
	int deleteLastNodeRec(Node<T> *inRoot) {
		if (inRoot->left == NULL) {
			// It means this is the last node
			return 1;
		}
		int i = deleteLastNodeRec(inRoot->left);
		if (i == 1) {
			cout << "Deleting last node with val: " << inRoot->left->val << endl;
			inRoot->left = NULL;
		}
		return 0;
	}

	// Helper function for tree/list traversal
	void printValRec(Node<T> *inNode) {
		if (inNode == NULL) {
			return;
		}
		cout << inNode->val << "\t";
		printValRec(inNode->left);
		return;
	}

	// Helper function for returning last node
	Node<T> * returnLastNodeRec(Node<T> *inNode) {
		if (inNode->left == NULL) {
			return inNode;
		}
		return returnLastNodeRec(inNode->left);
	}

public:
	BinaryTreeLikeLinkedList() {
		root = NULL;
	}

	// a. Function for inserting a new value to the tree
	void insert(T val) {
		Node<T> * temp = new Node<T>;
		temp->val = val;
		temp->left = NULL;

		// If the BST is empty, create a node as new root with given value
		if (root == NULL) {
			root = temp;
			cout << "New root node added with val " << val << endl;
			return;
		}
		// Call the helper function
		insertValRec(temp, root);
	}

	// b. deleteRoot for deleting the root and changing the root value
	void deleteRoot() {
		if (root == NULL) {
			cout << "No entries in the tree/linked list" << endl;
			return;
		}
		cout << "Deleting root from list/tree" << endl;
		Node<T> * newRoot;
		if (root->left == NULL) {
			cout << "Only single root present in the list" << endl;
			root = NULL;
		}
		else {
			newRoot = root->left;
			root = newRoot;
			cout << "Deleted root from list/tree; new root: " << root->val << endl;
		}
		return;	
	}

	// c. Function to delete last node from the list/tree
	void deleteLastNode() {
		if (root == NULL) {
			cout << "Tree/list is empty" << endl;
			return;
		}
		int i = deleteLastNodeRec(root);
		if (i == 1) {
			cout << "Only root is present, deleting it" << endl;
			root = NULL;
		}
		return;
	}

	// d. Function for creating new root with given value
	void createNewRoot(T val) {
		Node<T> *oldRoot = new Node<T>;
		oldRoot = root;
		Node<T> *newRoot = new Node<T>;
		newRoot->val = val;
		newRoot->left = oldRoot;
		root = newRoot;
		cout << "Created new root with value: " << root->val << endl;
	}

	// e. Function to print all values
	void printValues() {
		if (root == NULL) {
			cout << "Tree/list is empty" << endl;
			return;
		}
		cout << "Print values: " << endl;
		printValRec(root);
	}

	// f. Function to return root
	Node<T>* returnRoot() {
		if (root == NULL) {
			cout << "Tree/list is empty" << endl;
		}
		return root;
	}

	// g. Function to return last node
	Node<T> *returnLastNode() {
		if (root == NULL) {
			cout << "Tree/list is empty" << endl;
			return NULL;
		}
		return returnLastNodeRec(root);
	}

	// h. Function to get tree/list size
	int getSize() {
		if (root == NULL) {
			cout << "Tree/list is empty" << endl;
			return 0;
		}
		int size = 1;
		Node<T> *startRoot = root;
		while (startRoot->left != NULL) {
			size++;
			startRoot = startRoot->left;
		}
		return size;
	}
};


int main(int argc, char *argv[]) {
	BinaryTreeLikeLinkedList<int> newTree;
	cout << "Tree initial size: " << newTree.getSize() << endl;
	newTree.insert(80);
	newTree.insert(90);
	newTree.insert(70);
	newTree.insert(60);
	newTree.insert(100);
	newTree.insert(200);
	cout << "Tree after insertion size: " << newTree.getSize() << endl;
	newTree.deleteRoot();
	newTree.deleteLastNode();
	newTree.createNewRoot(45);
	newTree.printValues();
	cout << "Tree root node is: " << newTree.returnRoot()->val << endl;
	cout << "Tree last node is: " << newTree.returnLastNode()->val << endl;
	cout << "Tree final size: " << newTree.getSize() << endl;
	char c;
	cin >> c;
	return 0;
}

// Output
/*
Tree/list is empty
Tree initial size: 0
New root node added with val 80
Node value 90 added to the left
Node value 70 added to the left
Node value 60 added to the left
Node value 100 added to the left
Node value 200 added to the left
Tree after insertion size: 6
Deleting root from list/tree
Deleted root from list/tree; new root: 90
Deleting last node with val: 200
Created new root with value: 45
Print values: 
45	90	70	60	100	Tree root node is: 45
Tree last node is: 100
Tree final size: 5
*/
