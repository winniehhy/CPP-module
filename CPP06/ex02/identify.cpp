#include <iostream>
#include <cstdlib>
#include <ctime>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// Randomly generates and returns a pointer to a new instance of A, B, or C
Base* generate(void) {
	static bool seeded = false; // Ensures seed the random generator only once
	if (!seeded) {
		std::srand(static_cast<unsigned int>(std::time(0)));
		seeded = true;
	}
	int r = std::rand() % 3;
	if (r == 0) {
		return new A();
	} else if (r == 1) {
		return new B();
	} else {
		return new C();
	}
}

// Identifies the actual derived type (A, B, or C) of the object pointed to by Base* p using dynamic_cast
// p is a pointer to Base
void identify(Base* p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "A" << std::endl;
		return;
	}
	if (dynamic_cast<B*>(p)) {
		std::cout << "B" << std::endl;
		return;
	}
	if (dynamic_cast<C*>(p)) {
		std::cout << "C" << std::endl;
		return;
	}
	std::cout << "Unknown" << std::endl;
}

// Identifies the actual derived type (A, B, or C) of the object referenced by Base& p using dynamic_cast and exception handling
void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	} catch (const std::exception& e) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	} catch (const std::exception& e) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	} catch (const std::exception& e) {}
	std::cout << "Unknown" << std::endl;
}


