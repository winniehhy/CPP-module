#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <ctime>
#include "easyfind.hpp"

int main(void) {
	// Test 1: vector with element found
	std::cout << "=== Test 1: Vector  ===" << std::endl;
	std::vector<int> vec;
	vec.push_back(13);
	vec.push_back(2);
	vec.push_back(32);
	vec.push_back(43);
	vec.push_back(5);

	try {
		std::vector<int>::iterator it = easyfind(vec, 43);
		std::cout << "Found: " << *it << std::endl;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// Test 2: add & remove vector
	std::cout << "\n=== Test 2: Vector - Add & Remove ===" << std::endl;
	std::cout << "Original vector: ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	// Add element at end
	vec.push_back(99);
	std::cout << "After push_back(99): ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	// Remove last element
	vec.pop_back();
	std::cout << "After pop_back(): ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	// Search for element after modifications
	try {
		std::vector<int>::iterator it = easyfind(vec, 32);
		std::cout << "Found element: " << *it << std::endl;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// Test 3: list 
	std::cout << "\n=== Test 3: List  =========" << std::endl;
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

	// Test 4: list add & remove
	std::cout << "\n=== Test 4: List - Add & Remove ===" << std::endl;
	std::cout << "Original list: ";
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	// Add element at front (list can do this efficiently!)
	lst.push_front(5);
	std::cout << "After push_front(5): ";
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	// Add element at back
	lst.push_back(60);
	std::cout << "After push_back(60): ";
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	// Remove front and back
	lst.pop_front();
	lst.pop_back();
	std::cout << "After pop_front() & pop_back(): ";
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	// Search for element after modifications
	try {
		std::list<int>::iterator it = easyfind(lst, 30);
		std::cout << "Found element: " << *it << std::endl;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// Test 5: deque with first element
	std::cout << "\n=== Test 5: Deque - Add & Remove ===" << std::endl;
	std::deque<int> deq;
	deq.push_back(100);
	deq.push_back(200);
	deq.push_back(300);

	std::cout << "Original deque: ";
	for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	// Add element at front (deque can do this efficiently like list!)
	deq.push_front(50);
	std::cout << "After push_front(50): ";
	for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	// Add element at back
	deq.push_back(400);
	std::cout << "After push_back(400): ";
	for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	// Remove front and back (deque can do both efficiently!)
	deq.pop_front();
	deq.pop_back();
	std::cout << "After pop_front() & pop_back(): ";
	for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	// Search for element
	try {
		std::deque<int>::iterator it = easyfind(deq, 200);
		std::cout << "Found element: " << *it << std::endl;
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

	// Test 9: String test - finding character
	std::cout << "\n=== Test 9: String/Character test ===" << std::endl;
	std::string str = "Welcome to 42";
	std::vector<char> charVec(str.begin(), str.end());
	
	std::cout << "String: \"" << str << "\"" << std::endl;
	std::cout << "Searching for 'W'..." << std::endl;
	try {
		std::vector<char>::iterator it = easyfind(charVec, 'W');
		std::cout << "Found: '" << *it << "' at position " << std::distance(charVec.begin(), it) << std::endl;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}


	// Test 11: Time complexity comparison - Insert at front
	// std::cout << "\n=== Test 10: Time Complexity - Insert at Front ===" << std::endl;
	// const int NUM_INSERTS = 10000;
	
	// // Vector insert at front (slow - O(n) for each insert)
	// std::vector<int> timeVec;
	// clock_t startVec = clock();
	// for (int i = 0; i < NUM_INSERTS; ++i) {
	// 	timeVec.insert(timeVec.begin(), i);  // Insert at front
	// }
	// clock_t endVec = clock();
	// double vecTime = double(endVec - startVec) / CLOCKS_PER_SEC * 1000;
	
	// // List insert at front (fast - O(1) for each insert)
	// std::list<int> timeLst;
	// clock_t startLst = clock();
	// for (int i = 0; i < NUM_INSERTS; ++i) {
	// 	timeLst.push_front(i);  // Insert at front
	// }
	// clock_t endLst = clock();
	// double lstTime = double(endLst - startLst) / CLOCKS_PER_SEC * 1000;
	
	// std::cout << "Inserting " << NUM_INSERTS << " elements at FRONT:" << std::endl;
	// std::cout << "Vector time: " << vecTime << " ms (O(n) per insert = O(n²) total)" << std::endl;
	// std::cout << "List time:   " << lstTime << " ms (O(1) per insert = O(n) total)" << std::endl;
	// std::cout << "Vector is " << (vecTime / lstTime) << "x slower!" << std::endl;

	// std::cout << "\n=== All tests completed ===" << std::endl;
	// return 0;
}
