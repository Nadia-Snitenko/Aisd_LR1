#include <iostream>
#include "Image.h"

image::image(const image& other) {
    this->M = other.M;
    this->N = other.N;
    im_values = new bool[M * N];
    for (int i = 0; i < M * N; i++) {
        im_values[i] = other.im_values[i];
    }
}

image::~image() {
   delete[] im_values;
    M = 0;
    N = 0;
};

bool image:: get(int i, int j) const {// нахождение элемента по индексу
    return im_values[i * N + j];
}

void image::change(int i, int j, bool new_val) const { // замена переменной по индексу на новое значение 
    im_values[i * N + j] = new_val;
}

bool image::can_multiply(const image& other) {// возможность объединения/ перемножения двух изображений по размеру
    return ((M == other.M) && (N == other.N));
}

image image:: random_Image(int rows, int cols) { // составление случайного изображения
    image image(rows, cols);
    for (int i = 0; i < image.rows(); i++) {
        for (int j = 0; j < image.cols(); j++) {
            image.change(i, j, rand() % 2);
        }
    }
    return image;
}

image image:: operator+(const image& other) {//сложение изображений

    if (!(can_multiply(other))) { // если не подходят по размеру
         throw ("The images are of different sizes, they can not be combined");
        image empty;
        return empty;// пустое изображение
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
image image:: operator*(const image& other) { // перемножение изображений
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

image image:: operator!() { // обратное изображение
    image result(M, N);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            result.im_values[i * N + j] = !get(i, j);
        }
    }
    return result;
}

image image:: operator=(const image& other) { // оператор присваивания
    image result(other);
    return result;
}

image image:: operator*(bool value) { //домножение матрицы рисунка на переменную
    image result(M, N);
    for (int i = 0; i < M * N; ++i) {
        result.im_values[i] = im_values[i] && value;
    }
    return result;
}

image image:: operator+ (bool value) { //сложение матрицы рисунка с переменной
    image result(M, N);
    for (int i = 0; i < M * N; ++i) {
        result.im_values[i] = im_values[i] || value;
    }
    return result;
}



bool image::draw_using_the_keyboard() { // выполнение рисунка вручную, с клавиатуры
    if (im_values == nullptr) {
        std::cout << "Memory is not available";
        return false;
    }
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << "[" << i << "]" << "[" << j << "] = ";
            std::cin >> im_values[i * N + j];
        }
    }
    return true;
}

void image::print_to_screen() { // вывод изображения на экран
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (im_values[i * M + j]) {
                std::cout << "*" << " ";
            }
            else {
                std::cout << " " << " ";
            }
        }
        std::cout << std::endl;
    }
}


void image::resize(int rows, int cols) { //измение размера
    //N = checkType(rows);
    N = rows;
    M = cols;
    //M = checkType(cols);
    if (im_values)
        delete[] im_values;
    im_values = new bool[M * N];
}

double image::fullness() { // коэффициент заполненности
    int fullness = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (im_values[i * M + j]) fullness++;
        }
    }
    return (double)fullness / (double)(M * N);
}

int image::rows() const { // строки
    return M;
}

int  image:: cols() const { // столбцы
    return N;
}

