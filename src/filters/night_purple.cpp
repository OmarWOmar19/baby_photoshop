#include "../../include/filters/night_purple.h"
#include <iostream>

using namespace std;

void night_purple(Image& current_image) {

    for (int i = 0; i < current_image.width; i++) {
        for (int j = 0; j < current_image.height; j++) {
            for (int k = 0; k < 3; k++) {

                int calculated_value = current_image(i, j, k);

                switch (k) {
                    case 0:
                        calculated_value += 10;
                        break;
                    case 1:
                        calculated_value -= 30;
                        break;
                    case 2:
                        calculated_value += 25;
                }

                if (calculated_value > 255) { calculated_value = 255; }
                if (calculated_value < 0) { calculated_value = 0; }

                current_image(i, j, k) = calculated_value;

            }
        }
    }

    cout << "Filter has successfully been applied!!!\n";

}