#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main(void) {
	// Test 1: vector with element found
	std::cout << "=== Test 1: Vector - Element found ===" << std::endl;
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	try {
		std::vector<int>::iterator it = easyfind(vec, 3);
		std::cout << "Found: " << *it << std::endl;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// Test 2: vector with element not found
	std::cout << "\n=== Test 2: Vector - Element not found ===" << std::endl;
	try {
		std::vector<int>::iterator it = easyfind(vec, 10);
		std::cout << "Found: " << *it << std::endl;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// Test 3: list with element found
	std::cout << "\n=== Test 3: List - Element found ===" << std::endl;
	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	lst.push_back(40);
	lst.push_back(50);

	try {
		std::list<int>::iterator it = easyfind(lst, 30);
		std::cout << "Found: " << *it << std::endl;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// Test 4: list with element not found
	std::cout << "\n=== Test 4: List - Element not found ===" << std::endl;
	try {
		std::list<int>::iterator it = easyfind(lst, 100);
		std::cout << "Found: " << *it << std::endl;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// Test 5: deque with first element
	std::cout << "\n=== Test 5: Deque - First element ===" << std::endl;
	std::deque<int> deq;
	deq.push_back(100);
	deq.push_back(200);
	deq.push_back(300);

	try {
		std::deque<int>::iterator it = easyfind(deq, 100);
		std::cout << "Found: " << *it << std::endl;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// Test 6: deque with last element
	std::cout << "\n=== Test 6: Deque - Last element ===" << std::endl;
	try {
		std::deque<int>::iterator it = easyfind(deq, 300);
		std::cout << "Found: " << *it << std::endl;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// Test 7: empty container
	std::cout << "\n=== Test 7: Empty container ===" << std::endl;
	std::vector<int> empty;
	try {
		std::vector<int>::iterator it = easyfind(empty, 1);
		std::cout << "Found: " << *it << std::endl;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// Test 8: container with duplicates (finds first occurrence)
	std::cout << "\n=== Test 8: Container with duplicates ===" << std::endl;
	std::vector<int> dup;
	dup.push_back(5);
	dup.push_back(5);
	dup.push_back(5);
	try {
		std::vector<int>::iterator it = easyfind(dup, 5);
		std::cout << "Found: " << *it << " at position " << std::distance(dup.begin(), it) << std::endl;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== All tests completed ===" << std::endl;
	return 0;
}
