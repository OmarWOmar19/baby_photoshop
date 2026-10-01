#include "../../include/filters/crop_image.h"
#include "../../defs/defs.h"
#include "../../include/ui/output.h"

#include <iostream>

using namespace std;

Point read_starting_point(const int max_width, const int max_height) {

    Point starting_point;

    do {

        cout << " Starting Point (x, y):\n";

        starting_point.read_x();
        starting_point.read_y();

        if ((starting_point.x >= max_width) || (starting_point.y >= max_height)) {
            cout << "\nError: Starting point is out of range!!!\n";
        }

    } while ((starting_point.x >= max_width) || (starting_point.y >= max_height));

    return starting_point;

}

Point read_ending_point(const int max_width, const int max_height) {

    Point ending_point;

    do {

        cout << " Destination Point (x, y):\n";

        ending_point.read_x();
        ending_point.read_y();

        if ((ending_point.x >= max_width) || (ending_point.y >= max_height)) {
            cout << "\nError: Starting point is out of range!!!\n";
        }

    } while ((ending_point.x >= max_width) || (ending_point.y >= max_height));

    return ending_point;

}


void crop_image(Image &current_image) {

    cout << "========================================================\n";
    cout << "\t\t\tCrop Image\n";
    cout << "========================================================\n";

    Point starting_point = read_starting_point(current_image.width, current_image.height);
    Point ending_point = read_ending_point(current_image.width, current_image.height);

    Image resulted_image(ending_point.x - starting_point.x, ending_point.y - starting_point.y);

    // Crop process
    for (int i = starting_point.x; i < ending_point.x; i++) {
        for (int j = starting_point.y; j < ending_point.y; j++) {
            for (int k = 0; k < 3; k++) {    
                resulted_image(i - starting_point.x, j - starting_point.y, k) = current_image(i, j, k);
            }
        }
    }

    current_image = resulted_image; // Update the current image to be the croped image

    successful_filter_message();

}
