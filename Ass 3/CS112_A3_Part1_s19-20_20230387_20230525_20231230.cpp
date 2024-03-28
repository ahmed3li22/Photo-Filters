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

Image vertical_flip(Image &image);
Image horizontal_flip(Image &image);
Image black_and_white(Image &image);
Image grey(Image &image);
Image blacken(Image &image);
Image whiten(Image &image);
int menu(int x);
Image inverts(Image &image);

int main(){
    int x;
    int y=1;
    int z=0;
    string newname;
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
                        grey(image);
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
                             //y=0;
                        }
                    else if(x==5)
                        {
                            cout<<"Do you want to save it on the same file ?"<<endl;
                            cout<<"A) Yes"<<endl;
                            cout<<"B) No"<<endl;
                            string choose;
                            getline(cin,choose);
                            if(choose =="A" || choose =="a")
                                {
                                    image.saveImage(file);
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
                                    //y=0;
                                }
                        }
                    else if(x==6)
                        {
                            cout<<"Do you want to save the image before loading another image ?"<<endl;
                            cout<<"A) Yes "<<endl;
                            cout<<"B) No "<<endl;
                            string choose2;
                            getline(cin,choose2);
                            if(choose2 =="A" || choose2 =="a")
                                {
                                    cout<<"Do you want to save it on the same file ?"<<endl;
                                    cout<<"A) Yes"<<endl;
                                    cout<<"B) No"<<endl;
                                    string choose;
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
                                }
                            else if(choose2 =="B" || choose2 =="b")
                                {
                                    break;
                                }
                        }
                    else if(x==7)
                        {
                            cout<<"Do you want to save the image before exiting ?"<<endl;
                            cout<<"A) Yes "<<endl;
                            cout<<"B) No "<<endl;
                            string choose2;
                            getline(cin,choose2);
                            if(choose2 =="A" || choose2 =="a")
                                {
                                    cout<<"Do you want to save it on the same file ?"<<endl;
                                    cout<<"A) Yes"<<endl;
                                    cout<<"B) No"<<endl;
                                    string choose;
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
                                }
                            else if(choose2 =="B" || choose2 =="b")
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


int menu(int x){
    while(true)
        {
            cout<<"-------Photo Filters-------"<<endl;
            cout<<"A) Grayscale Filter"<<endl;
            cout<<"B) Darken and Lighten Filter"<<endl;
            cout<<"C) Black and White Filter "<<endl;
            cout<<"D) Flip Image Filter "<<endl;
            cout<<"E) invert colours Image "<<endl;
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

Image inverts(Image &image)
{
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


