#include <iostream>
#include <cstdlib>
#include <ctime>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void) {
	static bool seeded = false;
	if (!seeded) { std::srand(static_cast<unsigned int>(std::time(0))); seeded = true; }
	int r = std::rand() % 3;
	if (r == 0) return new A();
	if (r == 1) return new B();
	return new C();
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p)) { std::cout << "A" << std::endl; return; }
	if (dynamic_cast<B*>(p)) { std::cout << "B" << std::endl; return; }
	if (dynamic_cast<C*>(p)) { std::cout << "C" << std::endl; return; }
	std::cout << "Unknown" << std::endl;
}

void identify(Base& p) {
	try { (void)dynamic_cast<A&>(p); std::cout << "A" << std::endl; return; } catch (...) {}
	try { (void)dynamic_cast<B&>(p); std::cout << "B" << std::endl; return; } catch (...) {}
	try { (void)dynamic_cast<C&>(p); std::cout << "C" << std::endl; return; } catch (...) {}
	std::cout << "Unknown" << std::endl;
}


