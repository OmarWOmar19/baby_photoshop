#include "../../include/filters/natural_sunlight.h"

void natural_sunlight(Image& current_image) {

    for (int i = 0; i < current_image.width; i++) {
        for (int j = 0; j < current_image.height; j++) {
            for (int k = 0; k < 3; k++) {

                int calculated_value = current_image(i, j, k);

                switch (k) {
                    case 0:
                        calculated_value += 20;
                        break;
                    case 1:
                        calculated_value += 15;
                        break;
                    case 2:
                        calculated_value -= 10;
                }

                if (calculated_value > 255) { calculated_value = 255; }
                if (calculated_value < 0) { calculated_value = 0; }

                current_image(i, j, k) = calculated_value;

            }
        }
    }

    cout << "Filter has successfully been applied!!!\n";

}