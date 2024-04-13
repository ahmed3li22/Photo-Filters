#include <iostream>
#include <string>
#include "Image_Class.h"

using namespace std;

void resizeImage(Image& image, int newWidth, int newHeight) {
    Image resizedImage(newWidth, newHeight);
    for (int i = 0; i < newHeight; i++) {
        for (int j = 0; j < newWidth; j++) {
            for (int k = 0; k < image.channels; k++) {
                int original_i = i * image.height / newHeight;
                int original_j = j * image.width / newWidth;
                resizedImage(j, i, k) = image(original_j, original_i, k);
            }
        }
    }
    image = resizedImage;
}

int main() {
    string filename;
    cout << "Please enter the image name to apply the effect: ";
    cin >> filename;

    Image image(filename);


    int originalWidth = image.width;
    int originalHeight = image.height;

    int frameColor;
    cout << "Please enter the color of the frame (0-255): ";
    cin >> frameColor;
    int frameSize;
    cout << "Please enter the size of the frame (in pixels): ";
    cin >> frameSize;


    resizeImage(image, image.width, image.height);


    for (int i = 0; i < image.height; i++) {
        for (int j = 0; j < image.width; j++) {
            for (int k = 0; k < image.channels; k++) {

                if (i < frameSize || i >= image.height - frameSize || j < frameSize || j >= image.width - frameSize) {
                    if ((i + j) % 20 < 10) {
                        image(j, i, k) = frameColor;
                    }
                }
            }
        }
    }

    resizeImage(image, originalWidth, originalHeight);

    cout << "Please enter the image name to store the new image\n";
    cout << "and specify the extension (.jpg, .bmp, .png, .tga): ";
    cin >> filename;

    image.saveImage(filename);

    return 0;
}
