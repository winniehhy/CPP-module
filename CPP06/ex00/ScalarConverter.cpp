#include "ScalarConverter.hpp"
#include <cfloat>

// OCF
ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

// Type checking functions
bool ScalarConverter::isCharType(const std::string& str) {
	// Handle char literals in format: 'c' 
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		return std::isprint(str[1]);
	// return false  for control characters ( tabls, newlines,etc)
	return (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]));
}

bool ScalarConverter::isPseudoLiteral(const std::string& str) {
	return (str == "nan" || str == "nanf" || 
			str == "+inf" || str == "-inf" || str == "inf" ||
			str == "+inff" || str == "-inff" || str == "inff");
}

bool ScalarConverter::isIntType(const std::string& str) {
	size_t i = 0;
	
	// Skip sign if present
	if (!str.empty() && (str[0] == '+' || str[0] == '-'))
		i = 1;
	
	// Must have at least one digit after sign
	if (i >= str.length())
		return false;
	
	// Check all remaining characters are digits
	for (; i < str.length(); i++) {
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

bool ScalarConverter::isFloatType(const std::string& str) {
	// Must end with 'f' and have at least 2 characters
	if (str.length() < 2 || str[str.length() - 1] != 'f')
		return false;
	
	size_t i = 0;
	bool hasDot = false;
	bool hasE = false;
	
	// Skip sign
	if (str[0] == '+' || str[0] == '-')
		i = 1;
	
	// Check digits, decimal point, and scientific notation
	for (; i < str.length() - 1; i++) {
		if (str[i] == '.' && !hasDot && !hasE) {
			hasDot = true;
		} else if ((str[i] == 'e' || str[i] == 'E') && !hasE && i > 0) {
			hasE = true;
			// Check for optional sign after 'e'
			if (i + 1 < str.length() - 1 && (str[i + 1] == '+' || str[i + 1] == '-'))
				i++;
		} else if (!std::isdigit(str[i])) {
			return false;
		}
	}
	return hasDot || hasE;
}

bool ScalarConverter::isDoubleType(const std::string& str) {
	size_t i = 0;
	bool hasDot = false;
	bool hasE = false;
	
	// Skip sign
	if (!str.empty() && (str[0] == '+' || str[0] == '-'))
		i = 1;
	
	if (i >= str.length())
		return false;
	
	// Check digits, decimal point, and scientific notation
	for (; i < str.length(); i++) {
		if (str[i] == '.' && !hasDot && !hasE) {
			hasDot = true;
		} else if ((str[i] == 'e' || str[i] == 'E') && !hasE && i > 0) {
			hasE = true;
			// Check for optional sign after 'e'
			if (i + 1 < str.length() && (str[i + 1] == '+' || str[i + 1] == '-'))
				i++;
		} else if (!std::isdigit(str[i])) {
			return false;
		}
	}
	return hasDot || hasE;
}

// Identify the type of literal
ScalarConverter::Type ScalarConverter::identifyType(const std::string& str) {
	if (str.empty() || str[0] == '.')
		return INVALID;
	
	if (isPseudoLiteral(str)) {
		if (str[str.length() - 1] == 'f')
			return FLOAT;
		return DOUBLE;
	}
	
	if (isCharType(str))
		return CHAR;
	
	if (isFloatType(str))
		return FLOAT;
	
	if (isDoubleType(str))
		return DOUBLE;
	
	if (isIntType(str))
		return INT;
	
	return INVALID;
}

// Display all conversion results
void ScalarConverter::displayResults(char c, int i, float f, double d) {
	// Print char
	std::cout << "char: ";
	if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
		std::cout << "impossible\n";
	else if (!std::isprint(static_cast<unsigned char>(c)))
		std::cout << "Non displayable\n";
	else
		std::cout << "'" << c << "'\n";
	
	// Print int
	std::cout << "int: ";
	if (std::isnan(d) || std::isinf(d) || d > INT_MAX || d < INT_MIN)
		std::cout << "impossible\n";
	else
		std::cout << i << "\n";
	
	// Print float
	std::cout << "float: ";
	if (std::isnan(f))
		std::cout << "nanf\n";
	else if (std::isinf(f))
		std::cout << (f < 0 ? "-inff\n" : "+inff\n");
	else {
		// Use scientific notation for very small/large numbers
		if ((f != 0.0f && (std::abs(f) < 0.1f || std::abs(f) >= 1000000.0f)))
			std::cout << std::scientific << std::setprecision(5) << f << "f\n";
		else
			std::cout << std::fixed << std::setprecision(1) << f << "f\n";
	}
	
	// Print double
	std::cout << "double: ";
	if (std::isnan(d))
		std::cout << "nan\n";
	else if (std::isinf(d))
		std::cout << (d < 0 ? "-inf\n" : "+inf\n");
	else {
		// Use scientific notation for very small/large numbers
		if ((d != 0.0 && (std::abs(d) < 0.1 || std::abs(d) >= 1000000.0)))
			std::cout << std::scientific << std::setprecision(5) << d << "\n";
		else
			std::cout << std::fixed << std::setprecision(1) << d << "\n";
	}
}

// Main conversion function
void ScalarConverter::convert(const std::string& literal) {
	Type type = identifyType(literal);

	switch (type) {
		case CHAR: {
			// Extract character from 'c' format or single char
			char c = (literal.length() == 3) ? literal[1] : literal[0];
			displayResults(c, static_cast<int>(c),
						  static_cast<float>(c), static_cast<double>(c));
			break;
		}

		case INT: {
			//convert string to long first to check if the value fits within the range of an int before casting
			std::stringstream ss(literal);
			long val = 0;
			ss >> val;
			// Check for conversion errors, out of range, or garbage after number
			if (ss.fail() || !ss.eof()) {
				std::cout << "char: impossible\n";
				std::cout << "int: impossible\n";
				std::cout << "float: impossible\n";
				std::cout << "double: impossible\n";
			} else {
				// int out of range, but float/double may still be valid
				if (val > INT_MAX || val < INT_MIN) {
					std::cout << "char: impossible\n";
					std::cout << "int: impossible\n";
					std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(val) << "f\n";
					std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(val) << "\n";
				} else {
					displayResults(static_cast<char>(val), static_cast<int>(val),
								  static_cast<float>(val), static_cast<double>(val));
				}
			}
			break;
		}

		case FLOAT: {
			float f = std::strtof(literal.c_str(), NULL);
			double d = std::strtod(literal.c_str(), NULL);
			// Check if float overflowed to infinity (but not pseudo-literals)
			if (std::isinf(f) && !isPseudoLiteral(literal)) {
				std::cout << "char: impossible\n";
				std::cout << "int: impossible\n";
				std::cout << "float: impossible\n";
				// Double might still be valid
				if (std::isinf(d) || std::isnan(d))
					std::cout << "double: impossible\n";
				else
					std::cout << "double: " << std::fixed << std::setprecision(1) << d << "\n";
			} else {
				displayResults(static_cast<char>(f), static_cast<int>(f),
							  f, static_cast<double>(f));
			}
			break;
		}

		case DOUBLE: {
			double d = std::strtod(literal.c_str(), NULL);
			// Check if double overflowed to infinity (but not pseudo-literals)
			if ((std::isinf(d) || std::isnan(d)) && !isPseudoLiteral(literal)) {
				std::cout << "char: impossible\n";
				std::cout << "int: impossible\n";
				std::cout << "float: impossible\n";
				std::cout << "double: impossible\n";
			} else {
				displayResults(static_cast<char>(d), static_cast<int>(d),
							  static_cast<float>(d), d);
			}
			break;
		}

		case INVALID:
			std::cout << "char: impossible\n";
			std::cout << "int: impossible\n";
			std::cout << "float: impossible\n";
			std::cout << "double: impossible\n";
			break;
	}
}