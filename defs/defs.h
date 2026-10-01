#pragma once

#include "..\lib\Image_Class.h"
#include "../include/core/validation.h"

using namespace std;

enum class en_main_menu { LOAD_IMG = 1, APPLY_FILTER = 2, SAVE_IMG = 3, EXIT = 4 };

enum class en_filters_menu { 

    GRAYSCALE = 1,
    BLACK_AND_WHITE = 2,
    INVERT_IMAGE = 3, 
    ADDING_FRAME = 4,
    FLIP_IMAGE = 5,
    ROTATE_IMAGE = 6,
    DARKEN_AND_LIGHTEN = 7, 
    RESIZING_IMAGE = 8,
    MERGE_IMAGES = 9,
    DETECT_EDGES = 10,
    CROP_IMAGE = 11, 
    BLUR_IMAGE = 12,
    NATURAL_SUNLIGHT = 13,
    OLD_DEN_DEN_MUSHI = 14,
    NIGHT_PURPLE = 15,
    INFRARED = 16,
    IMAGE_SKEWING = 17,
    OIL_PAINTING = 18,
    EXIT = 19,

};

class Point {

    public: 
        int x = 0, y = 0;

        void read_x() {
            x = read_number(" --> x: ");
        }

        void read_y() {
            y = read_number(" --> y: ");
        }

};