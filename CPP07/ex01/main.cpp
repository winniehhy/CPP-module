#include <iostream>
#include <string>
#include "iter.hpp"

// ============ Test function templates ============
template <typename T>
void printOutput(T const & x) {
	std::cout << x << " ";
}

template <typename T>
void increment(T & x) {
	x++;
}

// ============ Simple print function (like eval sheet) ============
template <typename T>
void print(T const & x) {
	std::cout << x << std::endl;
}

void toUpper(char & c) {
	if (c >= 'a' && c <= 'z') {
		c = c - 'a' + 'A';
	}
}

// ============ Custom class ============================
class number {
public:
	number(void) : _n(42) {} // set _n = 42 by default
	number(int n) : _n(n) {} // parameterized constructor
	int get() const { return _n; }
private:
	int _n;
};


/*
std::ostream & o is the output stream (like std::cout).
number const & rhs is the number object you want to print (rhs = right-hand side).
*/

std::ostream & operator<<(std::ostream & o, number const & rhs) {
	o << rhs.get();
	return o;
}

int main(void) {
	std::cout << "========== EVAL SHEET TEST (REQUIRED) ==========\n";
	{
		int tab[] = { 0, 1, 2, 3, 4 };
		number tab2[5];

		std::cout << "Int array:" << std::endl;
		::iter(tab, 5, print<int>);
		
		std::cout << "\nnumber array:" << std::endl;
		::iter(tab2, 5, print<number>);
	}

	std::cout << "\n========== ADDITIONAL TESTS ==========\n";
	
	// Test 1: int array with print function
	std::cout << "\nTest 1: Print int array " << std::endl;
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intLen = sizeof(intArray) / sizeof(intArray[0]); // to calculate number of elements
	::iter(intArray, intLen, printOutput<int>);
	std::cout << std::endl;

	// Test 2: int array with increment function
	std::cout << "\nTest 2: Increment int array" << std::endl;
	std::cout << "Before: ";
	::iter(intArray, intLen, printOutput<int>);
	std::cout << std::endl;
	::iter(intArray, intLen, increment<int>);
	std::cout << "After:  ";
	::iter(intArray, intLen, printOutput<int>);
	std::cout << std::endl;

	// Test 3: double array
	std::cout << "\nTest 3: Print double array" << std::endl;
	double doubleArray[] = {1.1, 2.2, 3.3, 4.4};
	size_t doubleLen = sizeof(doubleArray) / sizeof(doubleArray[0]);
	::iter(doubleArray, doubleLen, printOutput<double>);
	std::cout << std::endl;

	// Test 4: string array
	std::cout << "\nTest 4: Print string array" << std::endl;
	std::string strArray[] = {"Hello", "World", "Templates", "Rock"};
	size_t strLen = sizeof(strArray) / sizeof(strArray[0]);
	::iter(strArray, strLen, printOutput<std::string>);
	std::cout << std::endl;

	// Test 5: char array with custom function
	std::cout << "\nTest 5: Convert char array to uppercase" << std::endl;
	char charArray[] = {'h', 'e', 'l', 'l', 'o'};
	size_t charLen = sizeof(charArray) / sizeof(charArray[0]);
	std::cout << "Before: ";
	::iter(charArray, charLen, printOutput<char>);
	std::cout << std::endl;
	::iter(charArray, charLen, toUpper);
	std::cout << "After:  ";
	::iter(charArray, charLen, printOutput<char>);
	std::cout << std::endl;

	// Test 6: const array
	std::cout << "\nTest 6: Const array (read-only)" << std::endl;
	const int constArray[] = {10, 20, 30}; // ut int arr[] = {1, 2, 3}; can be changed.
	::iter(constArray, 3, printOutput<int>);
	std::cout << std::endl;

	// Test 7: Empty behavior (length 0)
	std::cout << "\nTest 7: Array with length 0" << std::endl;
	int emptyArray[] = {1, 2, 3};
	::iter(emptyArray, 0, printOutput<int>);
	std::cout << "(nothing should print above)" << std::endl;

	// Test 8: Single element
	std::cout << "\nTest 8: Single element array" << std::endl;
	int single[] = {999};
	::iter(single, 1, printOutput<int>);
	std::cout << std::endl;

	return 0;
}