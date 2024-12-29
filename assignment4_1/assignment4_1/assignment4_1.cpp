// assignment4_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    int i, j, x;

    for (i = 1; i <= 9; i++)
    {
        for (j = 1; j <= 9; j++) {
            x = i * j;
            std::cout << i << " * " << j << " = " << x << std::endl;
        }
    }
    return 0;
}
