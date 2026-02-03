#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main(void) {
	// Test from subject
	std::cout << "=== Test from subject (MutantStack) ===" << std::endl;
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;

		mstack.pop();

		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);

		// it = bottom of stack ( first element pushed )
		// ite = top of stack ( last element pushed )

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it; // Move forward one position
		--it; // Move backward one position
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	// Same test with std::list for comparison
	std::cout << "\n=== Test from subject (std::list) ===" << std::endl;
	{
		std::list<int> mstack;

		mstack.push_back(5);
		mstack.push_back(17);

		std::cout << mstack.back() << std::endl;

		mstack.pop_back();

		std::cout << mstack.size() << std::endl;

		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(0);

		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(mstack);
	}

	// Additional tests
	std::cout << "\n=== Test 1: Empty stack ===" << std::endl;
	{
		MutantStack<int> mstack;
		std::cout << "Size: " << mstack.size() << std::endl;
		std::cout << "Empty: " << (mstack.empty() ? "yes" : "no") << std::endl;
	}

	std::cout << "\n=== Test 2: String stack ===" << std::endl;
	{
		MutantStack<std::string> mstack;
		mstack.push("Hello");
		mstack.push("World");
		mstack.push("MutantStack");

		std::cout << "Iterating through strings:" << std::endl;
		for (MutantStack<std::string>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
			std::cout << *it << std::endl;
		}
	}

	std::cout << "\n=== Test 3: Reverse iterators ===" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(1);
		mstack.push(2);
		mstack.push(3);
		mstack.push(4);
		mstack.push(5);

		std::cout << "Forward iteration: ";
		for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;

		std::cout << "Reverse iteration: ";
		for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}

	// std::cout << "\n=== Test 4: Copy constructor ===" << std::endl;
	// {
	// 	MutantStack<int> mstack1;
	// 	mstack1.push(10);
	// 	mstack1.push(20);
	// 	mstack1.push(30);

	// 	MutantStack<int> mstack2(mstack1);
	// 	mstack2.push(40);

	// 	std::cout << "mstack1 size: " << mstack1.size() << std::endl;
	// 	std::cout << "mstack2 size: " << mstack2.size() << std::endl;

	// 	std::cout << "mstack1: ";
	// 	for (MutantStack<int>::iterator it = mstack1.begin(); it != mstack1.end(); ++it) {
	// 		std::cout << *it << " ";
	// 	}
	// 	std::cout << std::endl;

	// 	std::cout << "mstack2: ";
	// 	for (MutantStack<int>::iterator it = mstack2.begin(); it != mstack2.end(); ++it) {
	// 		std::cout << *it << " ";
	// 	}
	// 	std::cout << std::endl;
	// }

	// std::cout << "\n=== Test 5: Assignment operator ===" << std::endl;
	// {
	// 	MutantStack<int> mstack1;
	// 	mstack1.push(100);
	// 	mstack1.push(200);

	// 	MutantStack<int> mstack2;
	// 	mstack2.push(1);

	// 	mstack2 = mstack1;

	// 	std::cout << "mstack2 after assignment: ";
	// 	for (MutantStack<int>::iterator it = mstack2.begin(); it != mstack2.end(); ++it) {
	// 		std::cout << *it << " ";
	// 	}
	// 	std::cout << std::endl;
	// }

	std::cout << "\n=== Test 6: Modifying through iterators (iterator) ===" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(1);
		mstack.push(2);
		mstack.push(3);

		std::cout << "Before: ";
		for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;

		// Multiply each element by 10
		for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
			*it *= 10;
		}

		std::cout << "After:  ";
		for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "\n=== Test 7: Converting to std::stack ===" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(42);
		mstack.push(21);
		mstack.push(84);

		std::stack<int> s(mstack);
		std::cout << "std::stack size: " << s.size() << std::endl;
		std::cout << "std::stack top: " << s.top() << std::endl;
	}

	
	// Test 9: const_iterator (forward, read-only)
	std::cout << "\n=== Test 9: const_iterator (forward, read-only) ===" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(100);
		mstack.push(200);
		mstack.push(300);

		const MutantStack<int>& const_stack = mstack;
		
		std::cout << "Using const_iterator to iterate forward: ";
		for (MutantStack<int>::const_iterator it = const_stack.begin(); it != const_stack.end(); ++it) {
			std::cout << *it << " ";
			//*it = 999;  // Error: cannot modify through const_iterator
		}
		std::cout << std::endl;
		std::cout << "Note: Cannot modify values through const_iterator (read-only)" << std::endl;
	}

	// Test 10: reverse_iterator (backward, modifiable)
	std::cout << "\n=== Test 10: reverse_iterator (backward, can modify) ===" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(1);
		mstack.push(2);
		mstack.push(3);
		mstack.push(4);

		std::cout << "Using reverse_iterator to iterate backward: ";
		for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;

		std::cout << "Multiplying values by 10 using reverse_iterator..." << std::endl;
		for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it) {
			*it *= 10;  // Can modify
		}

		std::cout << "After modification (forward view): ";
		for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}

	// Test 11: const_reverse_iterator (backward, read-only)
	std::cout << "\n=== Test 11: const_reverse_iterator (backward, read-only) ===" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(50);
		mstack.push(40);
		mstack.push(30);
		mstack.push(20);
		mstack.push(10);

		const MutantStack<int>& const_stack = mstack;
		
		std::cout << "Using const_reverse_iterator to iterate backward: ";
		for (MutantStack<int>::const_reverse_iterator it = const_stack.rbegin(); it != const_stack.rend(); ++it) {
			std::cout << *it << " ";
			// *it = 999;  // ❌ Error: cannot modify through const_reverse_iterator
		}
		std::cout << std::endl;
		std::cout << "Note: Cannot modify values through const_reverse_iterator (read-only)" << std::endl;
	}

	return 0;
}
