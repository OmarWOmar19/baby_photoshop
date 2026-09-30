#include "../../include/filters/invert_image.h"
#include "../../include/ui/output.h"

#include <iostream>

using namespace std;

void invert_image(Image& current_image) {

    for (int i = 0; i < current_image.width; i++) {
        for (int j = 0; j < current_image.height; j++) {
            for (int k = 0; k < 3; k++) {
                current_image(i, j, k) = 255 - current_image(i, j, k);
            }
        }
    }

    successful_filter_message();

}