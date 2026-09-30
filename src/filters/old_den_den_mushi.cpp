#include "../../include/filters/old_den_den_mushi.h"
#include "../../include/ui/output.h"

void old_den_den_mushi(Image& current_image) {

    for (int i = 0; i < current_image.width; i++) {
        for (int j = 0; j < current_image.height; j++) {

            float scanline_factor = (j % 4 == 0) ? 0.5 : 1.0;

            for (int k = 0; k < 3; k++) {

                int calculated_value = current_image(i, j, k);

                calculated_value *= scanline_factor;

                if (calculated_value > 255) { calculated_value = 255; }
                if (calculated_value < 0) { calculated_value = 0; }

                current_image(i, j, k) = calculated_value;

            }
        }
    }

    successful_filter_message();

}