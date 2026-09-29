#include "../../include/filters/merge_images.h"
#include "../../include/core/image-manager.h"
#include "../../include/core/file-manager.h"
#include "../../include/filters/resizing_image.h"

#include <algorithm>

void merge_images(Image& current_image) {

    Image new_image;
    string new_image_path = read_image_path();

    // Load Second Image
    if (load_image(new_image_path, new_image)) {
        system("cls");
        cout << "Successful Operation!!!\n";
        system("pause");
    }

    // Check if images have the same dimensions or not
    if (current_image.width != new_image.width || current_image.height != new_image.height) {
        int target_width = max(current_image.width, new_image.width);
        int target_height = max(current_image.height, new_image.height);

        if (current_image.width < target_width || current_image.height < target_height) {
            resize_image(current_image, target_width, target_height);
        }
        if (new_image.width < target_width || new_image.height < target_height) {
            resize_image(new_image, target_width, target_height);
        }
    }

    // merge two images operation

    double blending_percentage = 50.0;

    cout << "Blending Percentage [ 1% -> 100% ]: ";
    cin >> blending_percentage;

    if (blending_percentage < 0.0)  blending_percentage = 0.0;
    if (blending_percentage > 100.0) blending_percentage = 100.0;
    
    double alpha = blending_percentage / 100.0;
    double beta = 1.0 - alpha;

    for (int i = 0; i < current_image.width; i++) {
        for (int j = 0; j < current_image.height; j++) {
            for (int k = 0; k < 3; k++) {
                
                int val1 = current_image(i, j, k);
                int val2 = 0;

                if (i < new_image.width && j < new_image.height) {
                    val2 = new_image(i, j, k);
                } else {
                    val2 = val1; 
                }

                // Blending Equation
                int blended_val = int((val1 * alpha) + (val2 * beta));

                if (blended_val > 255) blended_val = 255;
                if (blended_val < 0)   blended_val = 0;

                current_image(i, j, k) = blended_val;

            }
        }
    }

    cout << "Filter has successfully been applied!!!\n";

}