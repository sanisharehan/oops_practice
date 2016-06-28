#include "StackOfIntegers.cpp"

int main() {
	StackOfIntegers stackInt;
	stackInt.Push(45);
	stackInt.Push(78);
	stackInt.Push(100);
	stackInt.Push(98);
	cout << "Elements in stack are: " << stackInt.countOfElements() << endl;
	stackInt.showStack();
	cout << "Popping last element " << stackInt.Pop() << endl;
	cout << "New size: " << stackInt.countOfElements() << endl;
    stackInt.showStack();
	cout << "Is stack empty? " << stackInt.isEmpty() << endl;
	return 0;
}
