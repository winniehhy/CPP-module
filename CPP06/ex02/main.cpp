#include <iostream>
#include <exception>
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
	if (!p)
		std::cout << "null" << std::endl;
	else
		identify(p);
}

static void test_reference(Base& r, const char* label)
{
	std::cout << label << " (ref): ";
	identify(r);
}

int main()
{
	std::cout << "=== Manual instances ===" << std::endl;

	A a;
	B b;
	C c;

	test_pointer(&a, "A");
	test_pointer(&b, "B");
	test_pointer(&c, "C");

	test_reference(a, "A");
	test_reference(b, "B");
	test_reference(c, "C");

	// ------------------------------------------------

	std::cout << "\n=== Invalid cast test: B pretending to be A ===" << std::endl;

	Base* baseFromB = new B();

	std::cout << "dynamic_cast<A*>(Base* -> B): ";
	if (dynamic_cast<A*>(baseFromB))
		std::cout << "Cast succeeded (WRONG)" << std::endl;
	else
		std::cout << "nullptr (correct)" << std::endl;

	std::cout << "dynamic_cast<A&>(Base& -> B): ";
	try {
		A& aref = dynamic_cast<A&>(*baseFromB);
		(void)aref;
		std::cout << "Cast succeeded (WRONG)" << std::endl;
	} catch (const std::exception&) {
		std::cout << "exception thrown (correct)" << std::endl;
	}

	delete baseFromB;


	// ------------------------------------------------

	std::cout << "\n=== Random generation loop ===" << std::endl;

	for (int i = 0; i < 10; ++i)
	{
		Base* p = generate();
		std::cout << "run " << i << ": ";
		identify(p);
		identify(*p);
		delete p;
	}

	// ------------------------------------------------

	std::cout << "\n=== Polymorphic delete check ===" << std::endl;
	Base* bp = new B();
	delete bp;

	std::cout << "Done." << std::endl;
	return 0;
}
