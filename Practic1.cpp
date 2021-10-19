#include <iostream>
#include <time.h>
#include "Image.h"
//#include <math.h>
#include <conio.h>

using namespace std;


int GetKey()
{
    int key = _getch();
    if ((key == 0) || (key == 224)) key = _getch();
    return key;
}

int Menu()
{
    system("cls"); 
    std::cout <<"What would you like to do?\n\n"<<"1 - Watch examples\n2 - Creating your own image\n3 - Try out methods\n\nEsc - Exit\n "; 
    while (true)
    {
        int key = GetKey();
        if ((key == 27) || (key == 49) || (key == 50) || (key == 51) || (key == 52) || (key == 53) || (key == 54) || (key == 55) || (key == 56)) return key;
    }
}

int Menu_1()
{
    system("cls");

    std::cout << "Select the function you want to test: \n\n1 - Replacing an element in an image 1 \n2 - im1+im2\n3 - im1*im2\n4 - !im1\n5 - im3+1\n6 - im1*1\n7 - Fullness of im2\n8 - im3=im1\n\nExit - Esc" << std::endl;
    while (true)
    {
        int key = GetKey();
        if ((key == 27) || (key == 49) || (key == 50) || (key == 51) || (key == 52) || (key == 53) || (key == 54) || (key == 55) || (key == 56)) return key;
    }
}


int Menu2()
{
    cout<<"Yes -  Enter\nNo - Esc\n";
    while (true)
    {
        int key = GetKey();
        if ((key == 27) || (key == 13)) return key;
    }
}

int main() {
    srand(time(0));
    std::cout << "Welcome to the binary image program\n";
    system("pause");
    int  answer = Menu();
    while (answer!=27) {

        image image1(10, 10), image2(10, 10), image3(10, 10);
        image1.random_Image(), image2.random_Image(), image3.random_Image();
        image image4(3, 3);
        int i = 0, j = 0, val = 0;

    switch (answer)
        {
        case 49:
            cout << "Images for tests:\n\n";
            cout << "1.\n";
            image1.print_to_screen();

            cout << "\n[Test]\n" << "Reverse image:\n";
            (!image1).print_to_screen();

            system("pause"); cout << "next\n";

            cout << "\n[Test1]\n" << "Summing up images:\n";
            cout << "1.\n";
            image1.print_to_screen();
            cout << "2.\n";
            image2.print_to_screen();

            cout << "\n1+2:\n" << endl;
            (image1 + image2).print_to_screen();

            system("pause"); cout << "next\n";

            cout << "\n[Test2]\n" << "The product of images:\n";
            cout << "2.\n";
            image2.print_to_screen();
            cout << "3.\n";
            image3.print_to_screen();

            cout << "2*3:\n";
            (image3 * image2).print_to_screen();

            cout << "\n[Test3]\n" << "Fullness of image:\n";
            cout << "3.\n";
            image3.print_to_screen();
            cout << image3.fullness();

            break;
        case 50:
            cout << "\nYou have a field 3 * 3, fill it in pixels\n";
            image4.draw_using_the_keyboard();
            image4.print_to_screen();
            
            cout << "\nDo you want know fullness of image?\n";
            answer = Menu2();
            if(answer==13)cout << image4.fullness();
            break;
        case 51:
            answer = Menu_1();
            if (answer == 27) break;

            switch (answer)
            {
            case 49:
                cout << "\n\n1.\n";
                image1.print_to_screen();

                cout << "\nSelect the pixel coordinates to change:\n\nWhat row?\n";
                cin >> i;
                cout << "\nWhat column?\n";
                cin >> j;
                cout << "\nWhat value?\n";
                cin >> val;
                if ((i >= 10) || (j >= 10) || (i < 0) || (j < 0) || (val < 0)) throw "exeption";
                else image1.change(i, j, val);
                image1.print_to_screen();
                break;
            case 50:
                cout << "\n\n1.\n";
                image1.print_to_screen();
                cout << "2.\n";
                image2.print_to_screen();
                cout << "1+2.\n";
                (image1 + image2).print_to_screen();
                break;
            case 51:
                cout << "\n\n1.\n";
                image1.print_to_screen();
                cout << "2.\n";
                image2.print_to_screen();
                cout << "1*2.\n";
                (image1 * image2).print_to_screen();
                break;
            case 52:
                cout << "\n\n1.\n";
                image1.print_to_screen();
                cout << "!1.\n";
                (!image1).print_to_screen();
                break;
            case 53:
                cout << "\n\n3.\n";
                image1.print_to_screen();
                cout << "3.+1\n";
                (image3 + 1).print_to_screen();
                break;
            case 54:
                cout << "\n\n1.\n";
                image1.print_to_screen();
                cout << "1.*2\n";
                (image1 * 2).print_to_screen();
                break;
            case 55:
                cout << "2.\n";
                image2.print_to_screen();
                cout << "2.fullness\n";
                cout << image2.fullness();
                break;
            case 56:
                cout << "\n\n1.\n";
                image1.print_to_screen();
                cout << "3.\n";
                image3.print_to_screen();
                cout << "3=1.\n";
                (image3 = image1).print_to_screen();
                break;
            }
            break;
        }

        cout << "\n\nWould you like to continue?\n";
        answer=Menu2();
        switch (answer)
        {
        case 13: answer = Menu(); break;
        case 27: break;
        }
       
    }
   std::cout << "End of program";
    return 0;
}

