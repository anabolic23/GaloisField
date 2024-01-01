#include <iostream>
#include "GaloisField.h"

// Default constructor
GaloisField::GaloisField() : element(0) {}

// Constructor with a std::bitset input
GaloisField::GaloisField(const std::bitset<281>& input) : element(input) {}

// Constructor with a string input (assuming it's a binary string)
GaloisField::GaloisField(const std::string& str, bool isHex) {
    if (isHex) {
        *this = convertFromHex(str); 
    }
    else {
        *this = convertFromString(str);
    }
}

GaloisField GaloisField::convertFromHex(const std::string& hexString) {
    size_t requiredSize = (degree + 3) / 4; // Calculate the required size of the hex string
    if (hexString.size() != requiredSize) {
        std::cerr << "Invalid hexadecimal string format or length." << std::endl;
        return GaloisField(); 
    }

    std::string binaryString;
    for (size_t i = 2; i < hexString.size(); ++i) {
        char c = std::toupper(hexString[i]);
        if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F'))) {
            std::cerr << "Invalid character in hexadecimal string: " << c << std::endl;
            return GaloisField(); 
        }

        int value = (c >= 'A') ? (c - 'A' + 10) : (c - '0');
        binaryString += std::bitset<4>(value).to_string();
    }

    return GaloisField(binaryString, false);
}

GaloisField GaloisField::convertFromString(const std::string& binaryString) {
    if (binaryString.size() != degree) {
        std::cerr << "Input string length must be 281 bits." << std::endl;
        return GaloisField(); 
    }

    GaloisField gf;
    for (size_t i = 0; i < degree; ++i) {
        if (binaryString[i] == '1') {
            gf.element.set(degree - 1 - i, true);
        }
        else if (binaryString[i] != '0') {
            std::cerr << "Invalid character in binary string: " << binaryString[i] << std::endl;
            return GaloisField(); 
        }
    }

    return gf;
}

std::string GaloisField::convertToString() const {
    std::string elementString;
    for (int i = 280; i >= 0; --i) {
        elementString += (element[i] ? '1' : '0');
    }
    return elementString;
}

std::string GaloisField::convertToHex() const {
    std::string hexRepresentation;
    const size_t bits = degree;

    for (int i = 0; i < bits; i += 4) {
        int hexValue = 0;
        constexpr int hexDigitSize = 4;

        for (int j = 0; j < hexDigitSize && (i + j) < bits; ++j) {
            if (element.test(i + j)) {
                hexValue |= 1 << j;
            }
        }

        const char hexChar = hexValue < 10 ? '0' + hexValue : 'A' + hexValue - 10;
        hexRepresentation = hexChar + hexRepresentation;
    }

    return hexRepresentation;
}

GaloisField GaloisField::add(const GaloisField& other) const {
    std::bitset<281> result = this->element ^ other.element; // XOR operation
    return GaloisField(result);
}

const int GaloisField::array[] = { 0, 1, 4, 9, 281 };
std::bitset<281> GaloisField::polynomialModulusReduction(const std::bitset<2 * degree - 1>& input) {
    std::bitset<2 * degree - 1> modulusPolynomial;
    for (int index : array) {
        modulusPolynomial.set(index);
    }

    std::bitset<2 * degree - 1> polynomial = input;

    constexpr int startIndex = 2 * degree - 2;
    constexpr int reducedDegree = degree;

    for (int i = startIndex; i >= reducedDegree; --i) {
        if (polynomial.test(i)) {
            polynomial ^= modulusPolynomial << (i - reducedDegree);
        }
    }

    std::bitset<degree> reducedResult;
    for (int i = 0; i < degree; ++i) {
        reducedResult[i] = polynomial[i];
    }
    return reducedResult;
}

GaloisField GaloisField::mult(const GaloisField& other) const {
    std::bitset<2 * degree - 1> product(0); // Initialize product to zero polynomial

    for (int i = 0; i < degree; ++i) {
        if (element.test(i)) {
            for (int j = 0; j < degree; ++j) {
                if (other.element.test(j)) {
                    int idx = i + j;
                    // Ensuring the index is within bounds of 'product'
                    if (idx < 2 * degree - 1) {
                        product[idx] = product[idx] ^ 1;
                    }
                }
            }
        }
    }
    return GaloisField(polynomialModulusReduction(product));
}

GaloisField GaloisField::square() const {
    return mult(*this); 
}

GaloisField GaloisField::pow(const GaloisField& exponent) const {
    GaloisField result(1); // Initialize result with the identity element

    // Base element for repeated squaring
    GaloisField base = *this;

    // Convert the field element to a binary string for processing
    std::string binExponent = exponent.convertToString();

    // Iterate through the binary representation of the exponent
    for (size_t i = 0; i < degree; ++i) {
        result = result.square(); // Square the result for each bit of the exponent

        if (binExponent[i] == '1') {
            result = result.mult(base); // Multiply the result by the base element if the bit is set
        }
    }

    return result;
}

GaloisField GaloisField::inverse() const {
    GaloisField temp = *this;
    GaloisField output(1);

    for (int i = 0; i < degree - 1; ++i) {
        temp = temp.square();
        output = output.mult(temp);
    }

    return output;
}

GaloisField GaloisField::trace() const {
    GaloisField temp = *this;
    GaloisField output = temp;

    for (int i = 0; i < degree - 1; ++i) {
        temp = temp.square();
        output = output.add(temp);
    }

    return output;
}

GaloisField GaloisField::zero() {
    return GaloisField(); 
}

GaloisField GaloisField::one() {
    // Create a GaloisField object with the bitset representing the number 1
    std::bitset<281> neutralOne;
    neutralOne.set(0); // Set the least significant bit to 1

    return GaloisField(neutralOne);
}