#include "Image_Class.h"
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;
void crop_image(string image_name){
    Image image(image_name);
    int start_x,start_y,new_width,new_height;
    while(true){
        cout<<"enter where to crop from width\n";
        cin>>start_x;
        cout<<"enter where to crop from height\n";
        cin>>start_y;
        cout<<"enter the width of the image to be cropped\n";
        cin>>new_width;
        cout<<"enter the height of the image to be cropped\n";
        cin>>new_height;
        if(start_x+new_width<image.width &&start_y+new_height<image.height){
            break;
        }
        cout<<"make sure you are in the boundaries\n";
    }
    Image new_image(new_width, new_height);
    for(int i =0;i<new_width;i++){
        for(int j=0;j<new_height;j++){
            for(int k=0;k<image.channels;k++){
                new_image(i, j, k)=image(i+start_x, j+new_height,k);
            }
        }
    }
    cout << "Enter the new image name with the extension: ";
    string file;
    cin >> file;
    new_image.saveImage(file);
    cout << "Image saved as " << file << endl;
}
void resize_image(string image_name) {
    Image image(image_name);

    int original_width = image.width;
    int original_height = image.height;

    cout << "Do you want to resize by ratio or new dimensions?\n"
         << "1) Resize by ratio\n"
         << "2) Resize by new dimensions\n";
    int choice;
    cin >> choice;

    int new_width, new_height;
    if (choice == 1) {
        double ratio;
        cout << "Enter the resizing ratio: ";
        cin >> ratio;
        new_width = static_cast<int>(original_width * ratio);
        new_height = static_cast<int>(original_height * ratio);
    } else if (choice == 2) {
        cout << "Enter the new width: ";
        cin >> new_width;
        cout << "Enter the new height: ";
        cin >> new_height;
    } else {
        cout << "Invalid choice. Exiting.\n";
        return;
    }

    Image new_image(new_width, new_height);

    for (int x = 0; x < new_width; x++) {
        for (int y = 0; y < new_height; y++) {
            int src_x = static_cast<int>(round(static_cast<double>(x) / new_width * original_width));
            int src_y = static_cast<int>(round(static_cast<double>(y) / new_height * original_height));
            src_x = min(src_x, original_width - 1);
            src_y = min(src_y, original_height - 1);

            for (int k = 0; k < new_image.channels; k++) {
                new_image(x, y, k) = image(src_x, src_y, k);
            }
        }
    }

    cout << "Enter the new image name with the extension: ";
    string file;
    cin >> file;
    new_image.saveImage(file);
    cout << "Image saved as " << file << endl;
}
void horizontal_flip(string imagename) {
    Image image(imagename);
    for (int i = 0; i < image.width/2; i++) {
        for (int j = 0; j < image.height; j++) {
            for(int k=0;k<image.channels;k++) {
                pixel temp = image(i, j, k);
                image(i, j, k) = image(image.width - i - 1, j, k);
                image(image.width - i - 1,j , k) = temp;
            }
        }
    }

    cout << "Enter the new image name with the extension: ";
    string file;
    cin >> file;
    image.saveImage(file);
    cout << "Image saved as " << file << endl;
}


void vertical_flip(string imagename){
    Image image(imagename);
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height / 2; j++) {
            for(int k=0;k<image.channels;k++) {
                pixel temp = image(i, j, k);
                image(i, j, k) = image(i, image.height - j - 1, k);
                image(i, image.height - j - 1, k) = temp;
            }
        }
    }

    cout << "Enter the new image name with the extension: ";
    string file;
    cin >> file;
    image.saveImage(file);
    cout << "Image saved as " << file << endl;
}
void black_and_white(string imagename) {
    Image image(imagename);
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            int avg = 0;
            for (int k = 0; k < image.channels; k++) {
                avg += image(i, j, k);
            }
            avg /= 3;

            for (int k = 0; k < image.channels; k++) {
                if (avg > 123) {
                    image(i, j, k) = 255;
                } else {
                    image(i, j, k) = 0;
                }
            }
        }
    }

    cout << "Enter the new image name with the extension: ";
    string file;
    cin >> file;
    image.saveImage(file);
    cout << "Image saved as " << file << endl;
    system(file.c_str());
}

int main() {
    cout << "What do you want to do?" << endl;
    cout << "A) black and white\nB) flip filter\nC) resize filter\nD) crop filter\n";
    string choice;
    cin >> choice;
    if (choice == "A"||choice=="a") {
        string image_name;
        cout << "Enter the image you want to filter with extension: "<<endl;
        cin >> image_name;
        black_and_white(image_name);
    }
    else if (choice == "b"||choice=="B") {
        string image_name;
        cout << "Enter the image you want to filter with extension: "<<endl;
        cin >> image_name;
        cout<<"How do you want to flip?\n"<<"A)Flip horizontaly\n"<<"B)Flip vertically"<<endl;
        string choice2;
        cin>>choice2;
        if (choice2 == "A"||choice2=="a"){
            horizontal_flip(image_name);
        }
        else if(choice2 == "b"||choice2=="B"){
            vertical_flip(image_name);
        }
    }
    else if(choice =="c"||choice=="C"){
        string image_name;
        cout << "Enter the image you want to filter with extension: "<<endl;
        cin >> image_name;
        resize_image(image_name);
    }
    else if(choice =="d"||choice=="D"){
        string image_name;
        cout << "Enter the image you want to filter with extension: "<<endl;
        cin >> image_name;
        crop_image(image_name);
    }


}
