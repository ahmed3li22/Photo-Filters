/*
this file contain the menu which shows 5 filters which are grayscale,darken&Lighten
,black&White,horizontal&vertical flips and Invert colours, also shows save image, load image
and exit program.

grayscale and darken&Lighten filters by Marwan Mohamed Hassen Id: 20230387 Section: 19/20
black&White and horizontal&vertical flips by Ahmed Ali Ahmed Somida Id:  20230525 Section: 19/20
Invert colours by Demiana farid michael Id:  20231230 Section: 19/20
Emails:2005marwanmohamed@gmail.com "Marwan Mohamed"
       a.semeda4@gmail.com         "Ahmed Ali"
       demianafarid88@gmail.com     "Demiana farid"
*/

#include <iostream>
#include "image_class.h"
#include <string>
#include <cmath>
#include <algorithm>
#include <fstream>

using namespace std;

int calculateOtsuThreshold(Image &image);
int menu(int x);
Image crop_image(Image &image);
Image vertical_flip(Image &image);
Image horizontal_flip(Image &image);
Image black_and_white(Image &image);
Image grey(Image &image);
Image blacken(Image &image);
Image whiten(Image &image);
Image inverts(Image &image);
Image resize_image(Image &image);
Image resize_image2(Image &image2 ,Image image);
Image merges(Image &image,Image image2);
Image blur2(Image &image);
Image Edge_Detection(Image &image);
Image grey2(Image &image);


