#include <iostream> 
using namespace std; 

void introduction() { 
    cout << "\nWelcome to Putnam Air! We noticed that you do not have an account set up with our airline. \n"
    "If you follow the steps below and fill in your government name as well as a new password and pin number, we can get you all set up! \n";
}

void nameIn() { 
    cout << "\nPlease input your first name as you see it on your government ID, below. \n"; 
    string name; 
    cin >> name; 
    cout << "\nWelcome to Putnam Air, " + name + "!\n"; 
}

void birthdayIn() { 
    cout << "Please enter your birthday in mm/dd/yyyy form.\n"; 
    string bday; 
    cin >> bday; 
    if (bday.length() == 10) { 
        cout << "\nThank you!\n"; 
    }
    else { 
        birthdayIn(); 
    }
}

void check_Palindrome() { 
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
        cout << "New password created.\n"; 
    }
    else {
        cout << "Invalid password: Please make sure your password is a palindrome.\n"; 
        check_Palindrome();
    } 
}

void pinIn() {
    cout << "\nPlease make a 4 character pin number for your new account. \n";
    string pin; 
    cin >> pin;
    if (pin.length() == 4) {
        cout << "The pin for your new account is: " + pin; 
    }
    else {
        cout << "Invalid Pin: Your pin MUST be no more or no less than 4 charecters long.\n"; 
        pinIn();
    }
}

void conclusion() { 
    cout << "\nThank you for creating an account with Putnam air! We look forward to flying with you soon!"; 
    cout << "To see your information, type HELP below.\n";
    cout << "To create a new account, type NEW below.\n";
    cout << "To exit, type EXIT below\n"; 
}

int main() { 
    introduction(); 
    nameIn(); 
    birthdayIn(); 

    cout << "\nPlease create a new password for your account. Your password MUST be a palindrom to work with our system.\n"; 
    cout << "Type your new password below.\n"; 
    check_Palindrome();

    pinIn(); 
    conclusion(); 
}
