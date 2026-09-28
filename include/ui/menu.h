#pragma once

#include "../../defs/defs.h"
#include "../../lib/Image_Class.h"

void show_apply_filter_menu();
void show_save_image_menu(Image& image);
void show_load_image_screen(Image &image);
void perform_main_menu_choice(en_main_menu choice, Image& image);

void show_main_menu();