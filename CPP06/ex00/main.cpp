#include "ScalarConverter.hpp"

int main(int argc, char** argv) {
    // Your friend's test cases
    if (argc == 3 && std::string(argv[1]) == "pseudo" && std::string(argv[2]) == "test")
    {
        std::cout << "=== Pseudo Literal Test ===\n";
        ScalarConverter::convert("nan"); 
        std::cout << "\n";
        ScalarConverter::convert("nanf"); 
        std::cout << "\n";
        ScalarConverter::convert("+inf"); 
        std::cout << "\n";
        ScalarConverter::convert("+inff"); 
        std::cout << "\n";
        ScalarConverter::convert("-inf"); 
        std::cout << "\n";
        ScalarConverter::convert("-inff"); 
        std::cout << "\n";
        ScalarConverter::convert("inf"); 
        std::cout << "\n";
        ScalarConverter::convert("inff"); 
        std::cout << "\n";
    }
    else if (argc == 3 && std::string(argv[1]) == "char" && std::string(argv[2]) == "test")
    {
        std::cout << "=== Character Test (ASCII -125 to 127) ===\n";
        for (int i = -125; i < 127; i++)
        {
            char c = static_cast<char>(i);
            std::string str(1, c);
            std::cout << "Testing char value: " << i << "\n";
            ScalarConverter::convert(str);
            std::cout << "\n";
        }
    }
    else if (argc == 3 && std::string(argv[1]) == "int" && std::string(argv[2]) == "test") 
    {
        std::cout << "=== Integer Test ===\n";
        
        // Negative extended ASCII range
        std::cout << "--- Testing negative extended ASCII (-100 to -10) ---\n";
        for (int i = -100; i < -10; i++) {
            char c = static_cast<char>(i);
            std::string str(1, c);
            std::cout << "Testing: " << i << "\n";
            ScalarConverter::convert(str);
            std::cout << "\n"; 
        }

        // Positive extended ASCII range
        std::cout << "--- Testing positive extended ASCII (127 to 200) ---\n";
        for (int i = 127; i < 200; i++) {
            char c = i;
            std::string str(1, c);
            std::cout << "Testing: " << i << "\n";
            ScalarConverter::convert(str);
            std::cout << "\n"; 
        }

        // INT_MIN
        std::cout << "--- Testing INT_MIN (-2147483648) ---\n";
        ScalarConverter::convert("-2147483648");
        std::cout << "\n";
        
        // INT_MAX
        std::cout << "--- Testing INT_MAX (2147483647) ---\n";
        ScalarConverter::convert("2147483647");
        std::cout << "\n";
        
        // INT_MIN - 1 (overflow)
        std::cout << "--- Testing INT_MIN - 1 (-2147483649) ---\n";
        ScalarConverter::convert("-2147483649");
        std::cout << "\n";
        
        // INT_MAX + 1 (overflow)
        std::cout << "--- Testing INT_MAX + 1 (2147483648) ---\n";
        ScalarConverter::convert("2147483648");
        std::cout << "\n";
    }
    else if (argc == 3 && std::string(argv[1]) == "float" && std::string(argv[2]) == "test") 
    {
        std::cout << "=== Float Test ===\n";
        
        // Float overflow (exceeds FLT_MAX)
        std::cout << "--- Testing float overflow (3.40282347e+39f) ---\n";
        ScalarConverter::convert("3.40282347e+39f");
        std::cout << "\n";
        
        std::cout << "--- Testing negative float overflow (-3.40282347e+39f) ---\n";
        ScalarConverter::convert("-3.40282347e+39f");
        std::cout << "\n";
        
        // Float max value
        std::cout << "--- Testing FLT_MAX (3.40282347e+38f) ---\n";
        ScalarConverter::convert("3.40282347e+38f");
        std::cout << "\n";
        
        std::cout << "--- Testing -FLT_MAX (-3.40282347e+38f) ---\n";
        ScalarConverter::convert("-3.40282347e+38f");
        std::cout << "\n";
        
        // Large float values
        std::cout << "--- Testing large float (21474836475.02345f) ---\n";
        ScalarConverter::convert("21474836475.02345f");
        std::cout << "\n";
        
        std::cout << "--- Testing large float (214748364234.76543f) ---\n";
        ScalarConverter::convert("214748364234.76543f");
        std::cout << "\n";
        
        // Double range in float format
        std::cout << "--- Testing double range as float (+1.7976931348623157e+308f) ---\n";
        ScalarConverter::convert("+1.7976931348623157e+308f");
        std::cout << "\n";
        
        std::cout << "--- Testing double range as float (-1.7976931348623157e+308f) ---\n";
        ScalarConverter::convert("-1.7976931348623157e+308f");
        std::cout << "\n";
    }
    else if (argc == 3 && std::string(argv[1]) == "double" && std::string(argv[2]) == "test") 
    {
        std::cout << "=== Double Test ===\n";
        
        // Float overflow as double
        std::cout << "--- Testing float overflow as double (3.40282347e+39) ---\n";
        ScalarConverter::convert("3.40282347e+39");
        std::cout << "\n";
        
        std::cout << "--- Testing negative float overflow as double (-3.40282347e+39) ---\n";
        ScalarConverter::convert("-3.40282347e+39");
        std::cout << "\n";
        
        // Large double values
        std::cout << "--- Testing large double (21474836475.02345) ---\n";
        ScalarConverter::convert("21474836475.02345");
        std::cout << "\n";
        
        std::cout << "--- Testing large double (214748364234.76543) ---\n";
        ScalarConverter::convert("214748364234.76543");
        std::cout << "\n";
        
        // Double max value
        std::cout << "--- Testing DBL_MAX (+1.7976931348623157e+308) ---\n";
        ScalarConverter::convert("+1.7976931348623157e+308");
        std::cout << "\n";
        
        std::cout << "--- Testing -DBL_MAX (-1.7976931348623157e+308) ---\n";
        ScalarConverter::convert("-1.7976931348623157e+308");
        std::cout << "\n";
        
        // Double overflow
        std::cout << "--- Testing double overflow (+1.7976931348623157e+309) ---\n";
        ScalarConverter::convert("+1.7976931348623157e+309");
        std::cout << "\n";
        
        std::cout << "--- Testing double overflow (-1.7976931348623157e+309) ---\n";
        ScalarConverter::convert("-1.7976931348623157e+309");
        std::cout << "\n";
        
        // Very large integer that overflows to +inf
        std::cout << "--- Testing very large integer (280 digits) ---\n";
        ScalarConverter::convert("578375827458627463756486058436538957635786248957880682404205625637584565829401568544569405684146840248349256945058735694835697658017864034620460846728956832956406440384720347284723804732847304738473849748374839470324702348732840732847230384738472384730274380473845084047234892346384458395");
        std::cout << "\n";
    }
    else if (argc == 3 && std::string(argv[1]) == "invalid" && std::string(argv[2]) == "test") 
    {
        std::cout << "=== Invalid Input Test ===\n";
        
        std::cout << "--- Testing invalid float (3.40282347fa) ---\n";
        ScalarConverter::convert("3.40282347fa");
        std::cout << "\n";
        
        std::cout << "--- Testing invalid number (-3.402823g47) ---\n";
        ScalarConverter::convert("-3.402823g47");
        std::cout << "\n";
        
        std::cout << "--- Testing invalid float (3.40282347f1234) ---\n";
        ScalarConverter::convert("3.40282347f1234");
        std::cout << "\n";
        
        std::cout << "--- Testing invalid scientific notation (-3.40282347e+1f) ---\n";
        ScalarConverter::convert("-3.40282347e+1f");
        std::cout << "\n";
        
        std::cout << "--- Testing invalid number (214748w36475.02345f) ---\n";
        ScalarConverter::convert("214748w36475.02345f");
        std::cout << "\n";
        
        std::cout << "--- Testing invalid number (214748364234.76543t) ---\n";
        ScalarConverter::convert("214748364234.76543t");
        std::cout << "\n";
        
        std::cout << "--- Testing invalid scientific notation (+1.797693y1348623157e+3) ---\n";
        ScalarConverter::convert("+1.797693y1348623157e+3");
        std::cout << "\n";
        
        std::cout << "--- Testing invalid exponent (-1.7976931348623157e+-3) ---\n";
        ScalarConverter::convert("-1.7976931348623157e+-3");
        std::cout << "\n";
    }
    else if (argc == 2)
    {
        // Single argument mode - convert the provided literal
        ScalarConverter::convert(argv[1]);
    }
    else if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <literal>\n";
        std::cerr << "   or: " << argv[0] << " <test_type> test\n\n";
        std::cerr << "Available test types:\n";
        std::cerr << "  pseudo  - Test pseudo-literals (nan, inf, etc.)\n";
        std::cerr << "  char    - Test character conversions\n";
        std::cerr << "  int     - Test integer edge cases and overflow\n";
        std::cerr << "  float   - Test float edge cases and overflow\n";
        std::cerr << "  double  - Test double edge cases and overflow\n";
        std::cerr << "  invalid - Test invalid inputs\n";
    }
    else
    {
        std::cerr << "Error: Too many arguments.\n";
    }
    
    return 0;
}