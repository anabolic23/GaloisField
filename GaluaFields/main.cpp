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
    //std::cout << "Hexadecimal representation of field1: " << field1.convertToHex() << std::endl;

    // Test hex convert
    //std::cout << "Hexadecimal representation of field2: " << field2.convertToHex() << std::endl;

    // Test addition operation
    //GaloisField sum = field1.add(field2);
    //std::cout << "Sum of field1 and field2: " << sum.convertToString() << std::endl;
    //std::cout << "Sum of field1 and field2(hex): " << sum.convertToHex() << std::endl;

    // Test mult operation
    //GaloisField mult = field1.mult(field2);
    //std::cout << "Mult of field1 and field2: " << mult.convertToString() << std::endl;
    //std::cout << "Mult of field1 and field2(hex): " << mult.convertToHex() << std::endl;

    // Test square operation
    //GaloisField squaredField1 = field1.square();
    //std::cout << "Square of field1: " << squaredField1.convertToString() << std::endl;
    //std::cout << "Square of field1(hex): " << squaredField1.convertToHex() << std::endl;

    // Test power operation 
    //GaloisField powerField1 = field1.pow(field3);
    //std::cout << "Field1 raised to the power of field3: " << powerField1.convertToString() << std::endl;
    //std::cout << "Field1 raised to the power of field3(hex): " << powerField1.convertToHex() << std::endl;

    // Test inverse 
    //GaloisField inverseField1 = field1.inverse();
    //std::cout << "Field1 inversed: " << inverseField1.convertToString() << std::endl;
    //std::cout << "Field1 inversed(hex): " << inverseField1.convertToHex() << std::endl;

    // Test trace 
    //GaloisField traceField1 = field1.trace();
    //std::cout << "Field1 trace: " << traceField1.convertToString() << std::endl;
    //std::cout << "Field1 trace(hex): " << traceField1.convertToHex() << std::endl;

    GaloisField a, b, c, result1, result2;

    a = testBinaryString1; 
    b = testBinaryString2; 
    c = testBinaryString3;

    result1 = (a.add(b)).mult(c); // (a + b) * c
    result2 = a.mult(c).add(b.mult(c)); // a * c + b * c

    if (result1.convertToString() == result2.convertToString()) {
        std::cout << "Right Distributivity Test Passed" << std::endl;
    }
    else {
        std::cout << "Right Distributivity Test Failed" << std::endl;
    }

    // Left Distributivity Test: c * (a + b) == c * a + c * b
    result1 = c.mult(a.add(b)); // c * (a + b)
    result2 = c.mult(a).add(c.mult(b)); // c * a + c * b

    if (result1.convertToString() == result2.convertToString()) {
        std::cout << "Left Distributivity Test Passed" << std::endl;
    }
    else {
        std::cout << "Left Distributivity Test Failed" << std::endl;
    }

    // Commutativity of Addition Test: a + b == b + a
    result1 = a.add(b); // a + b
    result2 = b.add(a); // b + a

    if (result1.convertToString() == result2.convertToString()) {
        std::cout << "Commutativity of Addition Test Passed" << std::endl;
    }
    else {
        std::cout << "Commutativity of Addition Test Failed" << std::endl;
    }

    // Commutativity of Multiplication Test: a * b == b * a
    result1 = a.mult(b); // a * b
    result2 = b.mult(a); // b * a

    if (result1.convertToString() == result2.convertToString()) {
        std::cout << "Commutativity of Multiplication Test Passed" << std::endl;
    }
    else {
        std::cout << "Commutativity of Multiplication Test Failed" << std::endl;
    }

    // Square Test: a.ToSquare() == a * a
    GaloisField squaredA = a.square(); // a.ToSquare()
    result1 = a.mult(a); // a * a

    if (squaredA.convertToString() == result1.convertToString()) {
        std::cout << "Square Test Passed" << std::endl;
    }
    else {
        std::cout << "Square Test Failed" << std::endl;
    }

    // Inverse Element Test: a * a.InverseElement() == 1
    GaloisField inverseA = a.inverse(); // a.InverseElement()
    result1 = a.mult(inverseA); // a * a.InverseElement()
    GaloisField identity = GaloisField::one(); // Identity element '1'

    if (result1.convertToString() == identity.convertToString()) {
        std::cout << "Inverse Element Test Passed" << std::endl;
    }
    else {
        std::cout << "Inverse Element Test Failed" << std::endl;
    }

    // Cycle Test
    std::string maxElement = "11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111";
    GaloisField result = a.pow(maxElement);

    if (result.convertToString() == GaloisField::one().convertToString()) {
        std::cout << "Cycle Test Passed" << std::endl;
    }
    else {
        std::cout << "Cycle Test Failed" << std::endl;
    }

    const int iterations = 10;

    // Measure time for addition
    long long totalTimeAdd = 0;
    for (int i = 0; i < iterations; ++i) {
        auto startTime = std::chrono::high_resolution_clock::now();
        GaloisField result = a.add(b);
        auto endTime = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
        totalTimeAdd += duration.count();
    }
    double averageTimeAdd = static_cast<double>(totalTimeAdd) / iterations;
    std::cout << "Average time for addition: " << averageTimeAdd << " microseconds\n";

    // Measure time for multiplication
    long long totalTimeMult = 0;
    for (int i = 0; i < iterations; ++i) {
        auto startTime = std::chrono::high_resolution_clock::now();
        GaloisField result = a.mult(b);
        auto endTime = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
        totalTimeMult += duration.count();
    }
    double averageTimeMult = static_cast<double>(totalTimeMult) / iterations;
    std::cout << "Average time for multiplication: " << averageTimeMult << " microseconds\n";

    // Measure time for squaring
    long long totalTimeSquare = 0;
    for (int i = 0; i < iterations; ++i) {
        auto startTime = std::chrono::high_resolution_clock::now();
        GaloisField result = a.square();
        auto endTime = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
        totalTimeSquare += duration.count();
    }
    double averageTimeSquare = static_cast<double>(totalTimeSquare) / iterations;
    std::cout << "Average time for squaring: " << averageTimeSquare << " microseconds\n";

    // Measure time for exponentiation
    long long totalTimePow = 0;
    for (int i = 0; i < iterations; ++i) {
        auto startTime = std::chrono::high_resolution_clock::now();
        GaloisField result = a.pow(b);
        auto endTime = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
        totalTimePow += duration.count();
    }
    double averageTimePow = static_cast<double>(totalTimePow) / iterations;
    std::cout << "Average time for exponentiation: " << averageTimePow << " microseconds\n";

    // Measure time for inversion
    long long totalTimeInverse = 0;
    for (int i = 0; i < iterations; ++i) {
        auto startTime = std::chrono::high_resolution_clock::now();
        GaloisField result = a.inverse();
        auto endTime = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
        totalTimeInverse += duration.count();
    }
    double averageTimeInverse = static_cast<double>(totalTimeInverse) / iterations;
    std::cout << "Average time for inversion: " << averageTimeInverse << " microseconds\n";

    return 0;
}