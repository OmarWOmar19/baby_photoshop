#include <iostream>
#include "../../include/filters/black_and_white.h"

using namespace std;

void black_and_white(Image& current_image) {

    for (int i = 0; i < current_image.width; i++) {
        for (int j = 0; j < current_image.height; j++) {

            int average = 0;

            for (int k = 0; k < 3; k++) {
                average += current_image(i, j, k);
            }

            average = average / 3;

            for (int l = 0; l < 3; l++) {
                if (average >= 128) {
                    current_image(i, j, l) = 255;
                } else {
                    current_image(i, j, l) = 0;
                }
            }

        }
    }

    cout << "Filter has successfully been applied!!!\n";

}