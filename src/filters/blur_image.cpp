#include "../../include/filters/blur_image.h"
#include <iostream>
#include <string>

using namespace std;

void horizontal_blur(Image& current_image, int radius) {

    for (int j = 0; j < current_image.height; j++) {
        for (int i = 0; i < current_image.width; i++) {
            int sumR = 0, sumG = 0, sumB = 0;
            int count = 0;
            
            for (int k= -radius; k <= radius; k++){
                int x = i + k;
                if (x >= 0 && x < current_image.width) {
                    sumR += current_image(x, j, 0);
                    sumG += current_image(x, j, 1);
                    sumB += current_image(x, j, 2);
                    count++;
                }
            }
            current_image(i, j, 0) = sumR / count;
            current_image(i, j, 1) = sumG / count;
            current_image(i, j, 2) = sumB / count;
        }
    }

}

void vertical_blur(Image& current_image, int radius) {

    for (int j = 0; j < current_image.height; j++) {
        for (int i = 0; i < current_image.width; i++) {
            int sumR = 0, sumG = 0, sumB = 0;
            int count = 0;
            
            for (int l= -radius; l <= radius; l++){
                int y = j + l;
                if (y >= 0 && y < current_image.height) {
                    sumR += current_image(i, y, 0);
                    sumG += current_image(i, y, 1);
                    sumB += current_image(i, y, 2);
                    count++;
                }
            }
            current_image(i, j, 0) = sumR / count;
            current_image(i, j, 1) = sumG / count;
            current_image(i, j, 2) = sumB / count;
        }
    }

}

void blur_image(Image& current_image) {

    int radius = 0;

    cout << "Enter blur radius: ";
    cin >> radius;

    vertical_blur(current_image, radius);
    horizontal_blur(current_image, radius);

}