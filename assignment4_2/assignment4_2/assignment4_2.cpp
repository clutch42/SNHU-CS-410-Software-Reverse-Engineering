// assignment4_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main() {
    int input;

    std::cout << "Enter Radius:" << std::endl;
    std::cin >> input;

    input = input * input * input;

    double result = static_cast<double>(input) * 3.14;

    std::cout << "The volume is: " << result << std::endl;

    return 0;
}