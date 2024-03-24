#include "Image_Class.h"
#include <iostream>
#include <string>

// invert filter
void applyInvert(Image& image) {
    // Get image dimensions
    int width = image.getWidth();
    int height = image.getHeight();


    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {

            unsigned char* pixel = image.getPixel(x, y);

            // Invert RGB values
            pixel[0] = 255 - pixel[0];
            pixel[1] = 255 - pixel[1];
            pixel[2] = 255 - pixel[2];
        }
    }
}

