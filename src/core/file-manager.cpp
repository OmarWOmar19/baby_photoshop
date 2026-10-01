#include <filesystem>
#include <iostream>
#include <string>
#include <fstream>

#include "../../include/core/file-manager.h"

string read_image_name() {

    string image_name = "";

    cout << "Image Name: ";
    getline(cin >> ws, image_name);

    return image_name;

}

string read_image_extension() {

    string image_extension = "";

    cout << "Image Extension: ";
    getline(cin >> ws, image_extension);

    return image_extension;

}

string read_image_path() {

    string image_path = "";

    cout << "Image Path: ";
    getline(cin >> ws, image_path);

    return image_path;

}