int main(){
    int x;
    int y=1;
    int z=0;
    string newname;
    string file;
    string file2;
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
                            if(rest == "tga" || rest == "bmp" || rest == "png" || rest == "jpg" || rest == "jpeg")
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
                Image image(file);
                while(true)
                {
                    x=menu(y);
                    y=1;
                    if(x==0)
                        {
                        grey2(image);
                        }
                    else if(x==1)
                        {
                            cout<<"A) Lighten"<<endl;
                            cout<<"B) Darken"<<endl;
                            string choose;
                            getline(cin,choose);
                            if(choose =="A" || choose =="a")
                                {
                                    whiten(image);
                                }
                            else if(choose =="B" || choose =="b")
                                {
                                    blacken(image);
                                }
                        }
                    else if(x==2)
                        {
                            black_and_white(image);
                        }
                    else if(x==3)
                        {
                            cout<<"A) Horizontal Flip"<<endl;
                            cout<<"B) Vertical Flip"<<endl;
                            string choose;
                            getline(cin,choose);
                            if(choose =="A" || choose =="a")
                                {
                                    horizontal_flip(image);
                                }
                            else if(choose =="B" || choose =="b")
                                {
                                    vertical_flip(image);
                                }
                        }
                    else if(x==4)
                        {
                            inverts(image);
                        }
                    else if(x==5)
                        {
                          crop_image(image);
                        }
                    else if(x==6)
                        {
                          resize_image(image);
                        }
                    else if(x==7)
                        {
                           cout << "Enter the Second image name with the extension: ";
                           while(true)
                            {
                                getline(cin,file2);
                                ifstream check;
                                check.open(file2);
                                size_t id =0;
                                string rest=file2.substr(file2.find_last_of(".") + 1);
                                if((id =file2.find(".")) != std::string::npos)
                                    {
                                        if(rest == "tga" || rest == "bmp" || rest == "png" || rest == "jpg" || rest == "jpeg")
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
                           Image image2(file2);
                           resize_image2(image2 , image);
                           merges(image , image2);
                        }
                    else if(x==8)
                        {
                            Edge_Detection(image);
                        }
                    else if(x==9)
                        {
                            cout<<"Do you want to save it on the same file ?"<<endl;
                            cout<<"A) Yes"<<endl;
                            cout<<"B) No"<<endl;
                            string choose;
                            while(true)
                                {
                                    getline(cin,choose);
                                    if(choose =="A" || choose =="a")
                                        {
                                            image.saveImage(file);
                                            break;
                                        }
                                    else if(choose =="B" || choose =="b")
                                        {
                                            cout << "Enter the new image name with the extension: ";
                                            while(true)
                                                {
                                                    getline(cin,newname);
                                                    size_t id =0;
                                                    string rest=newname.substr(newname.find_last_of(".") + 1);
                                                    if((id =newname.find(".")) != std::string::npos)
                                                        {
                                                            if(rest == "tga" || rest == "bmp" || rest == "png" || rest == "jpg" || rest == "jpeg")
                                                                {
                                                                    break;
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
                                            image.saveImage(newname);
                                            break;
                                            //y=0;
                                        }
                                    else
                                        {
                                            cout<<"Enter a correct choice"<<endl;
                                        }
                                }
                        }
                    else if(x==10)
                        {

                            cout<<"Do you want to save the image before loading another image ?"<<endl;
                            cout<<"A) Yes "<<endl;
                            cout<<"B) No "<<endl;
                            string choose2;
                            while(true)
                                {
                                    getline(cin,choose2);
                                    if(choose2 =="A" || choose2 =="a")
                                        {
                                            cout<<"Do you want to save it on the same file ?"<<endl;
                                            cout<<"A) Yes"<<endl;
                                            cout<<"B) No"<<endl;
                                            string choose;
                                            while(true)
                                                {
                                                    getline(cin,choose);
                                                    if(choose =="A" || choose =="a")
                                                        {
                                                            image.saveImage(file);
                                                            break;
                                                        }
                                                    else if(choose =="B" || choose =="b")
                                                        {
                                                            cout << "Enter the new image name with the extension: ";
                                                            while(true)
                                                                {
                                                                    getline(cin,newname);
                                                                    size_t id =0;
                                                                    string rest=newname.substr(newname.find_last_of(".") + 1);
                                                                    if((id =newname.find(".")) != std::string::npos)
                                                                        {
                                                                            if(rest == "tga" || rest == "bmp" || rest == "pbg" || rest == "jpg" || rest == "jpeg")
                                                                                {
                                                                                    break;
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
                                                            image.saveImage(newname);
                                                            break;
                                                        }
                                                    else
                                                        {
                                                            cout<<"Enter a correct choice"<<endl;
                                                        }
                                                }
                                            break;
                                        }
                                    else if(choose2 =="B" || choose2 =="b")
                                        {
                                            break;
                                        }
                                    else
                                        {
                                            cout<<"Enter a correct choice"<<endl;
                                        }
                                }
                        }
                    else if(x==11)
                        {
                            cout<<"Do you want to save the image before exiting ?"<<endl;
                            cout<<"A) Yes "<<endl;
                            cout<<"B) No "<<endl;
                            string choose2;
                            while(true)
                                {
                                    getline(cin,choose2);
                                    if(choose2 =="A" || choose2 =="a")
                                        {
                                            cout<<"Do you want to save it on the same file ?"<<endl;
                                            cout<<"A) Yes"<<endl;
                                            cout<<"B) No"<<endl;
                                            string choose;
                                            while(true)
                                                {
                                                    getline(cin,choose);
                                                    if(choose =="A" || choose =="a")
                                                        {
                                                            image.saveImage(file);
                                                            z=1;
                                                            break;
                                                        }
                                                    else if(choose =="B" || choose =="b")
                                                        {
                                                            cout << "Enter the new image name with the extension: ";
                                                            while(true)
                                                                {
                                                                    getline(cin,newname);
                                                                    size_t id =0;
                                                                    string rest=newname.substr(newname.find_last_of(".") + 1);
                                                                    if((id =newname.find(".")) != std::string::npos)
                                                                        {
                                                                            if(rest == "tga" || rest == "bmp" || rest == "png" || rest == "jpg" || rest == "jpeg")
                                                                                {
                                                                                    break;
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
                                                            image.saveImage(newname);
                                                            z=1;
                                                            break;
                                                        }
                                                    else
                                                        {
                                                            cout<<"Enter a correct choice"<<endl;
                                                        }
                                                }
                                            break;
                                        }
                                    else if(choose2 =="B" || choose2 =="b")
                                        {
                                            z=1;
                                            break;
                                        }
                                    else
                                        {
                                            cout<<"Enter a correct choice"<<endl;
                                        }
                                }
                            break;
                        }
                }
            }
            else
                {
                    break;
                }
        }
}



int menu(int x){
    while(true)
        {
            cout<<"-------Photo Filters-------"<<endl;
            cout<<"A) Grayscale Filter"<<endl;
            cout<<"B) Darken and Lighten Filter"<<endl;
            cout<<"C) Black and White Filter "<<endl;
            cout<<"D) Flip Image Filter "<<endl;
            cout<<"E) invert colours Image "<<endl;
            cout<<"F) Crop Image "<<endl;
            cout<<"G) Resize Image "<<endl;
            cout<<"H) Merge Images "<<endl;
            cout<<"I) Edge Detection "<<endl;
            cout<<"J) Save Image "<<endl;
            cout<<"K) Load New Image "<<endl;
            cout<<"L) Exit the program "<<endl;
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
            else if(choose =="I" || choose =="i")
                {
                    return 8;
                }
            else if(choose =="J" || choose =="j")
                {
                    return 9;
                }
             else if(choose =="K" || choose =="k")
                {
                    return 10;
                }
            else if(choose =="L" || choose =="l")
                {
                    return 11;
                }
            else
                {
                  cout<<"Please enter correct choice"<<endl;
                }
        }

}



int calculateOtsuThreshold(Image &image) {
    int hist[256] = {0};

    // Calculate histogram
    for (int x = 0; x < image.width; x++) {
        for (int y = 0; y < image.height; y++) {
            int intensity = image(x, y, 0);
            hist[intensity]++;
        }
    }

    int totalPixels = image.width * image.height;
    double sum = 0.0;
    for (int i = 0; i < 256; i++) {
        sum += i * hist[i];
    }

    double sumB = 0.0;
    int wB = 0;
    int wF = 0;
    double varMax = 0.0;
    int threshold = 0;

    for (int i = 0; i < 256; i++) {
        wB += hist[i];
        if (wB == 0)
            continue;

        wF = totalPixels - wB;
        if (wF == 0)
            break;

        sumB += i * hist[i];

        double mB = sumB / wB;
        double mF = (sum - sumB) / wF;

        double varBetween = wB * wF * (mB - mF) * (mB - mF);

        if (varBetween > varMax) {
            varMax = varBetween;
            threshold = i;
        }
    }

    return threshold;
}



Image grey(Image &image){
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
    return image;
}


Image blacken(Image &image){
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
    return image;


}


Image whiten(Image &image){
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
    return image;

}


Image horizontal_flip(Image &image) {
    for (int i = 0; i < image.width/2; i++) {
        for (int j = 0; j < image.height; j++) {
            for(int k=0;k<image.channels;k++) {
                pixel temp = image(i, j, k);
                image(i, j, k) = image(image.width - i - 1, j, k);
                image(image.width - i - 1,j , k) = temp;
            }
        }
    }

    return image;
}


Image vertical_flip(Image &image){
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height / 2; j++) {
            for(int k=0;k<image.channels;k++) {
                pixel temp = image(i, j, k);
                image(i, j, k) = image(i, image.height - j - 1, k);
                image(i, image.height - j - 1, k) = temp;
            }
        }
    }

    return image;
}


Image black_and_white(Image &image) {
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
    return image;

}


Image inverts(Image &image){
    for(int x=0;x<image.width;x++)
        {
            for(int y=0;y<image.height;y++)
                {
                    image(x,y,0)=-image(x,y,0);
                    image(x,y,1)=-image(x,y,1);
                    image(x,y,2)=-image(x,y,2);
                }
        }
    return image;
}


Image crop_image(Image &image){
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
    image=new_image;
    return image;
}


Image resize_image(Image &image){
    int original_width = image.width;
    int original_height = image.height;

    cout << "Do you want to resize by ratio or new dimensions?\n"
         << "A) Resize by ratio\n"
         << "B) Resize by new dimensions\n";
    string choice;
    getline(cin,choice);
    int new_width, new_height;
    while(true){
    if (choice == "A"||choice == "a") {
        double ratio;
        cout << "Enter the resizing ratio: ";
        cin >> ratio;
        new_width = static_cast<int>(original_width * ratio);
        new_height = static_cast<int>(original_height * ratio);
        break;
    } else if (choice == "B"||choice=="b") {
        cout << "Enter the new width: ";
        cin >> new_width;
        cout << "Enter the new height: ";
        cin >> new_height;
        break;
    } else {
        cout << "Invalid choice.\n";
    }}

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
    image=new_image;
    return image;
}


Image merges(Image &image,Image image2){
    for(int x=0;x<image.width;x++)
        {
            for(int y=0;y<image.height;y++)
                {

                    for(int z=0;z<3;z++)
                        {
                            image(x,y,z)=(image2(x,y,z)+image(x,y,z))/2;
                        }
                }
        }
    return image;
}


Image resize_image2(Image &image2 , Image image){
    int original_width = image2.width;
    int original_height = image2.height;
    int new_width, new_height;
    new_height=image.height;
    new_width=image.width;

    Image new_image(new_width, new_height);

    for (int x = 0; x < new_width; x++) {
        for (int y = 0; y < new_height; y++) {
            int src_x = static_cast<int>(round(static_cast<double>(x) / new_width * original_width));
            int src_y = static_cast<int>(round(static_cast<double>(y) / new_height * original_height));
            src_x = min(src_x, original_width - 1);
            src_y = min(src_y, original_height - 1);

            for (int k = 0; k < new_image.channels; k++) {
                new_image(x, y, k) = image2(src_x, src_y, k);
            }
        }
    }
    image2=new_image;
    return image2;
}


Image Edge_Detection(Image &image){
    grey2(image);
    blur2(image);
    Image image2(image.width,image.height);
    int threshold = calculateOtsuThreshold(image);
    cout<<threshold;
    int h=0;
    int v=0;
    int sum=0;
    int t=0;
    for(int x=1;x<image.width-1;x++)
       {
            for(int y=1;y<image.height-1;y++)
                {
                    h=(image(x-1,y-1,0)*-1)+(image(x-1,y,0)*-2)
                      +(image(x-1,y+1,0)*-1)+(image(x+1,y-1,0)*1)
                      +(image(x+1,y,0)*2)+(image(x+1,y+1,0)*1);

                    v=(image(x-1,y-1,0)*-1)+(image(x,y-1,0)*-2)
                      +(image(x+1,y-1,0)*-1)+(image(x-1,y+1,0)*1)
                      +(image(x,y+1,0)*2)+(image(x+1,y+1,0)*1);

                    sum=floor(sqrt((h*h)+(v*v)));
                    if(sum>threshold)
                        {
                            for(int z=0;z<3;z++)
                                {
                                    image2(x,y,z)=0;
                                }
                        }
                    else
                        {
                            for(int z=0;z<3;z++)
                                {
                                    image2(x,y,z)=255;
                                }
                        }
                }

        }
   image=image2;
   return image;
}


Image blur2(Image &image){
    int ab;
    int sum;
    for(int x=1;x<image.width-1;x++)
       {
            for(int y=1;y<image.height-1;y++)
                {
                    ab=(image(x-1,y-1,0))+(image(x-1,y,0)*2)
                      +(image(x-1,y+1,0))+(image(x+1,y-1,0))
                      +(image(x+1,y,0)*2)+(image(x+1,y+1,0))
                      +(image(x,y+1,0)*2)+(image(x,y-1,0)*2)+(image(x,y,0)*4);

                      sum=(ab)/16;

                    for(int z=0;z<3;z++)
                        {
                            image(x,y,z)=sum;
                        }
                }
        }
    return image;
}


Image grey2(Image &image){
    for(int x=0;x<image.width;x++)
        {
            for(int y=0;y<image.height;y++)
                {
                    unsigned int ave=(0.299*image(x,y,0))+(0.587*image(x,y,1))+(0.114*image(x,y,2));
                    for(int z=0;z<3;z++)
                        {
                            image(x,y,z)=ave;
                        }
                }
        }
    return image;
}


