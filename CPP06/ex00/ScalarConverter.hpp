#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <iomanip>

class ScalarConverter {
private:
	enum Type {
		CHAR,
		INT,
		FLOAT,
		DOUBLE,
		INVALID
	};

	ScalarConverter();
	ScalarConverter(const ScalarConverter&);
	ScalarConverter& operator=(const ScalarConverter&);
	~ScalarConverter();

	static bool isCharType(const std::string& str);
	static bool isIntType(const std::string& str);
	static bool isFloatType(const std::string& str);
	static bool isDoubleType(const std::string& str);
	static bool isPseudoLiteral(const std::string& str);
	static Type identifyType(const std::string& str);
	static void displayResults(char c, int i, float f, double d);

public:
	static void convert(const std::string& literal);
};

#endif 


