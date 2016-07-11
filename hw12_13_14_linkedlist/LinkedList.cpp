//
// Homework#12: Implement LinkedList class which includes all the primitive LinkedList features
// as mentioned below:
// a. InsertFirst: Function to insert element at beginning of linkedlist.
// b. DeleteFirst: Function to delete element from beginning of linkedlist. 
// c. display: Display all elements in a linked list.
// d. search: Search for a given element in list with a given key.
// e. delete: Delete an element with a given key from list.
// f. getSize: Display size of linked list.
// g. insertEnd: Insert an element at end of linkedlist.
// h. insert(val, place): insert element at a given place from beginning in linked list.
// i. deleteEnd: Delete element from end of linked list.
// j. deleteIndex: Delete element at a given index from linked list.
//
// Homework#13: Write additional functions to reverse a linked list recursively and iteratively.
// k. reverseIter(): Function to reverse a linked list itertively
// l. reverseRec(): Function to reverse a linked list recursively
//
// Homework#14: To check if a linked list is palindromic or not
// m. isPalindrome(): Returns true if a linked list is palindromic
//

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
struct Node {
	T val;
	Node<T> *next;
};

template <typename T>
class LinkedList {
private:
	Node<T> *root;

	bool isListEmpty() {
		if (root == NULL) {
			cout << "Linked List is empty" << endl;
			return true;
		}
		return false;
	}

	// Helper function to display the elements of list recursively
	void displayHelperRec(Node<T> *inRoot) {
		if (inRoot == NULL) {
			return;
		}
		cout << inRoot->val << "\t";
		displayHelperRec(inRoot->next);
	}

	// Helper function to reverse the list recursively
	int reverseHelperRec(Node<T> *inRoot) {
		if (inRoot->next == NULL) {
			return 1;
		}
		int i = reverseHelperRec(inRoot->next);
		inRoot->next->next = inRoot;
		if (i == 1) {
			root = inRoot->next;
		}
		return 0;
	}

public:
	LinkedList() {
		root = NULL;
	}

	// a. InsertFirst: Function to insert element at beginning of linkedlist.
	void insertFirst(T val) {
		Node<T> *temp = new Node<T>;
		temp->val = val;
		temp->next = NULL;
		if (isListEmpty()) {
			root = temp;
			cout << "New root is: " << root->val << endl;
			return;
		}
		temp->next = root;
		cout << "Old root is: " << root->val << endl;
		root = temp;
		cout << "New root is: " << root->val << endl;
	}

	// b. DeleteFirst: Function to delete element from beginning of linkedlist. 
	void deleteFirst() {
		if (isListEmpty()) {
			return;
		}
		if (root->next == NULL) {
			cout << "Only one element in list, deleting root with val: " << root->val << endl;
			root = NULL;
			return;
		}
		root = root->next;
		cout << "New root after deletion is: " << root->val << endl;
	}

	// c. display: Display all elements in a linked list.
	void displayIter() {
		if (isListEmpty()) {
			return;
		}
		// Printing the values iteratively
		Node<T> *temp = root;
		cout << temp->val << "\t";
		while (temp->next != NULL) {
			cout << temp->next->val << "\t";
			temp = temp->next;
		}
		cout << endl;
	}

	void displayRec() {
		if (isListEmpty()) {
			return;
		}
		displayHelperRec(root);
		cout << endl;
	}

	// d. search: Search for a given element in list with a given key. Return the element number
	// from root else -1
	int search(T val) {
		if (isListEmpty()) {
			return -1;
		}
		int index = 0;
		Node<T> *temp = root;
		if (temp->val == val) {
			return index;
		}
		// Searching itertively over the entire list
		while (temp->next != NULL) {
			index += 1;
			if (temp->next->val == val) {
				return index;
			}
			temp = temp->next;
		}
		return -1;
	}

