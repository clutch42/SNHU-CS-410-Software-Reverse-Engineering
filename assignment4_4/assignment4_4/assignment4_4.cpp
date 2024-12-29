// assignment4_4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main() {
    long binaryNumber, decimalNumber, powerOfTwo;
    int lastDigit;

    decimalNumber = 0;
    powerOfTwo = 1;

    std::cout << "Enter the binary number:" << std::endl;
    std::cin >> binaryNumber;

    while (binaryNumber != 0) {
        lastDigit = binaryNumber % 10;
        decimalNumber += lastDigit * powerOfTwo;
        powerOfTwo *= 2;
        binaryNumber /= 10;
    }

    std::cout << "Equivalent hexadecimal value: " << decimalNumber << std::endl;

    return 0;
}
