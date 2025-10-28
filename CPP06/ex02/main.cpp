#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// declare free functions defined in identify.cpp
Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main() {
	// Case 1: NULL pointer
	std::cout << "[1] identify(NULL): ";
	Base* np = 0;
	identify(np);

	// Case 2: Explicit objects via pointer
	std::cout << "\n[2] Explicit (pointer)" << std::endl;
	A a; B b; C c;
	std::cout << "  A*: "; identify(&a);
	std::cout << "  B*: "; identify(&b);
	std::cout << "  C*: "; identify(&c);

	// Case 3: Explicit objects via reference
	std::cout << "\n[3] Explicit (reference)" << std::endl;
	std::cout << "  A&: "; identify(a);
	std::cout << "  B&: "; identify(b);
	std::cout << "  C&: "; identify(c);

	// Case 4: Random generate several times; ensure we see A/B/C
	std::cout << "\n[4] Random 12x (ptr + ref)" << std::endl;
	bool seenA = false, seenB = false, seenC = false;
	for (int i = 0; i < 12; ++i) {
		Base* p = generate();
		std::cout << "  #" << (i + 1) << " ptr: "; identify(p);
		std::cout << "     ref: "; identify(*p);
		if (dynamic_cast<A*>(p)) seenA = true;
		else if (dynamic_cast<B*>(p)) seenB = true;
		else if (dynamic_cast<C*>(p)) seenC = true;
		delete p;
	}
	std::cout << "  seen -> A:" << (seenA ? "yes" : "no")
			  << " B:" << (seenB ? "yes" : "no")
			  << " C:" << (seenC ? "yes" : "no") << std::endl;

	// Case 5: Delete via Base*
	std::cout << "\n[5] Delete through Base*: ";
	Base* poly = new A();
	delete poly;
	std::cout << "ok" << std::endl;

	return 0;
}


