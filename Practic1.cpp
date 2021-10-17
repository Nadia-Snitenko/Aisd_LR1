#include <iostream>
#include <time.h>
#include "Image.h"
//#include <math.h>
//#include <conio.h>

using namespace std;

//class image {
//private:
//    int M, N;
//    bool* im_values;
//
//    //int checkType(int value)// проверка на число для размеров матрицы
//    //{
//    //    if (isdigit(value)) {
//    //        //throw -1;
//    //    }
//    //    return value;
//    //}
//
//public:
//    image() { //конструктор по умолчанию
//        this->M = 0;
//        this->N = 0;
//        im_values = nullptr;
//    }
//
//    image(const image& other) { //конструктор копирования
//        this->M = other.M;
//        this->N = other.N;
//        im_values = new bool[M * N];
//        for (int i = 0; i < M * N; ++i) {
//            im_values[i] = other.im_values[i];
//        }
//    }
//
//    image( int M, int N) { // конструктор по параметрам
//        this->N = N;
//        this->M = M;
//        /*this->N = checkType(N);
//        this->M = checkType(M);*/
//        im_values = new bool[M * N];
//    }
//
//    ~image() {
//        delete[] im_values;
//        M = 0;
//        N = 0;
//    };// деструктор
//
//    bool get(int i, int j) const {// нахождение элемента по индексу
//        return im_values[i * N + j];
//    }
//
//    void change(int i, int j, bool new_val) const { // замена переменной по индексу на новое значение 
//        im_values[i * N + j] = new_val;
//    }
//
//    bool can_multiply(const image& other) {// возможность объединения/ перемножения двух изображений по размеру
//        return ((M == other.M) && (N == other.N));
//    }
//
//    image random_Image(int rows, int cols) { // составление случайного изображения
//        image image(rows, cols);
//        for (int i = 0; i < image.rows(); ++i) {
//            for (int j = 0; j < image.cols(); ++j) {
//                image.change(i, j, rand() % 2);
//            }
//        }
//        return image;
//    }
//
//    image operator+(const image& other) {//сложение изображений
//
//        if (!(can_multiply(other))) { // если не подходят по размеру
//            cout << "The images are of different sizes, they can not be combined";
//            image empty;
//            return empty;// пустое изображение
//        }
//        else {
//            image sum(M, N);
//            for (int i = 0; i < M; ++i) {
//                for (int j = 0; j < other.N; ++j) {
//                    sum.im_values[i * N + j] = get(i, j) || other.get(i, j);
//                }
//            }
//            return sum;
//        }
//    }
//    image operator*(const image& other) { // перемножение изображений
//        if (!(can_multiply(other))) {
//            image empty;
//            return empty;
//        }
//        else {
//            image product(M, N);
//            for (int i = 0; i < M; i++) {
//                for (int j = 0; j < other.N; j++) {
//                    product.im_values[i * N + j] = get(i, j) && other.get(i, j);
//                }
//            }
//            return product;
//        }
//    }
//
//    image operator!() { // обратное изображение
//        image result(M, N);
//        for (int i = 0; i < M; i++) {
//            for (int j = 0; j < N; j++) {
//                result.im_values[i * N + j] = !get(i, j);
//            }
//        }
//        return result;
//    }
//
//    image operator=(const image& other) { // оператор присваивания
//        image result(other);
//        return result;
//    }
//
//    image operator*(bool value) { //домножение матрицы рисунка на переменную
//        image result(M, N);
//        for (int i = 0; i < M * N; ++i) {
//            result.im_values[i] = im_values[i] && value;
//        }
//    }
//
//    image operator+ (bool value) { //сложение матрицы рисунка с переменной
//        image result(M, N);
//        for (int i = 0; i < M * N; ++i) {
//            result.im_values[i] = im_values[i] || value;
//        }
//        return result;
//    }
//
//
//
//    bool draw_using_the_keyboard() { // выполнение рисунка вручную, с клавиатуры
//        if (im_values == nullptr) {
//            cout << "Memory is not available";
//            return false;
//        }
//        for (int i = 0; i < M; ++i) {
//            for (int j = 0; j < N; ++j) {
//                cout << "[" << i << "]" << "[" << j << "] = ";
//                cin >> im_values[i * N + j];
//            }
//        }
//        return true;
//    }
//
//    void print_to_screen() { // вывод изображения на экран
//        for (int i = 0; i < M; ++i) {
//            for (int j = 0; j < N; ++j) {
//                if (im_values[i * M + j]) {
//                    cout << "*" << " ";
//                }
//                else {
//                    cout << " " << " ";
//                }
//            }
//            cout << endl;
//        }
//    }
//
//
//    void resize(int rows, int cols) { //измение размера
//        //N = checkType(rows);
//        N = rows;
//        M = cols;
//        //M = checkType(cols);
//        if (im_values)
//            delete[] im_values;
//        im_values = new bool[M * N];
//    }
//
//    double fullness() { // коэффициент заполненности
//        int fullness = 0;
//        for (int i = 0; i < M; i++) {
//            for (int j = 0; j < N; j++) {
//                if (im_values[i * M + j]) fullness++;
//            }
//        }
//        return (double)fullness / (double)(M * N);
//    }
//
//    int rows() const { // строки
//        return M;
//    }
//
//    int cols() const { // столбцы
//        return N;
//    }
//
//};
//
//int GetKey()
//{
//    int key = _getch();
//    if ((key == 0) || (key == 224)) key = _getch();
//    return key;
//}

