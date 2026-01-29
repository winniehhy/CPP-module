#include <iostream>
#include <string>
#include "Array.hpp"

int main(void) {
	// Test 1: Default constructor (empty array)
	std::cout << "=== Test 1: Default constructor ===" << std::endl;
	Array<int> emptyArray;
	std::cout << "Size of empty array: " << emptyArray.size() << std::endl;

	// Test 2: Parametric constructor
	std::cout << "\n=== Test 2: Parametric constructor ===" << std::endl;
	Array<int> intArray(5);
	std::cout << "Size of int array: " << intArray.size() << std::endl;
	std::cout << "Default values: ";
	for (unsigned int i = 0; i < intArray.size(); i++) {
		std::cout << intArray[i] << " ";
	}
	std::cout << std::endl;

	// Test 3: Modify elements
	std::cout << "\n=== Test 3: Modify elements ===" << std::endl;
	for (unsigned int i = 0; i < intArray.size(); i++) {
		intArray[i] = (i + 1) * 10;
	}
	std::cout << "Modified values: ";
	for (unsigned int i = 0; i < intArray.size(); i++) {
		std::cout << intArray[i] << " ";
	}
	std::cout << std::endl;

	// Test 4: Copy constructor
	std::cout << "\n=== Test 4: Copy constructor ===" << std::endl;
	Array<int> copyArray(intArray);
	std::cout << "Copy array values: ";
	for (unsigned int i = 0; i < copyArray.size(); i++) {
		std::cout << copyArray[i] << " ";
	}
	std::cout << std::endl;

	// Test 5: Deep copy verification
	std::cout << "\n=== Test 5: Deep copy verification ===" << std::endl;
	copyArray[0] = 999;
	std::cout << "After modifying copy[0] to 999:" << std::endl;
	std::cout << "Original[0]: " << intArray[0] << std::endl;
	std::cout << "Copy[0]: " << copyArray[0] << std::endl;

	// Test 6: Assignment operator
	std::cout << "\n=== Test 6: Assignment operator ===" << std::endl;
	Array<int> assignArray(3);
	assignArray = intArray; // can test self assignment too
	std::cout << "Assigned array values: ";
	for (unsigned int i = 0; i < assignArray.size(); i++) {
		std::cout << assignArray[i] << " ";
	}
	std::cout << std::endl;

	// Test 7: Out of bounds exception
	std::cout << "\n=== Test 7: Out of bounds exception ===" << std::endl;
	try {
		std::cout << "Trying to access index 100..." << std::endl;
		std::cout << intArray[100] << std::endl;
	} catch (std::exception & e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	// Test 8: String array (complex type)
	std::cout << "\n=== Test 8: String array (complex type) ===" << std::endl;
	Array<std::string> strArray(3);
	strArray[0] = "Hello";
	strArray[1] = "World";
	strArray[2] = "Templates";
	std::cout << "String array: ";
	for (unsigned int i = 0; i < strArray.size(); i++) {
		std::cout << strArray[i] << " ";
	}
	std::cout << std::endl;

	// Test 9: Double array (simple type)
	std::cout << "\n=== Test 9: Double array (simple type) ===" << std::endl;
	Array<double> doubleArray(4);
	for (unsigned int i = 0; i < doubleArray.size(); i++) {
		doubleArray[i] = (i + 1) * 1.5;
	}
	std::cout << "Double array: ";
	for (unsigned int i = 0; i < doubleArray.size(); i++) {
		std::cout << doubleArray[i] << " ";
	}
	std::cout << std::endl;

	// Test 10: Empty array access
	std::cout << "\n=== Test 10: Empty array access ===" << std::endl;
	try {
		std::cout << "Trying to access empty array[0]..." << std::endl;
		std::cout << emptyArray[0] << std::endl;
	} catch (std::exception & e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	// cript operatopr: Const array (read-only)
	std::cout << "\n=== Test 11: Const array (read-only) ===" << std::endl;
	const Array<int> constArray(intArray);
	std::cout << "Const array[0] (read): " << constArray[0] << std::endl;
	std::cout << "Const array[2] (read): " << constArray[2] << std::endl;
	std::cout << "Const array size: " << constArray.size() << std::endl;
	// The following line will cause a compile-time error:
	//constArray[0] = 999;  //  Error: cannot modify const

	


	return 0;
}