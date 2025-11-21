#include <iostream>
#include <string>
#include "iter.hpp"

// Test function templates
template <typename T>
void printElement(T const & x) {
	std::cout << x << " ";
}

template <typename T>
void increment(T & x) {
	x++;
}

void toUpper(char & c) {
	if (c >= 'a' && c <= 'z') {
		c = c - 'a' + 'A';
	}
}

int main(void) {
	// Test 1: int array with print function
	std::cout << "Test 1: Print int array" << std::endl;
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intLen = sizeof(intArray) / sizeof(intArray[0]);
	::iter(intArray, intLen, printElement<int>);
	std::cout << std::endl;

	// Test 2: int array with increment function
	std::cout << "\nTest 2: Increment int array" << std::endl;
	::iter(intArray, intLen, increment<int>);
	::iter(intArray, intLen, printElement<int>);
	std::cout << std::endl;

	// Test 3: double array
	std::cout << "\nTest 3: Print double array" << std::endl;
	double doubleArray[] = {1.1, 2.2, 3.3, 4.4};
	size_t doubleLen = sizeof(doubleArray) / sizeof(doubleArray[0]);
	::iter(doubleArray, doubleLen, printElement<double>);
	std::cout << std::endl;

	// Test 4: string array
	std::cout << "\nTest 4: Print string array" << std::endl;
	std::string strArray[] = {"Hello", "World", "Templates", "Rock"};
	size_t strLen = sizeof(strArray) / sizeof(strArray[0]);
	::iter(strArray, strLen, printElement<std::string>);
	std::cout << std::endl;

	// Test 5: char array with custom function
	std::cout << "\nTest 5: Convert char array to uppercase" << std::endl;
	char charArray[] = {'h', 'e', 'l', 'l', 'o'};
	size_t charLen = sizeof(charArray) / sizeof(charArray[0]);
	std::cout << "Before: ";
	::iter(charArray, charLen, printElement<char>);
	std::cout << std::endl;
	::iter(charArray, charLen, toUpper);
	std::cout << "After:  ";
	::iter(charArray, charLen, printElement<char>);
	std::cout << std::endl;

	return 0;
}
