#pragma once
#include <iostream>
#include <string>
#include <bitset>
#include <chrono>

class GaloisField {
private:
    std::bitset<281> element;  

public:
    static const int array[];
    static constexpr unsigned int degree = 281;

    // Constructors
    GaloisField();
    GaloisField(const std::bitset<281>& input);
    GaloisField(const std::string& str, bool isHex = false);

    // Operations
    GaloisField add(const GaloisField& other) const;
    GaloisField mult(const GaloisField& other) const;
    GaloisField square() const;
    GaloisField pow(const GaloisField& exponent) const;
    GaloisField inverse() const;
    GaloisField trace() const;
    
    // Convertor
    static GaloisField convertFromString(const std::string& inputString);
    static GaloisField convertFromHex(const std::string& hexString);
    std::string convertToString() const;
    std::string convertToHex() const;

    // Static Methods
    static std::bitset<degree> polynomialModulusReduction(const std::bitset<2 * degree - 1>& input);

    // Constants
    static GaloisField zero();
    static GaloisField one();

};