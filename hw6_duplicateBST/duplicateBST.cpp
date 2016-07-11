// Homework#6: Are duplicate values allowed in a BST? How to handle/add duplicate values insertion in a BST.
// Generally, by definition, a BST is an ordered tree with no duplicate keys/nodes. However, in case 
// we wish to add duplicate keys, there can be many ways.
//
// a. We can keep a track of count of values with every node.
// b. We can keep adding same node in one direction of the root. eg. lets say a BST is such that
// left <= root_val and right > root_val, then any duplicate value withh always go to the left side of the node.
// Useful links:
// http://www.geeksforgeeks.org/how-to-handle-duplicates-in-binary-search-tree/
// 

#include <iostream>
using namespace std;

struct bst_node {
	int count;
	int val;
	bst_node *left;
	bst_node *right;
};

class BST_ex {
	bst_node *root;
};
