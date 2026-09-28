#include <iostream>
#include <string>
#include <exception>
#include <vector>

#include "../../include/ui/menu.h"
#include "../../include/core/file-manager.h"
#include "../../include/core/image-manager.h"

#include "../filters/filters_unity.cpp"

using namespace std;

vector <string> v_supported_extentions = { ".jpg", ".bmp", ".jpeg", ".png" };
bool is_image_saved = false, is_image_loaded = false;

void show_save_image_menu(Image& current_image) {

    // Check if there isn't an uploaded image
    if (is_image_loaded == false) {
        cout << "Error: Image isn't loaded!!!\n";
        return;
    }

    cout << "=============================\n";
    cout << "\tSave Image\n";
    cout << "=============================\n";

    string image_name = read_image_name();
    string image_extension = read_image_extension();
    string image_path = read_image_path();

    if (save_image(current_image, image_name, image_extension, image_path)) {
        is_image_saved = true;
        cout << "Image has successfully been saved!!!\n";
    } else {
        is_image_saved = false;
        cout << "Error: Image hasn't been saved!!!\n";
    }

}

void perform_apply_filter_menu_choice(en_filters_menu choice, Image& current_image) {

    switch (choice) {

        case en_filters_menu::INVERT_IMAGE:
            system("cls");
            invert_image(current_image);
            system("pause");
            break;

        case en_filters_menu::DARKEN_AND_LIGHTEN:
            system("cls");
            darken_and_lighten(current_image);
            system("pause");
            break;

        case en_filters_menu::CROP_IMAGE:
            system("cls");
            crop_image(current_image);
            system("pause");
            break;

        case en_filters_menu::GRAYSCALE:
            system("cls");
            grayscale(current_image);
            system("pause");
            break;

        case en_filters_menu::BLACK_AND_WHITE:
            system("cls");
            black_and_white(current_image);
            system("pause");
            break;

        case en_filters_menu::NIGHT_PURPLE:
            system("cls");
            night_purple(current_image);
            system("pause");
            break;

        case en_filters_menu::NATURAL_SUNLIGHT:
            system("cls");
            natural_sunlight(current_image);
            system("pause");
            break;

        case en_filters_menu::OLD_DEN_DEN_MUSHI:
            system("cls");
            old_den_den_mushi(current_image);
            system("pause");
            break;

        default:
            ;

    }

}

void show_apply_filter_menu(Image& current_image) {

    // Check if there isn't an uploaded image
    if (is_image_loaded == false) {
        cout << "Error: Image isn't loaded!!!\n";
        return;
    }

    short choice = 1;

    do {

        cout << "=============================\n";
        cout << "\tApply filter\n";
        cout << "=============================\n";

        cout << " [1] Grayscale conversion" << "\n";
        cout << " [2] Black and White" << "\n";
        cout << " [3] Invert image" << "\n";
        cout << " [4] Adding frame" << "\n"; 
        cout << " [5] Flip image" << "\n";
        cout << " [6] Rotate image" << "\n"; 
        cout << " [7] Darken and Lighten image" << "\n"; // 
        cout << " [8] Resizing image" << "\n";
        cout << " [9] Merge two images" << "\n";
        cout << " [10] Detect image edges" << "\n";
        cout << " [11] Crop image" << "\n"; // 
        cout << " [12] Blur image" << "\n";
        cout << " [13] Natural Sunlight" << "\n";
        cout << " [14] Old Den Den Mushi" << "\n";
        cout << " [15] Night Purple" << "\n"; // 
        cout << " [16] Infrared" << "\n";
        cout << " [17] Image Skewing" << "\n";
        cout << " [18] Oil Painting" << "\n";
        cout << " [19] Exit" << "\n";

        cout << "=============================\n";

        cout << "Enter a choice: ";
        cin >> choice;

        perform_apply_filter_menu_choice((en_filters_menu)choice, current_image);

    } while (choice != (int)en_filters_menu::EXIT);

}

void show_load_image_screen(Image& current_image) {

    // Check if there is an unsaved image. Then, ask user to save it or not 
    if (is_image_loaded == true && is_image_saved == false) {

        char save_confirm = 'Y';

        cout << "You already have an unsaved image. Do you want to save it? [Y/N] ";
        cin >> save_confirm;

        if (save_confirm == 'y' || save_confirm == 'Y') {

            if (save_image(current_image, read_image_name(), read_image_extension(), read_image_path())) {
                is_image_saved = true;
                cout << "Image has successfully been saved!!!\n";
            } else {
                is_image_saved = false;
                cout << "Error: Image hasn't been saved!!!\n";
            }

        }

        system("pause");

    }

    system("cls");

    cout << "=============================\n";
    cout << "\tLoad Image\n";
    cout << "=============================\n";

    string image_path = read_image_path();

    if (load_image(image_path, current_image)) {
        is_image_loaded = true;
        cout << "Image has successfully been loaded!!!\n";
    } else {
        is_image_loaded = false;
    }

}

void perform_main_menu_choice(en_main_menu choice, Image& current_image) {

    switch (choice) {

        case en_main_menu::LOAD_IMG:
            system("cls");
            show_load_image_screen(current_image);
            system("pause");
            break;

        case en_main_menu::APPLY_FILTER:
            system("cls");
            show_apply_filter_menu(current_image);
            break;

        case en_main_menu::SAVE_IMG:  
            system("cls");
            show_save_image_menu(current_image);
            system("pause");
            break;

        default: 
            break;

    }   

}

void show_main_menu() {

    Image current_image;
    short choice = 0;

    do {

        // Clear screen after every time you get back to main menu
        system("cls"); 

        cout << "=============================\n";
        cout << "\tBaby Photoshop\n";
        cout << "=============================\n";

        cout << " [1] Load Image" << endl;
        cout << " [2] Apply Filter" << endl;
        cout << " [3] Save Image" << endl;
        cout << " [4] Exit" << endl;

        cout << "=============================\n";

        // Read user choice for main menu
        cout << "Enter a choice: ";
        cin >> choice;

        perform_main_menu_choice((en_main_menu)choice, current_image);

    } while (choice != (int)en_main_menu::EXIT);

}