	// e. delete: Delete an element with a given key from list.
	void deleteVal(T val) {
		if (isListEmpty()) {
			return;
		}

		// Search if the element to be deleted is present in the list or not
		int index = search(val);
		if (index == -1) {
			cout << "Element with key: " << val << " not found in the list" << endl;
			return;
		}
		// If it is the root, delete root
		if (index == 0) {
			deleteFirst();
			return;
		}
		// Else loop till the given index and delete
		Node<T> *temp = root;
		for (int i = 1; i < index; i++) {
			temp = temp->next;
		}
		// Delete the current index node
		cout << "Deleting element with val: " << temp->next->val << " present at index: " << index << endl;
		temp->next = temp->next->next;
		cout << "Deleted" << endl;
	}

	// f. getSize: Display size of linked list.
	int getSize() {
		if (isListEmpty()) {
			return 0;
		}
		Node<T> *temp = root;
		int count = 1;
		while (temp->next != NULL) {
			temp = temp->next;
			count += 1;
		}
		return count;
	}

	// g. insertEnd: Insert an element at end of linkedlist.
	void insertEnd(T val) {
		return insertVal(val, getSize());
	}

	// h. insertVal(val, place): insert element at a given place from beginning in linked list.
	void insertVal(T val, int index) {
		// Case a: List is empty and given index is 0
		if (isListEmpty() && index == 0) {
			return insertFirst(val);
		}
		// Case b: List is empty and given index != 0
		if (isListEmpty() && index != 0) {
			cout << "Cannot insert at index: " << index << endl;
			return;
		}
		// Case c: Given index > list size
		if (index > getSize()) {
			cout << "Index " << index << " bigger than list size " << getSize() << " . Insertion not allowed." << endl;
			return;
		}
		// Case d: Valid case
		Node<T> *temp = root;
		Node<T> *newNode = new Node<T>();
		newNode->val = val;
		newNode->next = NULL;
		for (int i = 1; i < index; i++) {
			temp = temp->next;
		}
		newNode->next = temp->next;
		temp->next = newNode;
		cout << "Node with value: " << val << " inserted at index: " << index << endl;
	}

	// i. deleteEnd: Delete element from end of linked list.
	void deleteEnd() {
		return deleteIndex(getSize() - 1);
	}

	// j. deleteIndex: Delete element at a given index from linked list.
	void deleteIndex(int index) {
		if (isListEmpty()) {
			return;
		}
		if (index == 0) {
			return deleteFirst();
		}
		Node<T> *temp = root;
		for (int i = 1; i < index; i++) {
			temp = temp->next;
		}
		temp->next = temp->next->next;
		cout << "Deleted element from index: " << index << endl;
	}

	// k. reverseIter(): Function to reverse a linked list itertively
	void reverseIter() {
		if (isListEmpty()) {
			return;
		}
		vector<Node<T> *> nodeStack;
		Node<T> *temp = root;
		while (temp->next != NULL) {
			nodeStack.push_back(temp);
			temp = temp->next;
		}
		temp->next = nodeStack.back();
		root = temp;
		nodeStack.pop_back();
		temp = temp->next;
		while (!nodeStack.empty()) {
			temp->next = nodeStack.back();
			nodeStack.pop_back();
			temp = temp->next;
		}
		temp->next = NULL;
		return;
	}

	// l. reverseRec(): Function to reverse a linked list recursively
	void reverseRec() {
		if (isListEmpty()) {
			return;
		}
		Node<T> *temp = root;
		reverseHelperRec(temp);
		temp->next = NULL;
	}

	// m. reverseListTillIndex: Reverse a list till a given index
	void reverseListTillIndex(int endIndex) {
		if (isListEmpty()) {
			return;
		}
		vector<Node<T> *> nodeStack;
		Node<T> *temp = root;
		int i = 0;
		while (i < endIndex) {
			nodeStack.push_back(temp);
			temp = temp->next;
			i++;
		}
		Node<T> *tempEnd = temp->next;
		temp->next = nodeStack.back();
		root = temp;
		nodeStack.pop_back();
		temp = temp->next;
		while (!nodeStack.empty()) {
			temp->next = nodeStack.back();
			nodeStack.pop_back();
			temp = temp->next;
		}
		temp->next = tempEnd;
		return;
	}

