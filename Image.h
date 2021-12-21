#pragma once
#include <iostream>
#include <time.h>
#include <complex>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

enum class CardinalDirection { NORTH, EAST, SOUTH, WEST };

template <class T, T True_, T False_>
class image {

    size_t  columns, rows; //size
    vector <vector <T>> im; //  vector <T>

public:

    image() = default;
    image(const size_t _columns, const size_t _rows)
    {
        columns = _columns;
        rows = _rows;
        im.assign(columns, vector<T>(rows));

    }
    image(const image&) = default;
    ~image() = default;

    int get_size() const {
        if ((columns == NULL) || (rows == NULL)) throw "Exeption";
        return columns * rows;
    }

    int get_columns() const {
        return columns;
    }
    int get_rows() const {
        return rows;
    }

    void resize(size_t _rows, size_t _columns);  // измение размера
    T get(size_t i, size_t j) const;          // нахождение элемента по индексу
    void change(size_t i, size_t j, T new_val);  // изменение переменной по индексу на новое значение 
    bool can_multiply(const image& other);       // возможность объединения/ перемножения двух изображений 
    double fullness();                           // коэффициент заполненности

    T rand_();
    void random_Image();                         // составление случайного изображения

    image operator+(const image& other);//сложение изображений
    image operator*(const image& other);// перемножение изображений
    image operator!(); // реверсивное изображение
    image operator=(const image& other); // оператор присваивания
    image operator*(bool value); //домножение матрицы рисунка на переменную
    image operator+ (int value); //сложение матрицы рисунка с переменной

    bool draw_using_the_keyboard() {
        cout << "Size of your image: " << columns << 'x' << rows << endl << "'" << True_ << "' - is *\n" << "'" << False_ << "' - is ^\n\n";
        size_t n = 1;
        T kovka = ' ';

        for (auto it1 = im.begin(); it1 != im.end(); it1++) {
            for (auto it2 = it1->begin(); it2 != it1->end(); it2++) {
                cout << '№' << n << ':';
                cin >> kovka;
                *it2 = kovka;
                n++;
            }
        }
        cout << endl;
        return true;
    };

    void print_to_screen() {
        for (auto it1 = im.begin(); it1 != im.end(); it1++) {
            for (auto it2 = it1->begin(); it2 != it1->end(); it2++)
                if (*it2 == True_) cout << "*" << " ";
                else if (*it2 == False_) cout << "^" << " ";
            cout << endl;
        }
        cout << endl;
    };

    auto Begin() {
        return im.begin();
    }

    auto End() {
        return im.end();
    }
};

template <class T, T True_, T False_>
void image< T, True_, False_>::resize(size_t _rows, size_t _columns) {
    if ((rows < 0) || (_columns < 0)) throw "Invalid index";
    rows = _rows;
    columns = _columns;
    im.assign(columns, vector<T>(rows));
}

template <class T, T True_, T False_>
T image< T, True_, False_>::get(size_t i, size_t j) const {
    if ((i >= rows) || (j >= columns) || (i < 0) || (j < 0)) throw "Invalid index";
    return im[i][j];
}

template <class T, T True_, T False_>
void image< T, True_, False_>::change(size_t i, size_t j, T new_val) {
    if ((new_val != True_) && (new_val != False_)) throw "FAIL";
    if ((i >= rows) || (j >= columns) || (i < 0) || (j < 0)) throw "Invalid index";
    else im[i][j] = new_val;
}

template <class T, T True_, T False_>
bool image< T, True_, False_>::can_multiply(const image& other) {
    return ((columns == other.columns) && (rows == other.rows));
}


template <class T, T True_, T False_>
T image< T, True_, False_>::rand_() {
    if (rand() % 2) return (True_);
    else return (False_);
}


template <class T, T True_, T False_>
void image< T, True_, False_>::random_Image() {
    if ((columns == NULL) || (rows == NULL)) throw "Image is empty";
    srand(time(0));
    for (auto it1 = im.begin(); it1 != im.end(); it1++) {
        for (auto it2 = it1->begin(); it2 != it1->end(); it2++)
            *it2 = rand_();
    }
}



template <class T, T True_, T False_>
image< T, True_, False_> image< T, True_, False_>:: operator+(const image< T, True_, False_>& other) {

    if (!(can_multiply(other))) {
        cout << "The images are of different sizes, they can not be combined";
        image empty;
        return empty;
    }
    else {
        image sum(columns, rows);
        for (size_t i = 0; i < sum.get_columns(); i++) {
            for (size_t j = 0; j < sum.get_rows(); j++) {
                sum.im[i][j] = get(i, j) || other.get(i, j);
            }
        }
        return sum;
    }
}


template <class T, T True_, T False_>
image< T, True_, False_> image< T, True_, False_>:: operator*(const image& other) {
    if (!(can_multiply(other))) {
        image empty;
        return empty;
    }
    else {
        image product(columns, rows);
        for (size_t i = 0; i < columns; i++) {
            for (size_t j = 0; j < other.rows; j++) {
                product.im[i][j] = get(i, j) && other.get(i, j);
            }
        }
        return product;
    }
}

template <class T, T True_, T False_>
image< T, True_, False_> image< T, True_, False_>:: operator!() {
    image result(columns, rows);
    for (size_t i = 0; i < columns; i++) {
        for (size_t j = 0; j < rows; j++) {
            result.im[i][j] = !get(i, j);
        }
    }
    return result;
}


template <class T, T True_, T False_>
image< T, True_, False_> image< T, True_, False_>:: operator*(bool value) {
    image result(columns, rows);
    for (size_t i = 0; i < columns; i++) {
        for (size_t j = 0; j < rows; j++) {
            result.im[i][j] = get(i, j) && value;
        }
    }
    return result;
}

template <class T, T True, T False>
image< T, True, False> image< T, True, False>:: operator=(const image< T, True, False>& other) { // оператор присваивания
    image result(other);
    return result;
}

template <class T, T True_, T False_>
image< T, True_, False_> image< T, True_, False_>:: operator+ (int value) {
    image result(columns, rows);
    for (size_t i = 0; i < columns; i++) {
        for (size_t j = 0; j < rows; j++) {
            if ((value == True_) || (im[i][j] == True_) || (im[i][j] + value == True_)) result.im[i][j] = True_;
            else result.im[i][j] = False_;
        }
    }
    return result;

}


template <class T, T True_, T False_>
double image< T, True_, False_>::fullness() {
    size_t fullness = 0;
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            if ((im[i][j]) == True_) fullness++;
        }
    }
    return (double)fullness / (double)get_size();
}

