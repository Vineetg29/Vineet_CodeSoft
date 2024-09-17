#include <iostream>
using namespace std;

// Function to perform the selected operation
void calculate(double num1, double num2, char operation) {
    switch(operation) {
        case '+':
            cout << "Result: " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Result: " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Result: " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 != 0) {
                cout << "Result: " << num1 / num2 << endl;
            } else {
                cout << "Error: Division by zero is not allowed." << endl;
            }
            break;
        default:
            cout << "Error: Invalid operation." << endl;
    }
}

int main() {
    double num1, num2;
    char operation;
    int choice;

    do {
        // Input two numbers from the user
        cout << "Enter first number: ";
        cin >> num1;

        cout << "Enter second number: ";
        cin >> num2;

        // Ask the user for the operation they want to perform
        cout << "Choose an operation (+, -, *, /): ";
        cin >> operation;

        // Perform the calculation
        calculate(num1, num2, operation);

        // Ask if the user wants to perform another calculation or exit
        cout << "Press 1 to perform another calculation or 0 to exit: ";
        cin >> choice;

    } while (choice == 1);  // Continue while the user inputs 1

    cout << "Calculator exited. Thank you!" << endl;

    return 0;
}

