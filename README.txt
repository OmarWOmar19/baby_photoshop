// ============================================================================
//  File        :  CS213_A1_Part1_S11&S12_20250114_20250315_20250444_20250503.cpp
//  Course      :  CS213 - Assignment 1 (Part 2 - 16 filters)
//  Description :
//  ----------------------------------------------------------------------------
//  Baby Photoshop is a console application (no GUI) for basic image editing.
//  It relies on the provided "Image_Class.h" library to read, modify and write
//  images, and everything the user does is driven by text menus.
//
//  How the program works:
//    1. Main menu    : Load Image / Apply Filter / Save Image / Exit.
//    2. Load Image   : User enters an image path; the image is loaded into
//                      memory. If an unsaved image is already loaded, the
//                      program asks whether to save it first.
//    3. Apply Filter : the user chooses one of the filters below. Several
//                      filters ask for extra input (e.g. blur radius, crop
//                      points, rotation angle, frame size). Filters can be
//                      applied one after another on the same image.
//    4. Save Image   : the user enters a file name, extension and path to
//                      save the edited image.
//
//  Available filters (menu options 1-16):
//    Grayscale, Black and White, Invert Image, Adding Frame (simple /
//    decorative), Flip Image (horizontal / vertical), Rotate Image,
//    Darken & Lighten, Resizing Image, Merge Two Images, Detect Image Edges,
//    Crop Image, Blur Image, Natural Sunlight, Old Den Den Mushi,
//    Night Purple, Infrared.
//    (Image Skewing and Oil Painting appear in the menu but are not available
//    yet.)
//
//  File organization:
//    - defs        : enums for the main and filter menus, and a Point class
//                    used to read coordinates (for crop image filter).
//    - filters     : one section per filter, each with its own helper
//                    functions and a main function that takes the image by
//                    reference and modifies it.
//    - Validation  : read_number() and read_choice() keep reading until the
//                    user enters a valid number / a choice within range.
//    - Core        : reading the image name, extension and path, plus
//                    load_image() and save_image().
//    - UI          : the main menu, the filter menu, and the load / save
//                    screens that tie everything together.
//    - App / main  : starts the program by showing the main menu.
//  ----------------------------------------------------------------------------
//  Section:     section
//  ----------------------------------------------------------------------------

//  ----------------------------------------------------------------------------
//  Team Members:
//  ----------------------------------------------------------------------------
//  - Name                                   ID          Filters
//  ----------------------------------------------------------------------------
//  - Baher Yasser Ayad                      20250114    Grayscale, Flip Image,
//                                                       Merge Two Images,
//                                                       Natural Sunlight
//
//  - Seif Sabry Abd El-Salam                20250315    Black and White,
//                                                       Rotate Image,
//                                                       Detecting Image Edges,
//                                                       Old Den Den Mushi
//
//  - Omar Wael Omar Abd Al-Latief           20250444    Invert Image,
//                                                       Darken & Lighten,
//                                                       Crop Images,
//                                                       Night Purple
//
//  - Kirolos Nabil                          20250503    Adding Frame,
//                                                       Resizing Image,
//                                                       Blur Image,
//                                                       Infrared
//  ----------------------------------------------------------------------------
// ============================================================================
