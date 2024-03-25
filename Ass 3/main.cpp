#include <iostream>
#include "image_class.h"

using namespace std;
void vertical_flip(string imagename);
void horizontal_flip(string imagename);
void black_and_white(string imagename);
int grey(string file);
int blacken(string file);
int whiten(string file);
int merges(string file,string file2);
int new2(string file);
int menu();
int menu2();


int main(){
    int x,y;
    int z=0;
    while(true)
        {
            if(z<1)
                {
                    x=menu();
                }
            if(x==0)
                {
                    cout << "Enter the image name with the extension: ";
                    string file;
                    cin>>file;
                    grey(file);
                    z=0;
                }
            else if(x==1)
                {
                    cout<<"A) Lighten"<<endl;
                    cout<<"B) Darken"<<endl;
                    string choose;
                    getline(cin,choose);
                    if(choose =="A" || choose =="a")
                        {
                            cout << "Enter the image name with the extension: ";
                            string file;
                            cin>>file;
                            whiten(file);
                            z=0;
                        }
                    else if(choose =="B" || choose =="b")
                        {
                            cout << "Enter the image name with the extension: ";
                            string file;
                            cin>>file;
                            blacken(file);
                            z=0;
                        }
                }
            else if(x==2)
                {
                    cout<<"Please enter the First filename with the extension"<<endl;
                    string file;
                    cin>>file;
                    string file2;
                    cout<<"Please enter the Second filename with the extension"<<endl;
                    cin>>file2;
                    merges(file,file2);
                    z=0;
                }
            else if(x==3)
                {
                    cout << "Enter the image name with the extension: ";
                    string file;
                    cin>>file;
                    black_and_white(file);
                    z=0;
                }
            else if(x==4)
                {
                    cout<<"A) Horizontal Flip"<<endl;
                    cout<<"B) Vertical Flip"<<endl;
                    string choose;
                    getline(cin,choose);
                    if(choose =="A" || choose =="a")
                        {
                            cout << "Enter the image name with the extension: ";
                            string file;
                            cin>>file;
                            horizontal_flip(file);
                            z=0;
                        }
                    else if(choose =="B" || choose =="b")
                        {
                            cout << "Enter the image name with the extension: ";
                            string file;
                            cin>>file;
                            vertical_flip(file);
                            z=0;
                        }
                }
            else if(x==5)
                {
                    break;
                }
            y=menu2();
            if(y==0)
                {
                    continue;
                }
            else if(y==1)
                {
                    z=1;
                }
        }
}


int grey(string file){
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
    cout << "Enter the new image name with the extension: ";
    image.saveImage(file);
    system(file.c_str());
}



int  blacken(string file){
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


}


int whiten(string file){
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

}


int merges(string file,string file2){
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


int new2(string file){
    Image image(file);
     for(int x=2;x<image.width-2;x++)
        {
            for(int y=2;y<image.height-2;y++)
                {
                    unsigned int ave=0;
                    unsigned int ave2=0;
                    for(int z=0;z<3;z++)
                        {
                            ave=image(x,y,z);
                            ave2=image(x+1,y,z);
                        }
                    ave=ave/3;
                    ave2=ave2/3;
                    if(ave-ave2>50 )
                        {
                            for(int z=0;z<3;z++)
                            {
                                 for(int i =-2;i<=2;i++)
                                {
                                    for(int j=-2;j<=2;j++)
                                        {
                                            image(x+i,y+j,z)=255;
                                        }
                                }
                            }
                        }





                        /*else if(image(x,y,z)==0 && image(x+1,y,z) ==255)
                        {
                            image(x,y,z)=0;

                        }*/
                        else
                        {
                            for(int z=0;z<3;z++)
                            {
                                image(x,y,z)=0;
                            }
                        }

                }
        }
    cout<<"new name"<<endl;
    cin>>file;
    image.saveImage(file);
    system(file.c_str());
}


int menu(){
    while(true)
        {
            cout<<"-------Photo Filters-------"<<endl;
            cout<<"A) Grayscale Filter"<<endl;
            cout<<"B) Darken and Lighten Filter"<<endl;
            cout<<"C) Merge Images"<<endl;
            cout<<"D) Black and White Filter"<<endl;
            cout<<"E) Flip image Filter "<<endl;
            cout<<"F) Exit the program "<<endl;
            //cout<<" "<<endl;
            string choose;
            getline(cin,choose);
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
            else
                {
                  cout<<"Please enter correct choice"<<endl;
                }
        }

}


int menu2(){
    int x=0;
    while(true)
        {
            cout<<"A) Exit the filter"<<endl;
            cout<<"B) Load new image"<<endl;
            //cout<<" "<<endl;
            string choose;
            while(x<1)
                {
                    getline(cin,choose);
                    x=1;
                }
            getline(cin,choose);
            if(choose =="A" || choose =="a")
                {
                    return 0;
                }
            else if(choose =="B" || choose =="b")
                {
                    return 1;
                }
            else
                {
                  cout<<"Please enter correct choice"<<endl;
                }
        }

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
    system(file.c_str());
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
    system(file.c_str());
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

}

