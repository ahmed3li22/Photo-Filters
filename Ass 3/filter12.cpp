#include <iostream>
#include <string>
#include "Image_Class.h"

using namespace std;

int main() {
    string filename;
    cout << "Please enter the image name to apply the effect: ";
    cin >> filename;

    Image image1(filename);

    Image blurredImage(image1.width, image1.height);


    int numIterations = 10;

    for (int iteration = 0; iteration < numIterations; iteration++) {
        for (int x = 2; x < image1.width - 2; x++) {
            for (int y = 2; y < image1.height - 2; y++) {
                for (int z = 0; z < image1.channels; z++) {
                    int sum = 0;
                    for (int i = -2; i <= 2; i++) {
                        for (int j = -2; j <= 2; j++) {
                            sum += image1(x + i, y + j, z);
                        }
                    }
                    int blurredValue = sum / 25;
                    blurredImage(x, y, z) = blurredValue;
                }
            }
        }

        image1 = blurredImage;
    }

    cout << "Please enter the image name to store the new image\n";
    cout << "and specify the extension (.jpg, .bmp, .png, .tga): ";
    cin >> filename;

    blurredImage.saveImage(filename);

    return 0;
}