#include "../../include/filters/adding_frame.h"
#include "../../include/core/validation.h"
#include "../../include/ui/output.h"

#include <iostream>

using namespace std;

void show_adding_frame_choices() {
    cout << "========================================================\n";
    cout << "\t\t\tAdding Frame\n";
    cout << "========================================================\n";
    cout << " [1] Simple Frame\n";
    cout << " [2] Decorative Frame\n";
    cout << "========================================================\n";
}

void show_frame_colors_choices() {
    cout << "========================================================\n";
    cout << "\t\t    Choose Frame Color\n";
    cout << "========================================================\n";
    cout << " [1] Blue\n";
    cout << " [2] Red\n";
    cout << " [3] Green\n";
    cout << " [4] Black\n";
    cout << " [5] Yellow\n";
    cout << " [6] Custom RGB\n";
    cout << "========================================================\n";
}

void apply_simple_frame(Image& img, int frameSize, int r, int g, int b) {
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {

            if (i < frameSize || i >= img.width - frameSize || j < frameSize || j >= img.height - frameSize) {
                img(i, j, 0) = r;
                img(i, j, 1) = g;
                img(i, j, 2) = b;
            }
        }
    }
}

void apply_decorative_frame(Image& img, int outerSize, int innerSize, int r, int g, int b) {
    int totalSize = outerSize + innerSize;

    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {

            if (i < outerSize || i >= img.width - outerSize || j < outerSize || j >= img.height - outerSize) {
                img(i, j, 0) = r;
                img(i, j, 1) = g;
                img(i, j, 2) = b;
            }
            
            else if (i < totalSize || i >= img.width - totalSize || j < totalSize || j >= img.height - totalSize) {
                img(i, j, 0) = 255;
                img(i, j, 1) = 255;
                img(i, j, 2) = 255;
            }
        }
    }
}

void adding_frame(Image& current_image) {
    show_adding_frame_choices();

    int choice = read_choice("Enter a choice: ", "Error: Invalid choice!!!\nPlease enter a valid choice [1-2]!!!\n", 1, 2);

    system("cls");

    show_frame_colors_choices();
    int color_choice = read_choice("Enter color choice: ", "Error: Invalid choice!!!\nPlease enter a valid choice [1-6]!!!\n", 1, 6);

    int r = 0, g = 100, b = 255;
    
    switch (color_choice) {
        case 1:
            r = 0; g = 100; b = 255;
            break;
        case 2:
            r = 255; g = 0; b = 0;
            break;
        case 3:
            r = 0; g = 255; b = 0;
            break;
        case 4:
            r = 0; g = 0; b = 0;
            break;
        case 5:
            r = 255; g = 255; b = 0;
            break;
        case 6:
            r = read_choice("Enter Red (0-255): ", "Invalid value! Please enter between 0 and 255.\n", 0, 255);
            g = read_choice("Enter Green (0-255): ", "Invalid value! Please enter between 0 and 255.\n", 0, 255);
            b = read_choice("Enter Blue (0-255): ", "Invalid value! Please enter between 0 and 255.\n", 0, 255);
            break;
    }

    system("cls");

    switch (choice) {
        case 1: {
            int size = read_number("Enter frame size (e.g. 15): ");
            apply_simple_frame(current_image, size, r, g, b);
            break;
        }
        
        case 2: {
            int outer = read_number("Enter outer frame size (e.g. 15): ");
            int inner = read_number("Enter inner frame size (e.g. 5): ");
            apply_decorative_frame(current_image, outer, inner, r, g, b);
            break;
        }
        
        default:
            break;
    }

    successful_filter_message();
}