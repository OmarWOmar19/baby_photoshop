#include "../../include/filters/resizing_image.h"
#include <iostream>

using namespace std;

void resize_image(Image& current_image, int new_width, int new_height) {

    Image new_image(new_width, new_height);

    float scale_x = (float)current_image.width / new_width;
    float scale_y = (float)current_image.height / new_height;

    for (int i = 0; i < new_width; ++i) {
        for (int j = 0; j < new_height; ++j) {

            int old_x = i * scale_x;
            int old_y = j * scale_y;

            for (int k = 0; k < 3; ++k) {
                new_image(i, j, k) = current_image(old_x, old_y, k);
            }
        }
    }

}

void show_resize_image_menu(Image& current_image) {

    int new_width = 0, new_height = 0;

    cout << "========================================================\n";
    cout << "\t\t\tResize Image\n";
    cout << "========================================================\n";

    cout << " --> New Width: " << endl;
    cin >> new_width;

    cout << " --> New Height: " << endl;
    cin >> new_height;

    resize_image(current_image, new_width, new_height);

}