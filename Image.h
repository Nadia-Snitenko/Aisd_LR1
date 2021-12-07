#pragma once
#include <iostream>
#include "Image.h"
#include <time.h>
#include <complex>
#include <iostream>
#include <string>
using namespace std;

enum class CardinalDirection { NORTH, EAST, SOUTH, WEST };

template <class T, T True_, T False_>
class image {

    int N, M; //size
     T* im_values;

public:

    image() : im_values(nullptr), M(0), N(0) {}
    image(int colls, int rolls) : im_values(new T[colls * rolls]), M(colls), N(rolls) {}
    image(const image& other);
    ~image();

    bool get(int i, int j) const;
    // нахождение элемента по индексу
    void change(int i, int j, T new_val) const; // замена переменной по индексу на новое значение 
    bool can_multiply(const image& other);// возможность объединения/ перемножения двух изображений по размеру

    image operator+(const image& other);//сложение изображений
    image operator*(const image& other);// перемножение изображений
    image operator!(); // реверсивное изображение
    image operator=(const image& other); // оператор присваивания
    image operator*(bool value); //домножение матрицы рисунка на переменную
    image operator+ (bool value); //сложение матрицы рисунка с переменной

    void random_Image(); // составление случайного изображения
    T rand_();

    bool draw_using_the_keyboard(); // выполнение рисунка вручную, с клавиатуры
    void print_to_screen(); // вывод изображения на экран
    
    void resize(int rows, int cols);// измение размера
    double fullness();// коэффициент заполненности
    int get_size() const; // размер рисунка
    int rows() const; // строки
    int cols() const; // столбцы
};


template <class T, T True_, T False_>
image < T, True_, False_> ::image(const image& other) {
    this->M = other.M;
    this->N = other.N;
    im_values = new T[M * N];
    for (int i = 0; i < M * N; i++) {
        im_values[i] = other.im_values[i];
    }
}

template <class T, T True_, T False_>
image< T, True_, False_>::~image() {
    delete[] im_values;
    M = 0.0;
    N = 0.0;
};

template <class T, T True_, T False_>
bool image< T, True_, False_>::get(int i, int j) const {
    // нахождение элемента по индексу
    if (im_values == nullptr) throw "Image is empty";
    if ((i >= N) || (j >= M) || (i < 0) || (j < 0)) throw "Invalid index";
    return im_values[i * N + j];
}

template <class T, T True_, T False_>
void image< T, True_, False_>::change(int i, int j, T new_val) const { 
    // замена переменной по индексу на новое значение 
    if (im_values == nullptr) throw "FAIL";
    if ((new_val != True_) && (new_val != False_)) throw "FAIL";
    if ((i >= N) || (j >= M) || (i < 0) || (j < 0)) throw "Invalid index";

    else im_values[i * N + j] = new_val;
    
}



template <class T, T True_, T False_>
bool image< T, True_, False_>::can_multiply(const image& other) {
    // возможность объединения/ перемножения двух изображений по размеру
    return ((M == other.M) && (N == other.N));
}


template <class T, T True_, T False_>
T image< T, True_, False_>::rand_() {
    bool temp = rand() % 2;
    if (temp) return (True_); else return (False_);
}


template <class T, T True_, T False_>
void image< T, True_, False_>::random_Image() {
    // составление случайного изображения
    if ((M == NULL) || (N == NULL)) throw "exeption";
    srand(time(0));
    for (int i = 0; i < rows(); i++) {
        for (int j = 0; j < cols(); j++) {
            T p_1 = rand_();
            change(i, j, p_1);
        }
    }
}


template <class T, T True_, T False_>
image< T, True_, False_> image< T, True_, False_>:: operator+(const image< T, True_, False_>& other) {
    //сложение изображений

    if (!(can_multiply(other))) {  // если не подходят по размеру
        throw ("The images are of different sizes, they can not be combined");
        image empty;
        return empty; // пустое изображение
    }
    else {
        image sum(M, N);
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < other.N; j++) {
                sum.im_values[i * N + j] = get(i, j) || other.get(i, j);
            }
        }
        return sum;
    }
}

template <class T, T True_, T False_>
image< T, True_, False_> image< T, True_, False_>:: operator*(const image& other) {
    // перемножение изображений
    if (!(can_multiply(other))) {
        image empty;
        return empty;
    }
    else {
        image product(M, N);
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < other.N; j++) {
                product.im_values[i * N + j] = get(i, j) && other.get(i, j);
            }
        }
        return product;
    }
}

template <class T, T True_, T False_>
image< T, True_, False_> image< T, True_, False_>:: operator!() {
     // реверсивное изображение
    image result(M, N);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            result.im_values[i * N + j] = !get(i, j);
        }
    }
    return result;
}

template <class T, T True_, T False_>
image< T, True_, False_> image< T, True_, False_>:: operator=(const image< T, True_, False_>& other) {
     // оператор присваивания
    image result(other);
    return result;
}

template <class T, T True_, T False_>
image< T, True_, False_> image< T, True_, False_>:: operator*(bool value) {
    //домножение матрицы рисунка на переменную
    image result(M, N);
    for (int i = 0; i < M * N; ++i) {
        result.im_values[i] = im_values[i] && value;
    }
    return result;
}

template <class T, T True_, T False_>
image< T, True_, False_> image< T, True_, False_>:: operator+ (bool value) {
     //сложение матрицы рисунка с переменной
    image result(M, N);
    for (int i = 0; i < M * N; ++i) {
        if ((value) || (im_values[i] = True_)) result.im_values[i] = True_;
        //result.im_values[i] = im_values[i] || value;
    }
    return result;
}

template <class T, T True_, T False_>
bool image< T, True_, False_>::draw_using_the_keyboard() {
     // выполнение рисунка вручную, с клавиатуры
  
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            while ((im_values[i * N + j] != True_) && (im_values[i * N + j] != False_)) {
                cout << "[" << i << "]" << "[" << j << "] = ";
                cin >> im_values[i * N + j];
            }  
           
        }
    }
    return true;
}


template <class T, T True_, T False_>  
void image< T, True_, False_>::print_to_screen() {
     // вывод изображения на экран
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (im_values[i * M + j]== True_) {
                cout << "*" << " ";
            }
            else if (im_values[i * M + j] == False_) {
                cout << " " << " ";
            }
        }
        cout <<endl;
    }
}


template <class T, T True_, T False_>
void image< T, True_, False_>::resize(int rows, int cols) {
     //измение размера
    if ( (rows < 0) || (cols < 0)) throw "Invalid index";
    N = rows;
    M = cols;
    if (im_values)
        delete[] im_values;
    im_values = new int[M * N];
}

template <class T, T True_, T False_>
double image< T, True_, False_>::fullness() {
     // коэффициент заполненности
    int fullness = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if ((im_values[i * M + j])==True_) fullness++;
        }
    }
    return (double)fullness / (double)(M * N);
}

template <class T, T True_, T False_> 
int image< T, True_, False_>::get_size() const {
    // размер
    if ((M == NULL) || (N == NULL)) throw "exeption";
    return (M * N);
}

template <class T, T True_, T False_>
int image<T, True_, False_>::rows() const {
     // строки
    if (M == NULL) throw "exeption";
    return M;
}

template <class T, T True_, T False_>
int  image<T, True_, False_>::cols() const {
     // столбцы
    if (N == NULL) throw "exeption";
    return N;
}