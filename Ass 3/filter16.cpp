#include <iostream>
#include <string>
#include "Image_Class.h"

using namespace std;

int main() {
    string filename;
    cout << "Please enter the image name to apply the effect: ";
    cin >> filename;

    Image image1(filename);


    for (int x = 1; x < image1.width - 1; x++) {
        for (int y = 1; y < image1.height - 1; y++) {
            // Reduce the intensity of the green color
            int green = image1(x, y, 1);
            green *= 0.7;
            image1(x, y, 1) = green;
        }
    }

    cout << "Please enter the image name to store the new image\n";
    cout << "and specify the extension (.jpg, .bmp, .png, .tga): ";
    cin >> filename;

    image1.saveImage(filename);

    return 0;
}