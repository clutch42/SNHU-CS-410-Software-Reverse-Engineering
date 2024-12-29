// assignment4_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main() {
    int input, c, i, j;
    c = 1;

    std::cout << "Enter number of rows" << std::endl;
    std::cin >> input;
    c = input - 1;
    for (i = 1; i <= input; i++) {
        for (j = 1; j <= c; j++) {
            std::cout << " ";
        }
        c--;
        for (j = 1; j <= i * 2 - 1; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    c = 1;
    for (i = 1; i <= input - 1; i++) {
        for (j = 1; j <= c; j++) {
            std::cout << " ";
        }
        c++;
        for (j = 1; j <= ((input - i) * 2) - 1; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    return 1;
}
