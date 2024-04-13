#include "Image_Class.h"
#include <iostream>


using namespace std;
void resizeImage(Image& image, int newWidth, int newHeight) {
    Image resizedImage(newWidth, newHeight);
    for (int i = 0; i < newHeight; i++) {
        for (int j = 0; j < newWidth; j++) {
            for (int k = 0; k < image.channels; k++) {
                resizedImage(j, i, k) = image(j * image.width / newWidth, i * image.height / newHeight, k);
            }
        }
    }
    image = resizedImage;
}
int main() {
    Image image1("luffy.bmp");

    cout << "Choose your rotation degree:\n1-90\n2-180\n3-270\n";
    tow:
    int n;
    cin >> n;
    if(n==1) {
        int newWidth = image1.height;
        int newHeight = image1.width;


        Image rotatedImage(image1.width, image1.height);
        resizeImage(image1, newWidth, newHeight);

        for (int i = 0; i < newHeight; i++) {
            for (int j = 0; j < newWidth; j++) {
                for (int k = 0; k < image1.channels; k++) {
                    rotatedImage(i, j, k) = image1(j, newHeight - 1 - i, k);
                }
            }
        }

        resizeImage(rotatedImage, image1.width, image1.height);
        rotatedImage.saveImage("rotated_luffy.bmp");
        return 0;
    }
    else if (n==2){
        for (int i = 0; i < image1.width/2; i++) {
            for (int j = 0; j < image1.height; j++) {
                for(int k=0;k<image1.channels;k++) {
                    pixel temp = image1(i, j, k);
                    image1(i, j, k) = image1(image1.width - i - 1, j, k);
                    image1(image1.width - i - 1,j , k) = temp;
                }
            }
        }
        for (int i = 0; i < image1.width; i++) {
            for (int j = 0; j < image1.height / 2; j++) {
                for (int k = 0; k < image1.channels; k++) {
                    pixel temp = image1(i, j, k);
                    image1(i, j, k) = image1(i, image1.height - j - 1, k);
                    image1(i, image1.height - j - 1, k) = temp;
                }
            }
        }
    }
    else if (n==3) {
        int newWidth = image1.height;
        int newHeight = image1.width;


        Image rotatedImage(image1.width, image1.height);
        resizeImage(image1, newWidth, newHeight);

        for (int i = 0; i < newHeight; i++) {
            for (int j = 0; j < newWidth; j++) {
                for (int k = 0; k < image1.channels; k++) {
                    rotatedImage( i , j, k) = image1(j, i, k);
                }
            }
        }

        resizeImage(rotatedImage, image1.width, image1.height);
        rotatedImage.saveImage("rotated_luffy.bmp");
        return 0;
    }
    else {
        cout << "Error!\nplease enter with right way\n";
        goto tow;
    }

     image1.saveImage("rotated_luffy.bmp");

    return 0;
}