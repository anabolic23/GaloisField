#include <iostream>
#include "GaloisField.h" 

int main() {
    // Test constructor with string input (binary)
    std::string testBinaryString1 = "11101001000010111010011101110100000010101010000000000110000011010000100001010001010011110001110101011110101111010000100001001101101100011111011111110111110110011000100100111000110000101100111101010110100100111111111111000111100100000011000000101110000001101000000100001111100001101";
    GaloisField field1(testBinaryString1, false);
    std::cout << "Element initialized with binary string1: " << field1.convertToString() << std::endl;

    // Test constructor with string input (binary)
    std::string testBinaryString2 = "10000010011011110100111000001101101011111010011110001001110011000101111101000011110100101011001001111101011010001111010001101010000111010110011100110001100101111111000000100011011011110101100001110000001111010100101000100010110110011010001011011110100001001101100110011001011110100";
    GaloisField field2(testBinaryString2, false);
    std::cout << "Element initialized with binary string2: " << field2.convertToString() << std::endl;

    std::string testBinaryString3 = "01101011011001001110100101111001101001010000011110001111110000010101011100010010100111011010111100100011110101011111110001101011011001001110100101111001101001010000011110001111110000010101011100010010100111011010111100100011110101011111110001101011011001001110100101111001101001010";
    GaloisField field3(testBinaryString3, false);
    std::cout << "Element initialized with binary string3: " << field3.convertToString() << std::endl;

    // Test hex convert
    std::cout << "Hexadecimal representation of field1: " << field1.convertToHex() << std::endl;

    // Test hex convert
    std::cout << "Hexadecimal representation of field2: " << field2.convertToHex() << std::endl;

    // Test addition operation
    GaloisField sum = field1.add(field2);
    std::cout << "Sum of field1 and field2: " << sum.convertToString() << std::endl;
    std::cout << "Sum of field1 and field2(hex): " << sum.convertToHex() << std::endl;

    // Test mult operation
    GaloisField mult = field1.mult(field2);
    std::cout << "Mult of field1 and field2: " << mult.convertToString() << std::endl;
    std::cout << "Mult of field1 and field2(hex): " << mult.convertToHex() << std::endl;

    // Test square operation
    GaloisField squaredField1 = field1.square();
    std::cout << "Square of field1: " << squaredField1.convertToString() << std::endl;
    std::cout << "Square of field1(hex): " << squaredField1.convertToHex() << std::endl;

    // Test power operation 
    GaloisField powerField1 = field1.pow(field3);
    std::cout << "Field1 raised to the power of field3: " << powerField1.convertToString() << std::endl;
    std::cout << "Field1 raised to the power of field3(hex): " << powerField1.convertToHex() << std::endl;

    // Test inverse 
    GaloisField inverseField1 = field1.inverse();
    std::cout << "Field1 inversed: " << inverseField1.convertToString() << std::endl;
    std::cout << "Field1 inversed(hex): " << inverseField1.convertToHex() << std::endl;

    // Test trace 
    GaloisField traceField1 = field1.trace();
    std::cout << "Field1 trace: " << traceField1.convertToString() << std::endl;
    std::cout << "Field1 trace(hex): " << traceField1.convertToHex() << std::endl;

    return 0;
}