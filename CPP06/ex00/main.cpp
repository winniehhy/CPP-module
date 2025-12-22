#include "ScalarConverter.hpp"

//static_cast = compile time cast
// Casting - Only changes how the pointer/reference is viewed

int main(int ac, char** av) {
	if (ac == 2) {
		ScalarConverter::convert(av[1]);
		return 0;
	}

	
	const char* tests[] = {
		"0",
		"+0",
		"-0",
		"nan",
		"nanf",
		"42.0f",
		"0.0",
		"0.0f",
		"a",
		"A",
		"~",
		"-42",
		"+42",
		"-4.2f",
		"4.2",
		"42.",
		".5",
		"+inf",
		"-inf",
		"inf",
		"+inff",
		"-inff",
		"inff",
		"2147483647",
		"2147483648",
		"127",
		"128",
		"abc",
		"4.2ff",
		"--1",
		"",
		0
	};

	for (int i = 0; tests[i] != 0; ++i) {
		std::cout << "===== input: " << tests[i] << " =====" << std::endl;
		ScalarConverter::convert(tests[i]);
		std::cout << std::endl;
	}

	return 0;
}

// Check all handle
// - ASCII table ( 32 - 127) 
// - character input ( 'a', 'A' -- different)
// - decimal with f  & without f
// - negative values ( -42, -42.0f)
// - +inf, -inf, +inff, -inff
// - INT MAX, INT_MAX + 1 
// - empty string


// INT MAX = 2147483647
// INT MIN = -2147483648
// FLT MAX = 3.40282e+38
// FLT MIN = 1.17549e-38
// DBL MAX = 1.79769e+308
// DBL MIN = 2.22507e-308

/*
Values less than FLT_MIN and DBL_MIN should NOT show 'impossible', because according to the IEEE 754 floating-point standard, these values can still be represented as denormalized (subnormal) numbers,
 which gradually lose precision as they approach zero. Only when a value overflows to infinity (exceeds FLT_MAX or DBL_MAX) should it be considered 'impossible' to represent in that type
*/
