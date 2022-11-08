/*
	Example of value vs. reference parameters.
*/
#include <iostream>
#include <string>

using namespace std;

// Doesn't change actual parameters when
//  the formal parameters are changed.
void valueParams(int a, int b) {
	a = 0;
	b = 1;
	cout << "a inside valueParams(): " << a << endl;
	cout << "b inside valueParams(): " << b << endl;
}

// Changes actual parameters when the
//  formal parameters are changed.
void referenceParams(int &a, int &b) {
	a = 100;
	b = 9999;
	cout << "a inside referenceParams(): " << a << endl;
	cout << "b inside referenceParams(): " << b << endl;
}


int main(int argc, char const *argv[]) {
	int a = 10, b = 25;
	
	// Print values before being passed as parameters
	cout << "a before function: " << a << endl;
	cout << "b before function: " << b << endl;

	valueParams(a, b);

	// Print values after being value parameters
	cout << "a after valueParams(): " << a << endl;
	cout << "b after valueParams(): " << b << endl;

	referenceParams(a, b);

	// Print values after being reference parameters
	cout << "a after referenceParams(): " << a << endl;
	cout << "b after referenceParams(): " << b << endl;

	return 0;
}
