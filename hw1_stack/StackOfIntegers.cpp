#include <vector>
#include <iostream>
#include "StackOfIntegers.h"

using namespace std;

StackOfIntegers::StackOfIntegers(void) {
	cout << "Created a stack of integers" << endl;
}

//Simply push the element at top of stak i.e. end of vector
void StackOfIntegers::Push(int num) {
	myIntStack.push_back(num);
	cout << "Element pushed: " << num << endl;
}

//Return the last element as well as delete it from stack
int StackOfIntegers::Pop() {
	if (myIntStack.empty()) {
		cout << "Empty stack" << endl;
		return -1;
	}
	int lastEle = myIntStack.back();
	myIntStack.pop_back();
	return lastEle;
}

//Return the count of elements in stack
int StackOfIntegers::countOfElements() {
	return myIntStack.size();
}

//To delete all elements from stack
void StackOfIntegers::DeleteAllElements() {
	myIntStack.clear();
	cout << "Stack cleared" << endl;
}

bool StackOfIntegers::isEmpty() {
	return myIntStack.empty();
}

void StackOfIntegers::showStack() {
	if (myIntStack.empty()) {
		cout << "Stack empty" << endl;
	}
	cout << "Stack elements are:";
	for (std::vector<int>::reverse_iterator rit = myIntStack.rbegin(); rit != myIntStack.rend(); ++rit) {
		cout << ' ' << *rit;
	}
	cout << endl;
}
