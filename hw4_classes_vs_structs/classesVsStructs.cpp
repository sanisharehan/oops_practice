// Homework#4: Difference between structs and classes in c++
// These days with new C++11 and others, there is not much difference left between structs and classes.
// Structs can also have their functions, they can be inherited and can have access specifiers as well.
// Below points are the main points of differences between structs and classes.
// Structs vs Classes:
// 1. All members of a struct are PUBLIC by default. All members in a class are PRIVATE by default.
// 2. When a struct is derived from a base class/struct, the default access specifier is PUBLIC. whereas,
// for a derived class, the default access specifier is PRIVATE.

#include <iostream>
using namespace std;

// Point 1
struct tree_s {
	int x;			// public by default
};

class tree_c {
	int x;			// private by default
};

// Point 2
class base_class {
public:
	int y;
};

struct base_struct {
	int y;
};

class derived_class :base_class {
public:
	int z;
};

struct derived_struct :base_class {
	int a;
};

int main() {
	tree_s ts;
	tree_c tc;
	ts.x = 30;		// No error in accessing this
	cout << "The struct x value is: " << ts.x << endl;
	// tc.x = 40;	// Error

	derived_struct ds;
	ds.y = 80;	// We can access both a and y here due to default PUBLIC
	ds.a = 100;

	derived_class dc;  // if we write derived_class *dc =  new derived_class() This creates an object on heap, else on stack
	//dc.y = 89;   // Gives error inaccessible, since access to base class is private here
	dc.z = 78;

	tree_s *tf = new tree_s(); // This creates object on heap and hence any pointer in the class needs 
							  // to be destroyed in the destructor.
	tree_c *tg = new tree_c();

	char c;
	cin >> c;
	return 0;
}
