#include "../../include/filters/flip_image.h"
#include <iostream>

using namespace std;

void show_flip_image_menu() {

    cout << "========================================================\n";
    cout << "\tFlip Image\n";
    cout << "========================================================\n";
    cout << " [1] Vertically" << endl;
    cout << " [2] Horizontally" << endl;
    cout << "========================================================\n";

}

void flip_vertically(Image& current_image) {

    for (int i = 0; i < current_image.width; i++) {
        for (int j = 0; j < current_image.height / 2; j++) {
            for (int k = 0; k < 3; k++) {
                
                int mirror_j = current_image.height - 1 - j;
                int temp = current_image(i, j, k);

                current_image(i, j, k) = current_image(i, mirror_j, k);
                current_image(i, mirror_j, k) = temp;

            }
        }
    }

}

void flip_horizontally(Image& current_image) {

    for (int i = 0; i < current_image.width / 2; i++) {
        for (int j = 0; j < current_image.height; j++) {
            for (int k = 0; k < 3; k++) {
                
                int mirror_i = current_image.width - 1 - i;
                int temp = current_image(i, j, k);

                current_image(i, j, k) = current_image(mirror_i, j, k);
                current_image(mirror_i, j, k) = temp;

            }
        }
    }

}

void flip_image(Image& current_image) {

    show_flip_image_menu();

    short choice = 1;

    cout << "Enter a choice: ";
    cin >> choice;

    switch (choice) {

        case 1:
            flip_vertically(current_image);
            break;

        case 2:
            flip_horizontally(current_image);
            break;

    }

    cout << "Filter has successfully been applied!!!\n";

}