// Hw#2: Accepted answer:
// LeetCode(20): Given a string containing just the characters 
//'(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// The brackets must close in the correct order, 
// "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

#include <iostream>
#include <vector>
#include <string.h>
#include <map>

using namespace std;
bool isValid(string ipString);

// Global variable declaration
map<char, char> fixed_map;

int main(int argc, char *argv[]) {
	string input = "({[()()]})))";
	// Defining a fixed map to check for correctness of input string
	fixed_map['('] = ')';
	fixed_map['['] = ']';
	fixed_map['{'] = '}';

	if (isValid(input)) {
		cout << "Valid string entered " << input << endl;
	}
	else {
		cout << "Invalid string entered " << input << endl;
	}
	return 0;
}

// The main logic begins to compare
bool isValid(string ipString) {
	vector<char> stack;
	// In case of odd number of paranthesis, return false always
	if (ipString.size() % 2 != 0) {
		return false;
	}
	int index = 0;
	while (index <= (ipString.size() - 1)) {
		char currChar = ipString[index];
		if (fixed_map.find(currChar) != fixed_map.end()) {
			// It means key is present in map
			stack.push_back(currChar);
		}
		else {	
			if (stack.empty()) {
				return false;
			}
			// Get the last stack value and match the existing paranthesis with key
			char lastStackEle = stack.back();
			if (currChar != fixed_map.find(lastStackEle)->second) {
				return false;
			}
			stack.pop_back();
		}
		index += 1;
	}
	if (!stack.empty()) {
		return false;
	}
	return true;
}
