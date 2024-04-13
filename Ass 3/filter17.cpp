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

            int red = image1(x, y, 0);
            red = min(255, red + 250);
            image1(x, y, 0) = red;


            for (int z = 0; z < image1.channels; z++) {
                int intensity = image1(x, y, z);
                intensity = 255 - intensity;
                image1(x, y, z) = intensity + red;
            }
        }
    }

    cout << "Please enter the image name to store the new image\n";
    cout << "and specify the extension (.jpg, .bmp, .png, .tga): ";
    cin >> filename;

    image1.saveImage(filename);

    return 0;
}