#include "Image_Class.h"
#include <iostream>
#include <string>

using namespace std;

void applyRotate(Image& image) {
    cout << "Choose rotation angle:\n";
    cout << "1. 90 degrees clockwise\n";
    cout << "2. 180 degrees clockwise\n";
    cout << "3. 270 degrees clockwise\n";
    int choice;
    cin >> choice;

    // Get image dimensions
    int width = image.getWidth();
    int height = image.getHeight();

    // Create temporary image buffer
    unsigned char* tempBuffer = new unsigned char[width * height * 3];

    if (choice == 1) {
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {

                unsigned char* srcPixel = image.getPixel(x, y);
                unsigned char* destPixel = tempBuffer + ((width - x - 1) * height + y) * 3;
                destPixel[0] = srcPixel[0]; // Red
                destPixel[1] = srcPixel[1]; // Green
                destPixel[2] = srcPixel[2]; // Blue
            }
        }
        // Update image dimensions
        image.setWidth(height);
        image.setHeight(width);
    } else if (choice == 2) {
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {

                unsigned char* srcPixel = image.getPixel(x, y);
                unsigned char* destPixel = tempBuffer + ((width - x - 1) + (height - y - 1) * width) * 3;
                destPixel[0] = srcPixel[0];
                destPixel[1] = srcPixel[1];
                destPixel[2] = srcPixel[2];
            }
        }
    } else if (choice == 3) {
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {

                unsigned char* srcPixel = image.getPixel(x, y);
                unsigned char* destPixel = tempBuffer + (x * height + (height - y - 1)) * 3;
                destPixel[0] = srcPixel[0];
                destPixel[1] = srcPixel[1];
                destPixel[2] = srcPixel[2];
            }
        }
        // Update image dimensions
        image.setWidth(height);
        image.setHeight(width);
    } else {
        cout << "Invalid choice. No rotation applied.\n";
        delete[] tempBuffer;
        return;
    }

    // Copy rotated image data back to the original image
     memcpy(image.getData(), tempBuffer, width * height * 3);

    delete[] tempBuffer;
}
