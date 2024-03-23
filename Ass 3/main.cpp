#include <iostream>
#include "image_class.h"

using namespace std;

int grey(string file);
string blacken(string file);
string whiten(string file);
int merges(string file,string file2);
string edge (string file);
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
                    cout<<"Please enter filename with the extension"<<endl;
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
                            cout<<"Please enter filename with the extension"<<endl;
                            string file;
                            cin>>file;
                            whiten(file);
                        }
                    else if(choose =="B" || choose =="b")
                        {
                            cout<<"Please enter filename with the extension"<<endl;
                            string file;
                            cin>>file;
                            blacken(file);
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
                }
            else if(x==3)
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
    cout<<"The new image name with the extension"<<endl;
    cin>>file;
    image.saveImage(file);
    system(file.c_str());
}



string blacken(string file){
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
    cout<<"new name"<<endl;
    cin>>file;
    image.saveImage(file);
    system(file.c_str());


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
    cout<<"new name"<<endl;
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
    cout<<"new name"<<endl;
    cin>>file;
    image2.saveImage(file);
    system(file.c_str());
}


string edge(string file){
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
                    if(ave>127)
                        {
                            ave=255;
                        }
                    else
                        {
                            ave=0;
                        }
                    for(int z=0;z<3;z++)
                        {
                            image(x,y,z)=ave;
                        }
                }
        }
    cout<<"new name"<<endl;
    cin>>file;
    image.saveImage(file);
    return file;
    //system(file.c_str());

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
            cout<<"D) Exit the program"<<endl;
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


