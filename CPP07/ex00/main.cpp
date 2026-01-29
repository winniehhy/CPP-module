#include <iostream>
#include <string>
#include "whatever.hpp"

/*
:: swap 
- tell compiler to use the swap in the global namespace (mine)
- or else , it might confused to use std::swap

*/


int main(void) {
	std::cout << "========== REQUIRED TESTS (FROM PDF) ==========\n";
	{
		int a = 2;
		int b = 3;

		::swap(a, b);
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
		std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

		std::string c = "chaine1";
		std::string d = "chaine2";

		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
		std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
	}

	std::cout << "\n========== TEST 1: Work with ANY type (int, float, double, char, string) ==========\n";
	{
		// INT
		int i1 = 100, i2 = 200;
		std::cout << "INT: min(" << i1 << ", " << i2 << ") = " << ::min(i1, i2) << std::endl;
		std::cout << "INT: max(" << i1 << ", " << i2 << ") = " << ::max(i1, i2) << std::endl;

		// FLOAT
		float f1 = 3.14f, f2 = 2.71f;
		::swap(f1, f2);
		std::cout << "FLOAT after swap: f1 = " << f1 << ", f2 = " << f2 << std::endl;
		std::cout << "FLOAT: min(" << f1 << ", " << f2 << ") = " << ::min(f1, f2) << std::endl;

		// DOUBLE
		double d1 = 99.99, d2 = 100.01;
		std::cout << "DOUBLE: max(" << d1 << ", " << d2 << ") = " << ::max(d1, d2) << std::endl;

		// CHAR
		char c1 = 'z', c2 = 'a';
		::swap(c1, c2);
		std::cout << "CHAR after swap: c1 = " << c1 << ", c2 = " << c2 << std::endl;
		std::cout << "CHAR: min(" << c1 << ", " << c2 << ") = " << ::min(c1, c2) << std::endl;

		// STRING
		std::string s1 = "zebra", s2 = "apple";
		std::cout << "STRING: min(" << s1 << ", " << s2 << ") = " << ::min(s1, s2) << std::endl;

		// LONG
		long l1 = 1000000L, l2 = 2000000L;
		std::cout << "LONG: max(" << l1 << ", " << l2 << ") = " << ::max(l1, l2) << std::endl;

		// UNSIGNED INT
		unsigned int u1 = 50, u2 = 100;
		std::cout << "UNSIGNED INT: min(" << u1 << ", " << u2 << ") = " << ::min(u1, u2) << std::endl;
	}

	std::cout << "\n========== TEST 2: Both arguments with different type ==========\n";
	{
		
		// //These would cause compilation errors (uncomment to test):
		// int x = 5;
		// float y = 3.14f;
		// ::swap(x, y);  // ERROR: cannot deduce T (int vs float)
		// ::min(x, y);   // ERROR: template argument deduction fails
	}

	std::cout << "\n========== TEST 3: Type must support COMPARISON OPERATORS (<, >, ==) ==========\n";
	{
		// Test with types that support <, >, ==
		
		// INT comparison
		int a = 10, b = 20;
		std::cout << "INT: " << a << " < " << b << " → min = " << ::min(a, b) << std::endl;
		std::cout << "INT: " << a << " < " << b << " → max = " << ::max(a, b) << std::endl;

		// FLOAT comparison
		float f1 = 5.5f, f2 = 5.5f;
		std::cout << "FLOAT (equal): min(" << f1 << ", " << f2 << ") = " << ::min(f1, f2) 
		          << " (returns second)" << std::endl;

		// STRING comparison (lexicographic)
		std::string str1 = "abc", str2 = "xyz";
		std::cout << "STRING: '" << str1 << "' < '" << str2 << "' → min = " << ::min(str1, str2) << std::endl;

		// CHAR comparison (ASCII)
		char c1 = 'A', c2 = 'Z';
		std::cout << "CHAR: '" << c1 << "' < '" << c2 << "' → min = " << ::min(c1, c2) << std::endl;

		// Test EQUAL values (should return second parameter)
		int equal1 = 42, equal2 = 42;
		std::cout << "\nEQUAL VALUES TEST: min(" << equal1 << ", " << equal2 << ") = " 
		          << ::min(equal1, equal2) << " (should return second)" << std::endl;
		std::cout << "EQUAL VALUES TEST: max(" << equal1 << ", " << equal2 << ") = " 
		          << ::max(equal1, equal2) << " (should return second)" << std::endl;
	}


	std::cout << "\n========== TEST 4: EDGE CASES ==========\n";
	{
		// Negative numbers
		int neg1 = -5, neg2 = -10;
		std::cout << "NEGATIVE: min(" << neg1 << ", " << neg2 << ") = " << ::min(neg1, neg2) << std::endl;
		std::cout << "NEGATIVE: max(" << neg1 << ", " << neg2 << ") = " << ::max(neg1, neg2) << std::endl;

		// Mixed positive/negative
		int pos = 42, neg = -42;
		std::cout << "MIXED: min(" << pos << ", " << neg << ") = " << ::min(pos, neg) << std::endl;

		// Zero
		int zero1 = 0, zero2 = 5;
		std::cout << "WITH ZERO: min(" << zero1 << ", " << zero2 << ") = " << ::min(zero1, zero2) << std::endl;

		// Very large numbers
		long big1 = 9999999L, big2 = 10000000L;
		std::cout << "LARGE NUMBERS: max(" << big1 << ", " << big2 << ") = " << ::max(big1, big2) << std::endl;

		// Empty strings (valid but unusual)
		std::string empty = "", nonempty = "text";
		std::cout << "EMPTY STRING: min('" << empty << "', '" << nonempty << "') = '" 
		          << ::min(empty, nonempty) << "'" << std::endl;
	}

	std::cout << "\n========== TEST 5: CONST CORRECTNESS ==========\n";
	{
		const int ca = 100;
		const int cb = 50;
		std::cout << "CONST INT: min(" << ca << ", " << cb << ") = " << ::min(ca, cb) << std::endl;
		std::cout << "CONST INT: max(" << ca << ", " << cb << ") = " << ::max(ca, cb) << std::endl;

		// Binding to const reference (verifies return type is const T&)
		const int& ref_min = ::min(ca, cb);
		const int& ref_max = ::max(ca, cb);
		std::cout << "Bound to const ref: min = " << ref_min << ", max = " << ref_max << std::endl;

		const std::string cs1 = "alpha";
		const std::string cs2 = "beta";
		std::cout << "CONST STRING: min = " << ::min(cs1, cs2) << std::endl;
		std::cout << "CONST STRING: min = " << ::min(ca, cb) << std::endl;
	}


	

	return 0;
}


/*
Check
-Templates work with ANY type (int, float, double, char, string, long, etc.)
- Both arguments must be SAME TYPE (enforced by compiler)
- Types must support comparison operators (<, >, ==)
- Templates defined in HEADER FILES (whatever.hpp)
- Equal values return SECOND parameter as specified
- Const correctness maintained (returns const T&)
*/