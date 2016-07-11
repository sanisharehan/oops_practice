//
// Homework#11: Implement Queue data structure using the linked list class created with binary
// trees. The time complexities are as mentioned with all the methods.
// The new class should have following functions:
// a. enqueue: O(n) since we need to traverse to the last element and add new. It can be changed to O(1)
// by having an additional pointer pointing to the last node.
// b. dequeue : O(1) since we are removing the root only.
// c. isEmpty: O(1) since we can simply check the root node exists or not.
// d. front: Return the element at first without deleting. O(1)
// e. end: Return the element at end without deleting. O(n) without end pointer
// f. size: O(n)
//

#include <iostream>
#include "BinaryTreeLikeLinkedListWithEnd.cpp"

using namespace std;

// Here is the new way of typedef a class in C++
template <typename T>
using LinkedList<T> = BinaryTreeLikeLinkedListWithEnd<T>;

template <typename T>
class Queue {
private:
	LinkedList<T> list;

public:
	// a. enqueue: To add a new element to the end of the queue
	void enqueue(T val) {
		list.insert(val);
	}

	// b. dequeue: To remove first element of queue
	void dequeue() {
		list.deleteRoot();
	}

	// c. isEmpty: Check if queue is empty or not
	bool isEmpty() {
		if (list.returnRoot() != NULL) {
			return false;
		}
		return true;
	}

	// d. front: Return the element at first without deleting
	T front() {
		if (list.returnRoot() != NULL) {
			return list.returnRoot()->val;
		}
		else {
			return -1;
		}
	}

	// e. end: Return the element at end without deleting
	T end() {
		if (list.returnLastNode() != NULL) {
			return list.returnLastNode()->val;
		}
		else {
			return -1;
		}
	}

	// f. size: Return queue size
	int size() {
		return list.getSize();
	}
};


int main(int argc, char *argv[]) {
	Queue<char> qu;
	cout << "Queue empty? " << qu.isEmpty() << endl;
	qu.enqueue('b');
	qu.enqueue('e');
	qu.enqueue('s');
	qu.enqueue('t');
	qu.enqueue('y');
	cout << "Queue initial size is: " << qu.size() << endl;
	qu.dequeue();
	cout << "First element in queue: " << qu.front() << endl;
	cout << "Last element in queue: " << qu.end() << endl;
	//char c;
	//cin >> c;
	return 0;
}



