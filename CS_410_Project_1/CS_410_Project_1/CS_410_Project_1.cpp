// CS_410_Project_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

// as far as i can tell none of these are declared in any of the functions that we created
std::string userName;
std::string password = "123"; // got this from looking at the strings in the original .o file and trial and error of inputting in the program
int answer;
int choice;
int changeChoice;
int newService;
int num1 = 1; // nums are the values in the original program
int num2 = 2;
int num3 = 1;
int num4 = 1;
int num5 = 2;
std::string name1 = "Bob Jones"; // names are the values in the original program
std::string name2 = "Sarah Davis";
std::string name3 = "Amy Friendly";
std::string name4 = "Johnny Smith";
std::string name5 = "Carol Spears";

/* function that gets an integer from the user and returns it
* this checks that only an integer is entered, and
* also checks for overflow if the number entered is larger than
* max of min for signed integer. stio() function does that automatically.
* created this function in last assignment and liked how it worked. added
* min and max arguments to check for the range
*/
static int getInt(int min, int max) {
    int input;
    std::string line;

    while (true) {
        std::cout << "Enter a number: ";
        std::getline(std::cin, line);  // Read the entire line as a string

        try {
            size_t pos;
            input = std::stoi(line, &pos); // Attempt to convert string to integer. gives position of last read index
            if (pos == line.size() && (input >= min && input <= max)) {
                break; // Conversion successful, and no extra characters
            }
            else {
                throw std::invalid_argument("Invalid number");
            }

        }
        catch (std::invalid_argument& e) {
            std::cout << e.what() << std::endl; // Display the error message
        }
        catch (std::out_of_range& e) {
            std::cout << "Number out of range. Try again:" << std::endl; // Conversion failed due to out of range input
        }
    }
    return input;
}

// function for access to application
// returns 1 for valid and 2 for invalid password
int CheckUserPermissionAccess() {
    int match = 0;
    // using string to eliminate need to limit size
    std::string inputPassword;
    std::cout << "Enter your username:" << std::endl;
    // using string to eliminate need to limit size
    std::getline(std::cin, userName);

    std::cout << "Enter your password:" << std::endl;
    std::getline(std::cin, inputPassword);
   
    match = inputPassword.compare(password);

    // Clear password string before exiting function
    inputPassword = "";

    if (match == 0) {
        return 1;
    }
    else {
        return 2;
    }
}

// function for dislaying the client name and selected option
void DisplayInfo() {
    std::cout << "  Client's Name    Service Selected (1 = Brokerage, 2 = Retirement)" << std::endl;
    std::cout << "1. " << name1 << " selected option " << num1 << std::endl;
    std::cout << "2. " << name2 << " selected option " << num2 << std::endl;
    std::cout << "3. " << name3 << " selected option " << num3 << std::endl;
    std::cout << "4. " << name4 << " selected option " << num4 << std::endl;
    std::cout << "5. " << name5 << " selected option " << num5 << std::endl;
}

// function to change the clients choice
void ChangeCustomerChoice() {
    std::cout << "Enter the number of the client that you wish to change" << std::endl;
    // security vulnerability: need to make sure user input is an integer
    // while it isn't exactly a security vulnerability the integer should have a coresponding name associated with it
    changeChoice = getInt(1, 5);
    std::cout << "Please enter the client's new service choice (1 = Brokerage, 2 = Retirement)" << std::endl;
    // security vulnerability: need to make sure user input is an integer
    // while not exactly a security vulnerability the integer should be 1 or 2
    newService = getInt(1, 2);
    // used a switch because it is easier to read than if else statements
    switch (changeChoice) {
    case 1:
        num1 = newService;
        break;
    case 2:
        num2 = newService;
        break;
    case 3:
        num3 = newService;
        break;
    case 4:
        num4 = newService;
        break;
    case 5:
        num5 = newService;
        break;
    default:
        break;
    }
}


int main()
{
    std::cout << "Created by Brian Engel" << std::endl;
    std::cout << "Hello! Welcome to our Investment Company" << std::endl;
    
    // check for valid password and if invalid ask again 
    answer = CheckUserPermissionAccess();
    while (answer != 1) {
        std::cout << "Invalid Password. Please try again" << std::endl;
        answer = CheckUserPermissionAccess();
    }

    // used do while since it always runs at least once
    do {
        std::cout << "What would you like to do?" << std::endl;
        std::cout << "DISPLAY the client list (enter 1)" << std::endl;
        std::cout << "CHANGE a client's choice (enter 2)" << std::endl;
        std::cout << "Exit the program.. (enter 3)" << std::endl;
        // security vulnerability: need to make sure user input is an integer
        // while not exactly a vulnerability the choice should be 1-3
        choice = getInt(1, 3);
        std::cout << "You chose " << choice << std::endl;
        // used a switch because it is easier to read than if else statements
        switch (choice) {
        case 1:
            DisplayInfo();
            break;
        case 2:
            ChangeCustomerChoice();
            break;
        default:
            break;
        }
    } while (choice != 3);
}
