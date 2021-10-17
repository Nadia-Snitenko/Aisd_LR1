#pragma once
#include <iostream>


class image {
private:
    int M, N;
    bool* im_values;

public:

    image() : im_values(nullptr), M(0), N(0) {}
    image(int colls, int rolls) : im_values(new bool[colls * rolls]), M(colls), N(rolls) {}
    image(const image& other);
    ~image();

    bool get(int i, int j) const;// нахождение элемента по индексу
    void change(int i, int j, bool new_val) const; // замена переменной по индексу на новое значение 
    bool can_multiply(const image& other);// возможность объединения/ перемножения двух изображений по размеру

    image operator+(const image& other);//сложение изображений
    image operator*(const image& other);// перемножение изображений
    image operator!(); // обратное изображение
    image operator=(const image& other); // оператор присваивания
    image operator*(bool value); //домножение матрицы рисунка на переменную
    image operator+ (bool value); //сложение матрицы рисунка с переменной

    image random_Image(int rows, int cols); // составление случайного изображения
        
    bool draw_using_the_keyboard(); // выполнение рисунка вручную, с клавиатуры
    void print_to_screen(); // вывод изображения на экран
    void resize(int rows, int cols);// измение размера
    double fullness();// коэффициент заполненности
    int rows() const; // строки
    int cols() const; // столбцы

};


