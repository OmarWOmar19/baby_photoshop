#include "../../include/filters/infrared.h"
#include <iostream>

using namespace std;

void infrared(Image& current_image){
    for (int i = 0; i < current_image.width; i++) {
        for (int j = 0; j < current_image.height; j++) {
            int r = current_image(i, j, 0);
            int g = current_image(i, j, 1);
            int b = current_image(i, j, 2);
            
            int avg = (r + g + b) / 3;
            current_image(i, j, 0) = 255;
            current_image(i, j, 1) = 255 - avg;
            current_image(i, j, 2) = 255 - avg;
        }
    }
}