#include "../../include/filters/adding_frame.h"
#include "../../include/core/validation.h"
#include "../../include/ui/output.h"

#include <iostream>

using namespace std;

void show_adding_frame_choices() {

    cout << "========================================================\n";
    cout << "\t\t\tAdding Frame\n";
    cout << "========================================================\n";
    cout << " [1] Simple Frame" << endl;
    cout << " [2] Decorative Frame" << endl;
    cout << "========================================================\n";

}

void apply_simple_frame(Image& img, int frameSize) {
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {
            
            if (i < frameSize || i >= img.width - frameSize || j < frameSize || j >= img.height - frameSize) {
                img(i, j, 0) = 0;   // Red
                img(i, j, 1) = 100; // Green
                img(i, j, 2) = 255; // Blue
            }

        }
    }
}

void apply_decorative_frame(Image& img, int outerSize, int innerSize) {

    int totalSize = outerSize + innerSize;

    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {

            if (i < outerSize || i >= img.width - outerSize || j < outerSize || j >= img.height - outerSize) {
                img(i, j, 0) = 0;   // Red
                img(i, j, 1) = 100; // Green
                img(i, j, 2) = 255; // Blue
            }
            else if (i < totalSize || i >= img.width - totalSize ||j < totalSize || j >= img.height - totalSize) {
                img(i, j, 0) = 255; // Red
                img(i, j, 1) = 255; // Green
                img(i, j, 2) = 255; // Blue
            }

        }
    }
}

void adding_frame(Image& current_image){

    show_adding_frame_choices();

    int choice = read_choice("Enter a choice: ", "\nError: Invalied choice!!!\nPlease enter a valied choice [1-2]!!!\n", 1, 2);

    system("cls");

    switch (choice) {

        case 1: {
            int size = read_number("Enter frame size (e.g. 15): ");
            apply_simple_frame(current_image, size);
            break;
        }
        
        case 2: {
            int outer = read_number("Enter outer frame size (e.g. 15): "), inner = read_number("Enter inner frame size (e.g. 5): ");
            apply_decorative_frame(current_image, outer, inner);
            break;
        }
        
        default:
            ;

    }

    successful_filter_message();

}