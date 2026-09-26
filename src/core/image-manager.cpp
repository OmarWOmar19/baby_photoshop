#include "../../include/core/image-manager.h"

#include <exception>
#include <filesystem>

using namespace filesystem;

bool load_image(const string &image_path, Image& current_image) {

    try {

        current_image.loadNewImage(image_path);
        return true;

    } catch (exception const& e) {
        cout << "Error: " << e.what() << endl;
    }

    return false;

}

bool save_image(Image& current_image, const string& image_name, const string& image_extention, const string& image_path) {

    try {

        current_image.saveImage(image_path + image_name + image_extention);
        return true;

    } catch (exception const& e) {
        cout << "Error: " << e.what() << endl;
    }

    return false;

}