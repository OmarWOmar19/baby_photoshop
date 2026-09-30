#include "../../include/filters/crop_image.h"
#include "../../defs/defs.h"
#include "../../include/ui/output.h"

#include <iostream>

using namespace std;

Point read_starting_point() {

    Point starting_point;

    cout << " Starting Point (x, y):\n";

    cout << " --> x: ";
    starting_point.read_x();

    cout << " --> y: ";
    starting_point.read_y();

    return starting_point;

}

Point read_ending_point() {

    Point ending_point;

    cout << " Dimensions (x, y):\n";

    cout << " --> x: ";
    ending_point.read_x();

    cout << " --> y: ";
    ending_point.read_y();

    return ending_point;

}

void crop_image(Image &current_image) {

    Point starting_point = read_starting_point(), ending_point = read_ending_point();

    cout << "========================================================\n";
    cout << "\t\t\tCrop Image\n";
    cout << "========================================================\n";

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