// I included these libraries to use input/output and basic functions
#include <iostream>
using namespace std;

// This part is for the function that converts meters to feet
double metersToFeet(double meters) {
    return meters * 3.28084;
}

// This one is to convert feet to meters
double feetToMeters(double feet) {
    return feet / 3.28084;
}

// Here I convert kilograms to pounds
double kilogramsToPounds(double kg) {
    return kg * 2.20462;
}

// This one is pounds to kilograms
double poundsToKilograms(double lb) {
    return lb / 2.20462;
}

// Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

// Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

int main() {
    int choice;
    double value;
    int reverseChoice = 0; // I added this to track which specific conversion to reverse
    bool continueReversed = false; // I use this to know if the user wants to keep reversed state

    
    
    // === The stretch challenge starts here ===

    // I used a loop so the program keeps running until the user exits
    while (true) {
        cout << "\n=== Unit Converter ===" << endl;
        cout << "Choose a conversion:" << endl;
        cout << "1. Meters to Feet" << (reverseChoice == 1 && continueReversed ? " (Reversed)" : "") << endl;
        cout << "2. Kilograms to Pounds" << (reverseChoice == 2 && continueReversed ? " (Reversed)" : "") << endl;
        cout << "3. Celsius to Fahrenheit" << (reverseChoice == 3 && continueReversed ? " (Reversed)" : "") << endl;
        cout << "4. Reverse a specific conversion direction" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 5) {
            break; // This exits the loop and ends the program
        } else if (choice == 4) {
            cout << "Which one do you want to reverse?" << endl;
            cout << "1. Meters/Feet" << endl;
            cout << "2. Kilograms/Pounds" << endl;
            cout << "3. Celsius/Fahrenheit" << endl;
            cout << "Enter your reverse choice: ";
            cin >> reverseChoice;
            continueReversed = true; // Here I assume the user wants to use the reversed version
            cout << "Conversion direction reversed for option " << reverseChoice << "!" << endl;
            continue; // Goes back to menu
        }

        cout << "Enter value to convert: ";
        cin >> value;

        // I used if statements to check what conversion to do
        if (choice == 1) {
            if (reverseChoice == 1 && continueReversed)
                cout << value << " feet is " << feetToMeters(value) << " meters." << endl;
            else
                cout << value << " meters is " << metersToFeet(value) << " feet." << endl;
        } else if (choice == 2) {
            if (reverseChoice == 2 && continueReversed)
                cout << value << " lb is " << poundsToKilograms(value) << " kg." << endl;
            else
                cout << value << " kg is " << kilogramsToPounds(value) << " lb." << endl;
        } else if (choice == 3) {
            if (reverseChoice == 3 && continueReversed)
                cout << value << " Fahrenheit is " << fahrenheitToCelsius(value) << " Celsius." << endl;
            else
                cout << value << " Celsius is " << celsiusToFahrenheit(value) << " Fahrenheit." << endl;
        } else {
            cout << "Invalid choice, try again." << endl;
            continue;
        }

        // Here I ask the user if they want to continue with reversed mode or reset
        if (reverseChoice == choice && continueReversed) {
            char userAnswer;
            cout << "Do you want to continue using the reversed conversion? (y/n): ";
            cin >> userAnswer;
            if (userAnswer == 'n' || userAnswer == 'N') {
                continueReversed = false;
                reverseChoice = 0; // reset everything back to normal mode
                cout << "Reverted back to original conversion mode." << endl;
            }
        }
    }

    cout << "Thanks for using the Unit Converter!" << endl;
    return 0;
}
