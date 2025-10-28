#include "ScalarConverter.hpp"


static bool isPseudoFloat(const std::string& s) { return s == "nanf" || s == "+inff" || s == "-inff" || s == "inff"; }
static bool isPseudoDouble(const std::string& s) { return s == "nan" || s == "+inf" || s == "-inf" || s == "inf"; }
static bool isCharLiteral(const std::string& s) { return s.size() == 1 && std::isprint(static_cast<unsigned char>(s[0])) && !std::isdigit(static_cast<unsigned char>(s[0])); }

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }
ScalarConverter::~ScalarConverter() {}

static void printCharFromDouble(double d) {
	if (d != d || d > std::numeric_limits<char>::max() || d < std::numeric_limits<char>::min()) {
		std::cout << "char: impossible\n";
		return;
	}
	char c = static_cast<char>(d);
	if (!std::isprint(static_cast<unsigned char>(c))) {
		std::cout << "char: Non displayable\n";
	} else {
		std::cout << "char: '" << c << "'\n";
	}
}

static void printIntFromDouble(double d) {
	if (d != d || d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min()) {
		std::cout << "int: impossible\n";
	} else {
		std::cout << "int: " << static_cast<int>(d) << "\n";
	}
}

static void printFloat(double d, bool forcePointZero) {
	std::cout.setf(std::ios::fixed);
	std::cout.precision(forcePointZero ? 1 : 6);
	float f = static_cast<float>(d);
	if (d != d) {
		std::cout << "float: nanf\n";
	} else if (d == std::numeric_limits<double>::infinity()) {
		std::cout << "float: +inff\n";
	} else if (d == -std::numeric_limits<double>::infinity()) {
		std::cout << "float: -inff\n";
	} else {
		std::cout << "float: " << f << "f\n";
	}
}

static void printDouble(double d, bool forcePointZero) {
	std::cout.setf(std::ios::fixed);
	std::cout.precision(forcePointZero ? 1 : 6);
	if (d != d) {
		std::cout << "double: nan\n";
	} else if (d == std::numeric_limits<double>::infinity()) {
		std::cout << "double: +inf\n";
	} else if (d == -std::numeric_limits<double>::infinity()) {
		std::cout << "double: -inf\n";
	} else {
		std::cout << "double: " << d << "\n";
	}
}

//main function
void ScalarConverter::convert(const std::string& s) {
	if (isCharLiteral(s)) {
		const double d = static_cast<double>(s[0]);
		printCharFromDouble(d);
		printIntFromDouble(d);
		printFloat(d, true);
		printDouble(d, true);
		return;
	}

	if (isPseudoFloat(s) || isPseudoDouble(s)) {
		double d;
		if (s == "nanf" || s == "nan") d = std::numeric_limits<double>::quiet_NaN();
		else if (s == "+inff" || s == "inff" || s == "+inf" || s == "inf") d = std::numeric_limits<double>::infinity();
		else d = -std::numeric_limits<double>::infinity();
		printCharFromDouble(d);
		printIntFromDouble(d);
		printFloat(d, false);
		printDouble(d, false);
		return;
	}

	char* endptr = 0;
	bool ok = false;
	double d = 0.0;
	bool forcePointZero = false;

	// int
	if (!ok) {
		std::size_t i = 0;
		if (!s.empty() && (s[0] == '+' || s[0] == '-')) i = 1;
		if (i < s.size()) {
			ok = true;
			for (; i < s.size(); ++i) if (!std::isdigit(static_cast<unsigned char>(s[i]))) { ok = false; break; }
		}
		if (ok) {
			long v = std::strtol(s.c_str(), &endptr, 10);
			(void)endptr;
			d = static_cast<double>(v);
			forcePointZero = true;
		}
	}

	// float with trailing f
	if (!ok) {
		std::size_t dot = s.find('.');
		if (dot != std::string::npos && s.size() >= 2 && s[s.size()-1] == 'f') {
			d = std::strtod(s.c_str(), &endptr);
			if (endptr && *endptr == 'f' && *(endptr + 1) == '\0') {
				ok = true; forcePointZero = true;
			}
		}
	}

	// double with dot
	if (!ok) {
		std::size_t dot = s.find('.');
		if (dot != std::string::npos) {
			d = std::strtod(s.c_str(), &endptr);
			if (endptr && *endptr == '\0') { ok = true; forcePointZero = true; }
		}
	}

	if (!ok) {
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
		return;
	}

	printCharFromDouble(d);
	printIntFromDouble(d);
	printFloat(d, forcePointZero);
	printDouble(d, forcePointZero);
}