	// n. isPalindrome(): Returns true if a linked list is palindromic
	bool isPalindrome() {
		if (isListEmpty()) {
			return 0;
		}
		int listSize = getSize();
		int lastIndex = (listSize - 1) / 2;
		// In case of even number of elements
		if (listSize % 2 == 0) {
			reverseListTillIndex(lastIndex);
		}
		else {
			reverseListTillIndex(lastIndex - 1);
		}
		Node<T> *rightPtr;
		Node<T> *leftPtr;
		leftPtr = root;
		rightPtr = root;
		// Move to the middle
		for (int i = 0; i <= lastIndex; i++) {
			rightPtr = rightPtr->next;
		}
		// Compare elements
		bool isPalin = true;
		while (rightPtr->next != NULL) {
			if (leftPtr->val != rightPtr->val) {
				isPalin = false;
				break;
			}
			leftPtr = leftPtr->next;
			rightPtr = rightPtr->next;
		}
		// Checking last element
		if (leftPtr->val != rightPtr->val) {
			isPalin = false;
		}
		return isPalin;
	}
};

int main() {
	LinkedList<int> list;
	list.insertFirst(70);
	list.insertFirst(90);
	list.insertFirst(20);
	list.insertFirst(50);
	list.insertFirst(40);
	list.insertFirst(100);
	list.deleteFirst();
	list.displayIter();
	list.displayRec();
	int toFind = 100;
	int index = list.search(toFind);
	if (index == -1) {
		cout << "Element not found with val: " << toFind << endl;
	}
	else {
		cout << "Element present at location/index: " << index << endl;
	}
	list.deleteVal(20);
	list.displayRec();
	cout << "Linked list size is: " << list.getSize() << endl;
	list.insertVal(34, 3);
	list.displayRec();
	list.insertVal(77, 3);
	list.displayRec();
	list.insertEnd(98);
	list.displayIter();
	list.deleteIndex(2);
	list.displayIter();
	list.reverseIter();
	list.displayIter();
	list.reverseRec();
	list.displayIter();
	list.reverseListTillIndex(2);
	list.displayIter();

	LinkedList<int> list1;
	list1.insertFirst(70);
	list1.insertFirst(90);
	list1.insertFirst(20);
	list1.insertFirst(20);
	list1.insertFirst(90);
	list1.insertFirst(70);
	
	list1.displayIter();
	cout << "List is Palindrome? : " << list1.isPalindrome() << endl;

	//char		c;
	//cin >> c;
	return 0;
}

// Output
/*
Linked List is empty
New root is: 70
Old root is: 70
New root is: 90
Old root is: 90
New root is: 20
Old root is: 20
New root is: 50
Old root is: 50
New root is: 40
Old root is: 40
New root is: 100
New root after deletion is: 40
40	50	20	90	70	
40	50	20	90	70	
Element not found with val: 100
Deleting element with val: 20 present at index: 2
Deleted
40	50	90	70	
Linked list size is: 4
Node with value: 34 inserted at index: 3
40	50	90	34	70	
Node with value: 77 inserted at index: 3
40	50	90	77	34	70	
Node with value: 98 inserted at index: 6
40	50	90	77	34	70	98	
Deleted element from index: 2
40	50	77	34	70	98	
98	70	34	77	50	40	
40	50	77	34	70	98	
77	50	40	34	70	98	
Linked List is empty
New root is: 70
Old root is: 70
New root is: 90
Old root is: 90
New root is: 20
Old root is: 20
New root is: 20
Old root is: 20
New root is: 90
Old root is: 90
New root is: 70
70	90	20	20	90	70	
List is Palindrome? : 1
*/
