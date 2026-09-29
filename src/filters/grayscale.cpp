#include "../../include/filters/grayscale.h"

void grayscale(Image& current_image) {

    for (int i = 0; i < current_image.width; i++) {
        for (int j = 0; j < current_image.height; j++) {

            int average = 0;

            for (int k = 0; k < 3; k++) {
                average += current_image(i, j, k);
            }

            average = average / 3;

            for (int l = 0; l < 3; l++) {
                current_image(i, j, l) = average;
            }

        }
    }

    cout << "Filter has successfully been applied!!!\n";

}