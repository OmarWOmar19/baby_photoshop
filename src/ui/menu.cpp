#include <iostream>
#include <string>
#include <exception>
#include <vector>

#include "../../include/ui/menu.h"
#include "../../include/core/file-manager.h"
#include "../../include/core/image-manager.h"
#include "../../include/core/validation.h"

#include "../filters/filters_unity.cpp"

using namespace std;

bool is_image_saved = false;
bool is_image_loaded = false;

void show_save_image_menu(Image& current_image) {

    // Check if there isn't an uploaded image yet
    if (is_image_loaded == false) {
        cout << "Error: Image isn't loaded!!!\n";
        return;
    }

    cout << "========================================================\n";
    cout << "\t\t\tSave Image\n";
    cout << "========================================================\n";

    string image_name = read_image_name();
    string image_extension = read_image_extension();
    string image_path = read_image_path();

    if (save_image(current_image, image_name, image_extension, image_path)) {
        is_image_saved = true;
        system("cls");
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

        case en_filters_menu::FLIP_IMAGE:
            system("cls");
            flip_image(current_image);
            system("pause");
            break;

        case en_filters_menu::ROTATE_IMAGE:
            system("cls");
            rotate_image(current_image);
            system("pause");
            break;

        case en_filters_menu::MERGE_IMAGES:
            system("cls");
            merge_images(current_image);
            system("pause");
            break;

        case en_filters_menu::INFRARED:
            system("cls");
            infrared(current_image);
            system("pause");
            break;

        case en_filters_menu::BLUR_IMAGE:
            system("cls");
            blur_image(current_image);
            system("pause");
            break;

        case en_filters_menu::ADDING_FRAME:
            system("cls");
            adding_frame(current_image);
            system("pause");
            break;

        case en_filters_menu::RESIZING_IMAGE:
            system("cls");
            show_resize_image_menu(current_image);
            system("pause");
            break;

        case en_filters_menu::DETECT_EDGES:
            system("cls");
            detect_image_edges(current_image);
            system("pause");
            break;

        default:
            ;

    }

}

void show_apply_filter_menu(Image& current_image) {

    // Check if there isn't an uploaded image yet
    if (is_image_loaded == false) {
        cout << "Error: Image isn't loaded!!!\n";
        system("pause");
        return;
    }

    short choice = 1;

    do {

        system("cls");

        cout << "========================================================\n";
        cout << "\t\t\tApply filter\n";
        cout << "========================================================\n";
        cout << " [01] Grayscale conversion" << "\n";
        cout << " [02] Black and White" << "\n";
        cout << " [03] Invert image" << "\n";
        cout << " [04] Adding frame" << "\n"; 
        cout << " [05] Flip image" << "\n";
        cout << " [06] Rotate image" << "\n"; 
        cout << " [07] Darken and Lighten image" << "\n";
        cout << " [08] Resizing image" << "\n";
        cout << " [09] Merge two images" << "\n";
        cout << " [10] Detect image edges" << "\n";
        cout << " [11] Crop image" << "\n";
        cout << " [12] Blur image" << "\n";
        cout << " [13] Natural Sunlight" << "\n";
        cout << " [14] Old Den Den Mushi" << "\n";
        cout << " [15] Night Purple" << "\n"; 
        cout << " [16] Infrared" << "\n";
        cout << " [17] Image Skewing" << "\n";
        cout << " [18] Oil Painting" << "\n";
        cout << " [19] Exit" << "\n";
        cout << "========================================================\n";

        choice = read_choice("Enter a choice: ", "\nError: Invalied choice!!!\nPlease enter a valied choice [1-19]!!!\n", 1, 19);

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

            system("cls");

            string image_name = read_image_name();
            string image_path = read_image_path();
            string image_extension = read_image_extension();

            if (save_image(current_image, image_name, image_extension, image_path)) {
                is_image_saved = true;
                system("cls");
                cout << "Image has successfully been saved!!!\n";
            } else {
                is_image_saved = false;
                system("cls");
                cout << "Error: Image hasn't been saved!!!\n";
            }

        }

        system("pause");

    }

    system("cls");

    cout << "========================================================\n";
    cout << "\t\t\tLoad Image\n";
    cout << "========================================================\n";

    string image_path = read_image_path();

    if (load_image(image_path, current_image)) {
        is_image_loaded = true;
        system("cls");
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
            return;

    }   

}

void show_main_menu() {

    Image current_image;
    short choice = 0;

    do {

        // Clear screen after every time you get back to main menu
        system("cls"); 

        cout << "========================================================\n";
        cout << "\t\t\tBaby Photoshop\n";
        cout << "========================================================\n";
        cout << " [1] Load Image" << endl;
        cout << " [2] Apply Filter" << endl;
        cout << " [3] Save Image" << endl;
        cout << " [4] Exit" << endl;
        cout << "========================================================\n";

        // Read user choice for main menu
        choice = read_choice("Enter a choice: ", "\nError: Invalied choice!!!\nPlease enter a valied choice [1-4]!!!\n", 1, 4);

        perform_main_menu_choice((en_main_menu)choice, current_image);

    } while (choice != (int)en_main_menu::EXIT);

}