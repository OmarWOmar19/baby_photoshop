#include "../../include/ui/output.h"
#include <iostream>

using namespace std;

void successful_filter_message() {

    system("cls");
    cout << "Filter has successfully been applied!!!\n";

}

void show_error_message(const string& message) {
    cout << "\n" << "\a" << "\033[31m" << message << "\033[0m" << "\n";
}