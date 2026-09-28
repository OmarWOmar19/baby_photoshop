#include <iostream>
#include "../../include/filters/darken_and_lighten.h"

using namespace std;

void show_darken_and_lighten_menu() {

    cout << "========================================================\n";
    cout << "\t\t\tDarken and Lighten\n";
    cout << "========================================================\n";
    cout << " [1] Darken" << endl;
    cout << " [2] Lighten" << endl;
    cout << "========================================================\n";

}

void darken_and_lighten(Image& current_image) {

    show_darken_and_lighten_menu();

    short choice = 1;
    short brightness_percentage = 0;

    cout << "Enter a choice: ";
    cin >> choice;

    switch (choice) {

        case 1:
            cout << "Dark percentage %: ";
            cin >> brightness_percentage;
            brightness_percentage = -brightness_percentage;
            break;

        case 2:
            cout << "Light percentage %: ";
            cin >> brightness_percentage;
            break;

        default:
            ;

    }

    for (int i = 0; i < current_image.width; i++) {
        for (int j = 0; j < current_image.height; j++) {
            for (int k = 0; k < 3; k++) {

                int calculated_value = current_image(i, j, k) * (1 + float(brightness_percentage) / 100);

                if (calculated_value > 255) {
                    calculated_value = 255;
                }

                if (calculated_value < 0) {
                    calculated_value = 0;
                }

                current_image(i, j, k) = calculated_value;
    
            }
        }
    }

    cout << "Filter has successfully been applied!!!\n";

}