//int Menu()
//{
//    system("cls");
//    std::cout << "Good morning\n\n1 - Add a vertex to the beginning of the polyline\n2 - Add a vertex to the end of the polyline\n3 - Calculate the length of the polyline\n4 - View the line\n5 - Overwrite vertex value\n6 - View the value of the vertex\n7 - The sum of two polylines\n8 - Check polylines for equality\n\nExit - Esc" << std::endl;
//    while (true)
//    {
//        int key = GetKey();
//        if ((key == 27) || (key == 49) || (key == 50) || (key == 51) || (key == 52) || (key == 53) || (key == 54) || (key == 55) || (key == 56)) return key;
//    }
//}
//
//int Menu_1()
//{
//    system("cls");
//    std::cout << "Choose your line:\n\n1 - First line\n2 - Second line\n\nEsc - Return back" << std::endl;
//    while (true)
//    {
//        int key = GetKey();
//        if ((key == 27) || (key == 49) || (key == 50)) return key;
//    }
//}




int main() {
    srand(time(0));

    
    cout << "Would you like to create a new binary image?\n" << "1 Yes\n" << "0 No\n" << "Your answer:";
    bool answer;
    cin >> answer;
  
    while (answer) {

        cout << "\n A few examples with randomly created images:\n";

        image image1(10,10), image2(10,10), image3(10,10);
        image1.random_Image(10, 10), image2.random_Image(10, 10), image3.random_Image(10, 10);

        cout << "1.\n";
        image1.print_to_screen();

        cout << "\n[Test]\n" << "Reverse image:\n";
        (!image1).print_to_screen();

        cout << "\n[Test1]\n" << "Summing up images:\n";
        cout << "1.\n";
        image1.print_to_screen();
        cout << "2.\n";
        image2.print_to_screen();

        cout << "\n1+2:\n" << endl;
        (image1 + image2).print_to_screen();

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

        cout << "\nWould you like to create a new binary image by yourself?\n" << "1 Yes\n" << "0 No\nYour answer:";
        cin >> answer;
        /*while (!(cin >> answer) || (cin.peek() != '\n') || answer != 1 && answer != 0)
        {
            cin.clear();
            cin.ignore(100000000, '\n');
            cout << "Mistake. Choose 1 or 0\nYour answer:";
        }*/
        if (answer) {
            int M, N;
            cout << "\nHow many lines ?\nM=";
            cin >> M;
            cout << "How many columns ?\nN=";
            cin >> N;
            image IM(M, N);
            IM.draw_using_the_keyboard();
            IM.print_to_screen();
            cout << "Fullness of image:\n";
            cout << IM.fullness();
        }

        cout << "\nWould you like to continue?\n" << "1 Yes\n" << "0 No\n";
        cin >> answer;
       //image1.~image(), image2.~image(), image3.~image();
    }
    return 0;
}

