// Assignment6_1Fix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <limits>

constexpr int MAX_VALUE = std::numeric_limits<int>::max();
constexpr int MIN_VALUE = std::numeric_limits<int>::min();

/* included in original code */
static void DisplayMenu(){
    std::cout << "----------------" << std::endl;
    std::cout << " - 1)Add -" << std::endl;
    std::cout << " - 2)Subtract -" << std::endl;
    std::cout << " - 3)Multiply -" << std::endl;
    std::cout << " - 4)Exit -" << std::endl;
    std::cout << "----------------" << std::endl;
}

/* function that gets an integer from the user and returns it
* this checks that only an integer is entered, and
* also checks for overflow if the number entered is larger than
* max of min for signed integer. (stio() function does that automatically
*/
static int getInt() {
    int input;
    std::string line;

    while (true) {
        std::cout << "Enter a number: ";
        std::getline(std::cin, line);  // Read the entire line as a string

        try {
            size_t pos;
            input = std::stoi(line, &pos); // Attempt to convert string to integer. gives position of last read index
            if (pos == line.size()) {
                break; // Conversion successful, and no extra characters
            }
            else {
                throw std::invalid_argument("Extra characters after number");
            }

        }
        catch (std::invalid_argument& e) {
            std::cout << "Must be a number: " << e.what() << std::endl; // Display the error message
        }
        catch (std::out_of_range& e) {
            std::cout << "Number out of range. Try again:" << std::endl; // Conversion failed due to out of range input
        }
    }
    return input;
}

/* detect overflow / underflow for addition 
* returns 0 for no overflow,1 for overflow, -1 for underflow 
*/
static int addInts(const int& num1, const int& num2) {
    if (num1 > MAX_VALUE - num2) {
        return 1;
    }
    if (num1 < MIN_VALUE + num2) {
        return -1;
    }
    return 0;
}

/* detect overflow / underflow for subtraction
* returns 0 for no overflow,1 for overflow, -1 for underflow 
*/
static int subtractInts(const int& num1, const int& num2) {
    if (num1 < MIN_VALUE + num2) {
        return -1;
    }
    if (num1 > MAX_VALUE - num2) {
        return 1;
    }
    return 0;
}

/* detect overflow / underflow for multiplication
* returns 0 for no overflow,1 for overflow, -1 for underflow 
*/
static int multiplyInts(const int& num1, const int& num2) {
    if (num2 == 0 || num1 == 0) {
        return 0;
    }
    if (num1 > 0) {
        if (num2 > 0) {
            if (num1 > MAX_VALUE / num2) {
                return 1;
            }
        }
        else {
            if (num1 > MIN_VALUE / num2) {
                return -1;
            }
        }
    }
    else {
        if (num2 > 0) {
            if (num1 < MIN_VALUE / num2) {
                return -1;
            }
        }
        else {
            if (num1 < MAX_VALUE / num2) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    
    int input, num1, num2;
    input = 0;
    /*
    * the original condition does not match the menu
    while (input != 5) {
    */
    while (input != 4) {
        /*
        * there is already a function that does this
        std::cout << "----------------" << std::endl;
        std::cout << " - 1)Add -" << std::endl;
        std::cout << " - 2)Subtract -" << std::endl;
        std::cout << " - 3)Multiply -" << std::endl;
        std::cout << " - 4)Exit -" << std::endl;
        std::cout << "----------------" << std::endl;
        */
        DisplayMenu();
        /*
        * need to check if input is an integer
        * we have a lot of integers input in this program so i created a function that 
        * ensures an int is entered
        std::cin >> input;
        */
        input = getInt();

        switch (input) {
        case 1:
            num1 = getInt();
            num2 = getInt();
            /*
            * should be addition for option 1
            * added a function to check for integer overflow and underflow in addition
            std::cout << num1 << " - " << num2 << " = " << num1 - num2 << std::endl;
            */
            if (addInts(num1, num2) == 0) {
                std::cout << num1 << " + " << num2 << " = " << num1 + num2 << std::endl;
            }
            else if (addInts(num1, num2) < 0) {
                std::cout << "Underflow detected" << std::endl;
            }
            else {
                std::cout << "Overflow detected" << std::endl;
            }
            break;
        case 2:
            num1 = getInt();
            num2 = getInt();
            /*
            * should be subtraction for option 2
            * added a function to check for integer overflow and underflow in subtraction
            std::cout << num1 << " - " << num2 << " = " << num1 + num2 << std::endl;
            */
            if (subtractInts(num1, num2) == 0) {
                std::cout << num1 << " - " << num2 << " = " << num1 - num2 << std::endl;
            }
            else if (subtractInts(num1, num2) < 0) {
                std::cout << "Underflow detected" << std::endl;
            }
            else {
                std::cout << "Overflow detected" << std::endl;
            }
            break;
        case 3:
            num1 = getInt();
            num2 = getInt();
            /*
            * should be multiplication for option 3
            * added a function to check for integer overflow and underflow in multiplication
            std::cout << num1 << " - " << num2 << " = " << num1 / num2 << std::endl;
            */
            if (multiplyInts(num1, num2) == 0) {
                std::cout << num1 << " * " << num2 << " = " << num1 * num2 << std::endl;
            }
            else if (multiplyInts(num1, num2) < 0) {
                std::cout << "Underflow detected" << std::endl;
            }
            else {
                std::cout << "Overflow detected" << std::endl;
            }
            break;
        }
    }
    return 0;
}
