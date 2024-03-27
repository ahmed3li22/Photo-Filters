#include <iostream>
#include "image_class.h"
#include <string>
#include <cmath>
#include <algorithm>
#include <fstream>

using namespace std;
string crop_image(string image_name);
string resize_image(string image_name);
string vertical_flip(string imagename);
string horizontal_flip(string imagename);
string black_and_white(string imagename);
string grey(string file);
string blacken(string file);
string whiten(string file);
string merges(string file,string file2);
int menu(int x);


int main(){
    int x;
    int y=1;
    int z=0;
    string newfile;
    string file;
    while(true)
        {
            if(z==0)
            {
                cout << "Enter the image name with the extension: ";
                while(true)
                {
                    getline(cin,file);
                    ifstream check;
                    check.open(file);
                    size_t id =0;
                    string rest=file.substr(file.find_last_of(".") + 1);
                    if((id =file.find(".")) != std::string::npos)
                        {
                            if(rest == "tga" || rest == "bmp" || rest == " pbg" || rest == "jpg" || rest == "jpeg")
                                {
                                if(check)
                                    {
                                        break;
                                    }
                                else
                                    {
                                      cout<<"Image not found, Please enter an image that exist: ";
                                    }
                                }
                            else
                                {
                                    cout<<"Please enter the image name with the correct extension : ";
                                }
                        }
                    else
                        {
                            cout<<"Please enter the image name with the extension: ";
                        }
                }
                Image image;
                while(true)
                {
                    x=menu(y);
                    y=1;
                    if(x==0)
                        {
                        image=grey(file);
                        }
                    else if(x==1)
                        {
                            cout<<"A) Lighten"<<endl;
                            cout<<"B) Darken"<<endl;
                            string choose;
                            getline(cin,choose);
                            if(choose =="A" || choose =="a")
                                {
                                    whiten(file);
                                }
                            else if(choose =="B" || choose =="b")
                                {
                                    blacken(file);
                                }
                        }
                    else if(x==2)
                        {
                            black_and_white(file);
                        }
                    else if(x==3)
                        {
                            cout<<"A) Horizontal Flip"<<endl;
                            cout<<"B) Vertical Flip"<<endl;
                            string choose;
                            getline(cin,choose);
                            if(choose =="A" || choose =="a")
                                {
                                    horizontal_flip(file);
                                }
                            else if(choose =="B" || choose =="b")
                                {
                                    vertical_flip(file);
                                }
                        }
                    else if(x==4)
                        {
                            resize_image(file);
                        }
                    else if(x==5)
                        {
                            cout << "Enter the new image name with the extension: ";
                            cin>>newfile;
                            image.saveImage(newfile);
                            system(file.c_str());
                            y=0;
                        }
                    else if(x==6)
                        {
                            break;
                        }
                    else if(x==7)
                        {
                            cout<<"Do you want to save the image before exiting ?"<<endl;
                            cout<<"A) Yes "<<endl;
                            cout<<"B) No "<<endl;
                            string choose2;
                            getline(cin,choose2);
                            if(choose =="A" || choose =="a")
                                {
                                    s
                                    z=1;
                                    break;
                                }
                            else if(choose =="B" || choose =="b")
                                {
                                    z=1;
                                    break;
                                }
                        }
                }
            }
            else
                {
                    break;
                }
        }
}


string grey(string file){
    Image image(file);
    for(int x=0;x<image.width;x++)
        {
            for(int y=0;y<image.height;y++)
                {
                    unsigned int ave=0;
                    for(int z=0;z<3;z++)
                        {
                            ave+=image(x,y,z);
                        }
                    ave=ave/3;
                    for(int z=0;z<3;z++)
                        {
                            image(x,y,z)=ave;
                        }
                }
        }
    return file;

}


