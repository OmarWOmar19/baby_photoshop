#include <filesystem>
#include <iostream>
#include <string>
#include <fstream>

#include "../../include/core/file-manager.h"

string read_image_name() {

    string image_name = "";

    cout << "Image name: ";
    getline(cin >> ws, image_name);

    return image_name;

}

string read_image_extension() {

    string image_extention = "";

    cout << "Image Extention: ";
    getline(cin >> ws, image_extention);

    return image_extention;

}

string read_image_path() {

    string image_path = "";

    cout << "Image Path: ";
    getline(cin >> ws, image_path);

    return image_path;

}