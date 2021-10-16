#include <iostream> 
using namespace std; 

void introduction() { 
    cout << "Welcome to Putnam Air! We noticed that you do not have an account set up with our airline. \n"
    "If you follow the steps below and fill in your government name as well as a new password and pin number, we can get you all set up! \n";
}

void nameIn() { 
    cout << "Please input the fist name you see on your government ID, below. \n"; 
    string name; 
    cin >> name; 
    cout << "Welcome to Putnam Air, " + name + "!\n"; 
}

void birthdayIn() { 
    cout << "Please enter your birthday in mm/dd/yyyy form.\n"; 
    string bday; 
    cin >> bday; 
    if (bday.length() == 10) { 
        cout << "Thank you!\n"; 
    }
    else { 
        birthdayIn(); 
    }
}

void passwordIn() { 
    cout << "Please create a new password for your account. Your password MUST be a palindrom to work with our system.\n"; 
    string password; 
    cin >> password; 
    if (password == "palindrome") { //obvously "palindrome" will not stay there
        cout << "Your new password is: " + password + ".\n";
    }
    else { 
        cout << "Your password MUST be a palindrome\n"; 
        passwordIn(); 
    }
}

void pinIn() {
    cout << "Please make a 4 character pin number for your new account. \n";
    string pin; 
    cin >> pin;
    if (pin.length() == 4) {
        cout << "The pin for your new account is: " + pin; 
    }
    else {
        cout << "Please make sure your pin is no more or no less than 4 charecters long.\n"; 
        pinIn();
    }
}

int main() { 
    introduction(); 
    nameIn(); 
    birthdayIn(); 
    passwordIn(); 
    pinIn(); 
}
