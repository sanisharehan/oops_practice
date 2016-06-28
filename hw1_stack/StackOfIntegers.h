#include <vector>

//Defining the class prototype here
class StackOfIntegers {
private:
	std::vector<int> myIntStack;
public:
	//class constructor has same name as that of a class, no return and no input
	StackOfIntegers(void);
	void Push(int num);
	int Pop();
	int countOfElements();
	void DeleteAllElements();
	bool isEmpty();
	void showStack();
};
