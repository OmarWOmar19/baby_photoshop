#pragma once

#include "../../defs/defs.h"
#include <string>

using namespace std;

bool save_image(Image &current_image, const string &image_name, const string &image_extention, const string &image_path);
bool load_image(const string &image_path, Image &current_image);