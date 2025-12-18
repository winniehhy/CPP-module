#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// free functions
Base* generate(void);
void identify(Base* p);
void identify(Base& p);

static void test_pointer(Base* p, const char* label)
{
	std::cout << label << " (ptr): ";
	identify(p);
}

static void test_reference(Base& r, const char* label)
{
	std::cout << label << " (ref): ";
	identify(r);
}

int main()
{
	std::cout << "=== Basic safety test ===" << std::endl;
	identify(static_cast<Base*>(0));

	std::cout << "\n=== Manual instances ===" << std::endl;
	A a;
	B b;
	C c;

	test_pointer(&a, "A");
	test_pointer(&b, "B");
	test_pointer(&c, "C");

	test_reference(a, "A");
	test_reference(b, "B");
	test_reference(c, "C");

	std::cout << "\n=== Random generation loop ===" << std::endl;
	int countA = 0, countB = 0, countC = 0;

	for (int i = 0; i < 10; ++i)
	{
		Base* p = generate();

		std::cout << "run " << i << ": ";
		identify(p);
		identify(*p);

		if (dynamic_cast<A*>(p)) countA++;
		else if (dynamic_cast<B*>(p)) countB++;
		else if (dynamic_cast<C*>(p)) countC++;

		delete p;
	}

	std::cout << "\nGenerated counts -> "
			  << "A=" << countA << " "
			  << "B=" << countB << " "
			  << "C=" << countC << std::endl;

	std::cout << "\n=== Polymorphic delete check ===" << std::endl;
	Base* bptr = new B();
	delete bptr;

	std::cout << "Done." << std::endl;
	return 0;
}
