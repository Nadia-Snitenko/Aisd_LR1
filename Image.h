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
    // ���������� �������� �� �������
    void change(int i, int j, T new_val) const; // ������ ���������� �� ������� �� ����� �������� 
    bool can_multiply(const image& other);// ����������� �����������/ ������������ ���� ����������� �� �������

    image operator+(const image& other);//�������� �����������
    image operator*(const image& other);// ������������ �����������
    image operator!(); // ����������� �����������
    image operator=(const image& other); // �������� ������������
    image operator*(bool value); //���������� ������� ������� �� ����������
    image operator+ (bool value); //�������� ������� ������� � ����������

    void random_Image(); // ����������� ���������� �����������
    T rand_();

    bool draw_using_the_keyboard(); // ���������� ������� �������, � ����������
    void print_to_screen(); // ����� ����������� �� �����
    
    void resize(int rows, int cols);// ������� �������
    double fullness();// ����������� �������������
    int get_size() const; // ������ �������
    int rows() const; // ������
    int cols() const; // �������
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
    // ���������� �������� �� �������
    if (im_values == nullptr) throw "Image is empty";
    if ((i >= N) || (j >= M) || (i < 0) || (j < 0)) throw "Invalid index";
    return im_values[i * N + j];
}

template <class T, T True_, T False_>
void image< T, True_, False_>::change(int i, int j, T new_val) const { 
    // ������ ���������� �� ������� �� ����� �������� 
    if (im_values == nullptr) throw "FAIL";
    if ((new_val != True_) && (new_val != False_)) throw "FAIL";
    if ((i >= N) || (j >= M) || (i < 0) || (j < 0)) throw "Invalid index";

    else im_values[i * N + j] = new_val;
    
}



template <class T, T True_, T False_>
bool image< T, True_, False_>::can_multiply(const image& other) {
    // ����������� �����������/ ������������ ���� ����������� �� �������
    return ((M == other.M) && (N == other.N));
}


template <class T, T True_, T False_>
T image< T, True_, False_>::rand_() {
    bool temp = rand() % 2;
    if (temp) return (True_); else return (False_);
}


template <class T, T True_, T False_>
void image< T, True_, False_>::random_Image() {
    // ����������� ���������� �����������
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
    //�������� �����������

    if (!(can_multiply(other))) {  // ���� �� �������� �� �������
        throw ("The images are of different sizes, they can not be combined");
        image empty;
        return empty; // ������ �����������
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
    // ������������ �����������
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
     // ����������� �����������
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
     // �������� ������������
    image result(other);
    return result;
}

template <class T, T True_, T False_>
image< T, True_, False_> image< T, True_, False_>:: operator*(bool value) {
    //���������� ������� ������� �� ����������
    image result(M, N);
    for (int i = 0; i < M * N; ++i) {
        result.im_values[i] = im_values[i] && value;
    }
    return result;
}

template <class T, T True_, T False_>
image< T, True_, False_> image< T, True_, False_>:: operator+ (bool value) {
     //�������� ������� ������� � ����������
    image result(M, N);
    for (int i = 0; i < M * N; ++i) {
        if ((value) || (im_values[i] = True_)) result.im_values[i] = True_;
        //result.im_values[i] = im_values[i] || value;
    }
    return result;
}

template <class T, T True_, T False_>
bool image< T, True_, False_>::draw_using_the_keyboard() {
     // ���������� ������� �������, � ����������
  
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
     // ����� ����������� �� �����
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
     //������� �������
    if ( (rows < 0) || (cols < 0)) throw "Invalid index";
    N = rows;
    M = cols;
    if (im_values)
        delete[] im_values;
    im_values = new int[M * N];
}

template <class T, T True_, T False_>
double image< T, True_, False_>::fullness() {
     // ����������� �������������
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
    // ������
    if ((M == NULL) || (N == NULL)) throw "exeption";
    return (M * N);
}

template <class T, T True_, T False_>
int image<T, True_, False_>::rows() const {
     // ������
    if (M == NULL) throw "exeption";
    return M;
}

template <class T, T True_, T False_>
int  image<T, True_, False_>::cols() const {
     // �������
    if (N == NULL) throw "exeption";
    return N;
}