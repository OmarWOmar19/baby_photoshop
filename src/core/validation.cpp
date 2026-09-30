#include <iostream>
#include <limits>

#include "../../include/core/validation.h"

using namespace std;

int read_number(const string& prompt) {

    int number = 0;

    cout << prompt;
    cin >> number;

    while (cin.fail()) {

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\nError: Invalied input!!!";
        cout << "\nPlease Enter a numeric value!!!\n";

        cout << endl;

        cout << prompt;
        cin >> number;

    }

    return number;

}

int read_choice(const string& prompt, const string& error_message, int from, int to) {

    short choice = 0;

    do {

        choice = read_number(prompt);

        if (!(choice >= from && choice <= to)) {
            cout << error_message << endl;
        }

    } while (!(choice >= from && choice <= to));

    return choice;

}