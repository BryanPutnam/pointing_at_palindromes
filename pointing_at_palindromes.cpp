/* 
Author: Bryan Putnam

Date: 10/16/2021

Class: CSC 3110-01

Pledge: I have neither given nor recieved unauthorized aid on this program. 

Description: Pointing at Palindromes is meant to simulate an airline account creation program. The user input various data through the console (Name, Birthday, Password, Pin)
and the program handels that input data. For the password specifically, the password the user chooses must be a palindrome and if it is not, they are prompted to try again. 
The check_palindrome method uses pointers to determind if values on on either side of the users password are the same. 

Input: The user will input data for Name, Birthday, Password, Pin, and NEW or EXIT to either create a new account or exit the program. 

Output: The program will output various print statements depending on the input from the user.
*/

#include <iostream> 
using namespace std; 

/*
Description: Prints an introduction to the program
Param: N/A
Return: N/A
*/
void introduction() { 
    cout << "\nWelcome to Putnam Air! We noticed that you do not have an account set up with our airline. \n"
    "If you follow the steps below and fill in your government name as well as a new password and pin number, we can get you all set up! \n";
}
/*
Description: Let's the user input their name.
Param: N/A
Return: N/A
*/
void nameIn() { 
    cout << "\nPlease input your first name as you see it on your government ID, below. \n"; 
    string name; 
    cin >> name; 
    cout << "\nWelcome to Putnam Air, " + name + "!\n"; 
}
/*
Description: Let's the user input their birthday.
Param: N/A
Return: N/A
*/
void birthdayIn() { 
    cout << "Please enter your birthday in mm/dd/yyyy form.\n"; 
    string bday; 
    cin >> bday; 
    if (bday.length() == 10) { 
        cout << "\nThank you! Be looking for an email on " << bday << " for promotional deals or rewards from Putnam air.\n";  
    }
    else { 
        birthdayIn(); 
    }
}
/*
Description: Let's the user input a password and checks the password for palindrome status. 
Param: N/A
Return: N/A
*/
void check_Palindrome() { 
    cout << "\nPlease create a new password for your account. Your password MUST be a palindrom to work with our system.\n"; 
    cout << "Type your new password below.\n"; 
    char *password = new char[1]; 
    cin >> password;
    char *forwards; 
    char *backwards;
    int length = strlen(password); 
    forwards = password; 
    backwards = forwards + length - 1; 

    for (forwards = password; forwards <= backwards;) { 
        if (*backwards == *forwards) { 
            backwards --; 
            forwards ++; 
        } else 
        break; 
    } 
    if (forwards > backwards) { 
        cout << "\nYour password, " << password <<  ",is a palindrome!\n"; 
        cout << "Password memory address: " << &password << "\n";
    }
    else {
        cout << "Invalid password: " << password << ". Please make sure your password is a palindrome.\n"; 
        check_Palindrome();
    } 
}
/*
Description: Let's the user input a pin for their account. 
Param: N/A
Return: N/A
*/
void pinIn() {
    cout << "\nPlease make a 4 character pin number for your new account. \n";
    string pin; 
    cin >> pin;
    if (pin.length() == 4) {
        cout << "The pin for your new account is: " + pin + "\n"; 
    }
    else {
        cout << "Invalid Pin: Your pin MUST be no more or no less than 4 charecters long.\n"; 
        pinIn();
    }
}
/*
Description: Prints a closing statement for the program. 
Param: N/A
Return: N/A
*/
void conclusion() { 
    cout << "\nThank you for creating an account with Putnam air! We look forward to flying with you soon!\n"; 
    cout << "To create a new account, type NEW below.\n";
    cout << "To exit, type EXIT below\n"; 
}
/*
Description: Prompts the user to either create a new account or exit the program.  
Param: N/A
Return: Returns an integer value or 1 or 0. 
*/
int newAccount() { 
    string answer; 
    cin >> answer; 
    if (answer == "NEW") { 
        return 1; 
    }
    else if (answer == "EXIT") { 
        cout << "\nWe look forward to flying with you soon!";
        return 0; 
    }
    else { 
        cout << "\nInvalid input. Try NEW or EXIT.\n";
        newAccount(); 
        return 0; 
    }
}

int main() { 
    introduction(); 
    nameIn(); 
    birthdayIn(); 
    check_Palindrome();
    pinIn(); 
    conclusion(); 

    if (newAccount() == 1) {
        main(); 
    }
}
