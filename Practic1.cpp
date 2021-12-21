#include <iostream>
#include <time.h>
#include "Image.h"
#include <math.h>
#include <conio.h>
#include <string>
#include <vector>
#include "windows.h"

using namespace std;


int GetKey()
{
    int key = _getch();
    if ((key == 0) || (key == 224)) key = _getch();
    return key;
}

int Menu_()
{
    system("cls");
    cout << "Choose type of elements:\n\n 1-bool\n 2-int\n 3-char\n 4-other\n\n Esc - Exit\n";
    while (true)
    {
        int key = GetKey();
        if ((key == 27) || (key == 49) || (key == 50) || (key == 51)|| (key == 52)) return key;
    }
}

int Menu()
{
    system("cls"); 
    cout <<"What would you like to do?\n\n"<<"1 - Watch examples\n2 - Creating your own image\n3 - Try out methods\n\nEsc - Back\n "; 
    while (true)
    {
        int key = GetKey();
        if ((key == 27) || (key == 49) || (key == 50) || (key == 51) ) return key;
    }
}

int Menu_1()
{
    system("cls");

    cout << "Select the function you want to test: \n\n1 - Replacing an element in an image 1 \n2 - im1+im2\n3 - im1*im2\n4 - !im1\n5 - im3+1\n6 - im1*1\n7 - Fullness of im2\n8 - im3=im1\n\n Esc - Back" << std::endl;
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
    cout << "Welcome to the binary image program!";
    Sleep(3000);
    int  answer = Menu_();

    if (answer == 27) return 0;
    while (answer != 27) {

        image<bool, 1, 0> image1(5, 5), image2(5, 5), image3(5, 5), image4(3, 3);
        image1.random_Image(), image2.random_Image(), image3.random_Image();
        image<int, 5, 3> image5(5, 5), image6(5, 5), image7(5, 5), image8(3, 3);
        image5.random_Image(), image6.random_Image(), image7.random_Image() ;
        image<char, 'S', 'N'> image9(5, 5), image10(5, 5), image11(5, 5), image12(3, 3);
        image9.random_Image(), image10.random_Image(), image11.random_Image();

        switch (answer)
        {
        case 49:                                                                                             // bool
            cout << " Working with bool type\n\n";
            
            while (true) {
                int  answer = Menu();
                while (answer != 27) {
                    switch (answer)
                    {
                    case 49:
                        try {

                            cout << "\n""Images for tests:\n\n";
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

                            system("pause"); cout << "next\n";

                            cout << "\n[Test3]\n" << "Fullness of image:\n";
                            cout << "3.\n";
                            image3.print_to_screen();
                            cout << image3.fullness();

                        }

                        catch (const char* exception) 
                        {
                            cout << exception << '\n';
                        }
                        break;


                    case 50:

                        try {
                            cout << "\n Your image1: \n";
                            cout << "\nYou have a field 3 * 3, fill it in pixels: 5- true, 3- false\n";
                            image4.draw_using_the_keyboard();
                            image4.print_to_screen();

                            cout << "\nDo you want know fullness of image?\n";
                            answer = Menu2();
                            if (answer == 13)cout << image4.fullness();
                        }

                        catch (const char* exception) 
                        {
                            cout << exception << '\n';
                        }

                        break;

                    case 51:
                        answer = Menu_1();
                        int i = 0, j = 0, val = 0;
                        if (answer == 27) break;
                        try {
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
                                if ((i >= 5) || (j >= 5) || (i < 0) || (j < 0) || ((val != 0) && (val != 1))) throw "exeption";
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

                        }
                        catch (const char* exception) 
                        {
                            cout << exception << '\n';
                        }
                        break;
                    }
                    cout << "\nAgain?\n";
                    answer = Menu2();
                }
            }
            break;
                                                                                                                        // int
        case 50:
            cout << " Working with int type\n\n";
            
            while (true) {
                int  answer = Menu();
                while (answer != 27) {
                    switch (answer)
                    {
                    case 49:
                        try {
                            cout << "Images for tests:\n\n";
                            cout << "1.\n";
                            image5.print_to_screen();
                            cout << "\n[Test]\n" << "Reverse image:\n";
                            (!image5).print_to_screen();
                            system("pause"); cout << "next\n";
                            cout << "\n[Test1]\n" << "Summing up images:\n";
                            cout << "1.\n";
                            image5.print_to_screen();
                            cout << "2.\n";
                            image6.print_to_screen();
                            cout << "\n1+2:\n" << endl;
                            (image5 + image6).print_to_screen();
                            system("pause"); cout << "next\n";
                            cout << "\n[Test2]\n" << "The product of images:\n";
                            cout << "2.\n";
                            image6.print_to_screen();
                            cout << "3.\n";
                            image7.print_to_screen();
                            cout << "2*3:\n";
                            (image7* image6).print_to_screen();
                            system("pause"); cout << "next\n";
                            cout << "\n[Test3]\n" << "Fullness of image:\n";
                            cout << "3.\n";
                            image7.print_to_screen();
                            cout << image7.fullness();
                        }
                                catch (const char* exception) 
                            {
                                cout << exception << '\n';
                            }
                            break;
                    case 50:

                        try {
                            cout << "\n Your image1: \n";
                            cout << "\nYou have a field 3 * 3, fill it in pixels: 5- true, 3- false\n";
                            image8.draw_using_the_keyboard();
                            image8.print_to_screen();

                            cout << "\nDo you want know fullness of image?\n";
                            answer = Menu2();
                            if (answer == 13)cout << image8.fullness();
                        }
                        catch (const char* exception) 
                        {
                            cout << exception << '\n';
                        }

                        break;

                    case 51:
                        answer = Menu_1();
                        int i = 0, j = 0, val = 0;
                        if (answer == 27) break;
                        try {
                            switch (answer)
                            {
                            case 49:
                                cout << "\n\n1.\n";
                                image5.print_to_screen();

                                cout << "\nSelect the pixel coordinates to change:\n\nWhat row?\n";
                                cin >> i;
                                cout << "\nWhat column?\n";
                                cin >> j;
                                cout << "\nWhat value?\n";
                                cin >> val;
                                if ((i >= 5) || (j >= 5) || (i < 0) || (j < 0) || ((val != 0) && (val != 1))) throw "exeption";
                                else image5.change(i, j, val);
                                image5.print_to_screen();
                                break;

                            case 50:
                                cout << "\n\n1.\n";
                                image5.print_to_screen();
                                cout << "2.\n";
                                image6.print_to_screen();
                                cout << "1+2.\n";
                                (image5 + image6).print_to_screen();
                                break;

                            case 51:
                                cout << "\n\n1.\n";
                                image5.print_to_screen();
                                cout << "2.\n";
                                image6.print_to_screen();
                                cout << "1*2.\n";
                                (image5 * image6).print_to_screen();
                                break;
                            case 52:
                                cout << "\n\n1.\n";
                                image5.print_to_screen();
                                cout << "!1.\n";
                                (!image5).print_to_screen();
                                break;
                            case 53:
                                cout << "\n\n3.\n";
                                image7.print_to_screen();
                                cout << "3.+1\n";
                                (image7 + 1).print_to_screen();
                                break;
                            case 54:
                                cout << "\n\n1.\n";
                                image5.print_to_screen();
                                cout << "1.*2\n";
                                (image5 * 2).print_to_screen();
                                break;
                            case 55:
                                cout << "2.\n";
                                image6.print_to_screen();
                                cout << "2.fullness\n";
                                cout << image6.fullness();
                                break;
                            case 56:
                                cout << "\n\n1.\n";
                                image5.print_to_screen();
                                cout << "3.\n";
                                image7.print_to_screen();
                                cout << "3=1.\n";
                                (image7 = image5).print_to_screen();
                                break;
                            }

                        }

                        catch (const char* exception) 
                        {
                            cout << exception << '\n';
                        }
                     break;
                        }
                        cout << "\nAgain?\n";
                        answer = Menu2();
                    }
                }
        break;                                                                                              // char 

        case 51:
            cout << " Working with char type\n\n";
            while (true)
            {
                int  answer = Menu();
                while (answer != 27) {
                    switch (answer) {
                    case 49:
                        try {
                            cout << "Images for tests:\n\n";
                            cout << "1.\n";
                            image9.print_to_screen();
                            cout << "\n[Test]\n" << "Reverse image:\n";
                            (!image9).print_to_screen();
                            system("pause"); cout << "next\n";
                            cout << "\n[Test1]\n" << "Summing up images:\n";
                            cout << "1.\n";
                            image9.print_to_screen();
                            cout << "2.\n";
                            image10.print_to_screen();
                            cout << "\n1+2:\n" << endl;
                            (image9 + image10).print_to_screen();
                            system("pause"); cout << "next\n";
                            cout << "\n[Test2]\n" << "The product of images:\n";
                            cout << "2.\n";
                            image10.print_to_screen();
                            cout << "3.\n";
                            image11.print_to_screen();
                            cout << "2*3:\n";
                            (image11 * image10).print_to_screen();
                            system("pause"); cout << "next\n";
                            cout << "\n[Test3]\n" << "Fullness of image:\n";
                            cout << "3.\n";
                            image11.print_to_screen();
                            cout << image11.fullness();
                        }
                        catch (const char* exception) 
                        {
                            cout << exception << '\n';
                        }
                        break;
                    case 50:

                        try {
                            cout << "\n Your image1: \n";
                            cout << "\nYou have a field 3 * 3, fill it in pixels: 5- true, 3- false\n";
                            image12.draw_using_the_keyboard();
                            image12.print_to_screen();

                            cout << "\nDo you want know fullness of image?\n";
                            answer = Menu2();
                            if (answer == 13)cout << image8.fullness();
                        }
                        catch (const char* exception) 
                        {
                            cout << exception << '\n';
                        }

                        break;

                    case 51:
                        answer = Menu_1();
                        int i = 0, j = 0, val = 0;
                        if (answer == 27) break;
                        try {
                            switch (answer)
                            {
                            case 49:
                                cout << "\n\n1.\n";
                                image9.print_to_screen();

                                cout << "\nSelect the pixel coordinates to change:\n\nWhat row?\n";
                                cin >> i;
                                cout << "\nWhat column?\n";
                                cin >> j;
                                cout << "\nWhat value?\n";
                                cin >> val;
                                if ((i >= 5) || (j >= 5) || (i < 0) || (j < 0) || ((val != 0) && (val != 1))) throw "exeption";
                                else image9.change(i, j, val);
                                image9.print_to_screen();
                                break;

                            case 50:
                                cout << "\n\n1.\n";
                                image9.print_to_screen();
                                cout << "2.\n";
                                image10.print_to_screen();
                                cout << "1+2.\n";
                                (image9 + image10).print_to_screen();
                                break;

                            case 51:
                                cout << "\n\n1.\n";
                                image9.print_to_screen();
                                cout << "2.\n";
                                image2.print_to_screen();
                                cout << "1*2.\n";
                                (image9 * image10).print_to_screen();
                                break;
                            case 52:
                                cout << "\n\n1.\n";
                                image9.print_to_screen();
                                cout << "!1.\n";
                                (!image9).print_to_screen();
                                break;
                            case 53:
                                cout << "\n\n3.\n";
                                image9.print_to_screen();
                                cout << "3.+1\n";
                                (image11 + 1).print_to_screen();
                                break;
                            case 54:
                                cout << "\n\n1.\n";
                                image9.print_to_screen();
                                cout << "1.*2\n";
                                (image9 * 2).print_to_screen();
                                break;
                            case 55:
                                cout << "2.\n";
                                image10.print_to_screen();
                                cout << "2.fullness\n";
                                cout << image10.fullness();
                                break;
                            case 56:
                                cout << "\n\n1.\n";
                                image9.print_to_screen();
                                cout << "3.\n";
                                image11.print_to_screen();
                                cout << "3=1.\n";
                                (image11 = image9).print_to_screen();
                                break;
                            }

                        }
                        catch (const char* exception) // обработчик исключений типа const char*
                        {
                            cout << exception << '\n';
                        }
                        break;
                    }
                }
                cout << "\nAgain?\n";
                answer = Menu2();

            }
            break;
                                                                                                              // enum
        case 52:
            cout << "\n Working with enum\n";
            image<CardinalDirection, CardinalDirection::EAST, CardinalDirection::WEST> image12(5, 5);
            try {
                cout << "\nImage 1:\n";
                image12.random_Image();
                image12.print_to_screen();
                cout << "\nChange elements on plaeces 2x2 and 4x4\n";
                image12.change(2, 2, CardinalDirection::WEST);
                image12.change(4, 4, CardinalDirection::EAST);
                cout << "New image 1:\n";
                image12.print_to_screen();
            }

            catch (const char* exception) 
            {
                cout << exception << '\n';
            }
            cout << "\nAgain?\n";
            answer = Menu2();

            break;
        }
    
    }
    
}
                             
                     








  
