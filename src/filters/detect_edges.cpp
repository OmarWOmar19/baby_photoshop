#include "../../include/filters/detect_edges.h"
#include "../../include/ui/output.h"

void detect_image_edges(Image& current_image) {

    Image copy_image = current_image;
    int threshold = 2;

    for (int i = 0; i < current_image.width - 1; i++) {
        for (int j = 0; j < current_image.height - 1; j++) {
            int current_gray = (copy_image(i, j, 0) + copy_image(i, j, 1) + copy_image(i, j, 2)) / 3;
            int right_gray = (copy_image(i + 1, j, 0) + copy_image(i + 1, j, 1) + copy_image(i + 1, j, 2)) / 3;
            int bottom_gray = (copy_image(i, j + 1, 0) + copy_image(i, j + 1, 1) + copy_image(i, j + 1, 2)) / 3;

            int diff = int(current_gray - right_gray) + int(current_gray - bottom_gray);
            int edge_color = (diff > threshold) ? 0 : 255;

            current_image(i, j, 0) = edge_color;
            current_image(i, j, 1) = edge_color;
            current_image(i, j, 2) = edge_color;
        }
    }

    successful_filter_message();

}
