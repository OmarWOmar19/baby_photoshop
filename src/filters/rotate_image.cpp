#include "../../include/filters/rotate_image.h"
#include "../../include/core/validation.h"
#include "../../include/ui/output.h"

void show_rotate_image_menu() {

    cout << "========================================================\n";
    cout << "\tRotate Image\n";
    cout << "========================================================\n";
    cout << " - 90" << endl;
    cout << " - 180" << endl;
    cout << " - 270" << endl;
    cout << "========================================================\n";

}

void rotate_image(Image& current_image) {

    show_rotate_image_menu();

    short angle = read_number("Enter an angle: ");

    if (angle == 0 || angle == 360) {
        return; 
    }

    int old_width = current_image.width;
    int old_height = current_image.height;

    Image target_image = current_image; 

    if (angle == 90 || angle == 270) {
        target_image.width = old_height;
        target_image.height = old_width;
    }

    for (int i = 0; i < old_width; i++) {
        for (int j = 0; j < old_height; j++) {

            int target_i = 0;
            int target_j = 0;

            switch (angle) {
                case 90: 
                    target_i = old_height - 1 - j;
                    target_j = i;
                    break;
                case 180: 
                    target_i = old_width - 1 - i;
                    target_j = old_height - 1 - j;
                    break;
                case 270: 
                    target_i = j;
                    target_j = old_width - 1 - i;
                    break;
                default:
                    return;
            }

            for (int k = 0; k < 3; k++) {
                target_image(target_i, target_j, k) = current_image(i, j, k);
            }
        }
    }

    current_image = target_image;

    successful_filter_message();

}