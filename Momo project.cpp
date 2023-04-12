#include <iostream>

using namespace std;

int main() {
    int balance = 1000;
    int pin_attempt = 0;
    int pin = 0000;
    int option = 0;

    while (option != 5) {
        cout << "Welcome to MTN Mobile Money Service" << endl;
        cout << "1. Authenticate" << endl;
        cout << "2. Reset/Change PIN" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Send Money" << endl;
        cout << "5. Exit" << endl;
        cout << "Choose an option: ";

        cin >> option;

        if (option == 1) {
            int user_pin;
            cout << "Enter your PIN: ";
            cin >> user_pin;

            if (user_pin == pin) {
                cout << "Authentication successful" << endl;
                pin_attempt = 0;
            } else {
                cout << "Incorrect PIN" << endl;
                pin_attempt++;
            }

            if (pin_attempt >= 3) {
                cout << "Too many incorrect PIN attempts. Exiting..." << endl;
                break;
            }
        } else if (option == 2) {
            cout << "Enter new PIN: ";
            cin >> pin;
            cout << "PIN successfully changed" << endl;
        } else if (option == 3) {
            cout << "Your balance is: " << balance << endl;
        } else if (option == 4) {
            int amount;
            cout << "Enter amount to send: ";
            cin >> amount;

            if (amount > balance) {
                cout << "Insufficient funds" << endl;
            } else {
                balance -= amount;
                cout << "Successfully sent " << amount << endl;
                cout << "New balance is: " << balance << endl;
            }
        } else if (option == 5) {
            cout << "Exiting Mobile Money Service" << endl;
        } else {
            cout << "Invalid option. Please try again." << endl;
        }
    }

    return 0;
}