string  blacken(string file){
    Image image(file);
    for(int x=0;x<image.width;x++)
        {
            for(int y=0;y<image.height;y++)
                {

                    for(int z=0;z<3;z++)
                        {
                            image(x,y,z)=image(x,y,z)/2;
                        }
                }
        }
    cout << "Enter the new image name with the extension: ";
    cin>>file;
    image.saveImage(file);
    system(file.c_str());
    return file;


}


string whiten(string file){
    Image image(file);
    unsigned int number =0;
    for(int x=0;x<image.width;x++)
        {
            for(int y=0;y<image.height;y++)
                {

                    for(int z=0;z<3;z++)
                        {
                            number=image(x,y,z);
                            number=(255-number)/2;
                            image(x,y,z)+=number;
                        }
                }
        }
    cout << "Enter the new image name with the extension: ";
    cin>>file;
    image.saveImage(file);
    system(file.c_str());
    return file;

}


string merges(string file,string file2){
    unsigned int number =0;
    Image image(file);
    Image image2(file2);
    for(int x=0;x<image.width;x++)
        {
            for(int y=0;y<image.height;y++)
                {

                    for(int z=0;z<3;z++)
                        {
                            image2(x,y,z)=(image2(x,y,z)+image(x,y,z))/2;
                        }
                }
        }
    cout << "Enter the new image name with the extension: ";
    cin>>file;
    image2.saveImage(file);
    system(file.c_str());
}



int menu(int x){
    while(true)
        {
            cout<<"-------Photo Filters-------"<<endl;
            cout<<"A) Grayscale Filter"<<endl;
            cout<<"B) Darken and Lighten Filter"<<endl;
            cout<<"C) Black and White Filter "<<endl;
            cout<<"D) Flip Image Filter "<<endl;
            cout<<"E) resize Image "<<endl;
            cout<<"F) Save Image "<<endl;
            cout<<"G) Load New Image "<<endl;
            cout<<"H) Exit the program "<<endl;
            string choose;
            getline(cin,choose);
            while(x<1)
                {
                    getline(cin,choose);
                    x=1;
                }
            if(choose =="A" || choose =="a")
                {
                    return 0;
                }
            else if(choose =="B" || choose =="b")
                {
                    return 1;
                }
            else if(choose =="C" || choose =="c")
                {
                    return 2;
                }
            else if(choose =="D" || choose =="d")
                {
                    return 3;
                }
            else if(choose =="E" || choose =="e")
                {
                    return 4;
                }
            else if(choose =="F" || choose =="f")
                {
                    return 5;
                }
            else if(choose =="G" || choose =="g")
                {
                    return 6;
                }
            else if(choose =="H" || choose =="h")
                {
                    return 7;
                }
            else
                {
                  cout<<"Please enter correct choice"<<endl;
                }
        }

}





string horizontal_flip(string imagename) {
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
    system(file.c_str());
    return file;
}


string vertical_flip(string imagename){
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
    system(file.c_str());
    return file;
}


string black_and_white(string imagename) {
    Image image(imagename);
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            int avg = 0;
            for (int k = 0; k < image.channels; k++) {
                avg += image(i, j, k);
            }
            avg /= 3;

            for (int k = 0; k < image.channels; k++) {
                if (avg > 127) {
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
    return file;

}


string resize_image(string image_name) {
    Image image(image_name);

    int original_width = image.width;
    int original_height = image.height;

    cout << "Do you want to resize by ratio or new dimensions?\n"
         << "1) Resize by ratio\n"
         << "2) Resize by new dimensions\n";
    string choice;
    getline(cin,choice);

    int new_width, new_height;
    if (choice == "1") {
        double ratio;
        cout << "Enter the resizing ratio: ";
        cin >> ratio;
        new_width = static_cast<int>(original_width * ratio);
        new_height = static_cast<int>(original_height * ratio);
    } else if (choice == "2") {
        cout << "Enter the new width: ";
        cin >> new_width;
        cout << "Enter the new height: ";
        cin >> new_height;
    } else {
        cout << "Invalid choice. Exiting.\n";
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
    return file;
}

string crop_image(string image_name){
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
    return file;
}


