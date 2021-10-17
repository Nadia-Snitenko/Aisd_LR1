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

    bool get(int i, int j) const;// ���������� �������� �� �������
    void change(int i, int j, bool new_val) const; // ������ ���������� �� ������� �� ����� �������� 
    bool can_multiply(const image& other);// ����������� �����������/ ������������ ���� ����������� �� �������

    image operator+(const image& other);//�������� �����������
    image operator*(const image& other);// ������������ �����������
    image operator!(); // �������� �����������
    image operator=(const image& other); // �������� ������������
    image operator*(bool value); //���������� ������� ������� �� ����������
    image operator+ (bool value); //�������� ������� ������� � ����������

    image random_Image(int rows, int cols); // ����������� ���������� �����������
        
    bool draw_using_the_keyboard(); // ���������� ������� �������, � ����������
    void print_to_screen(); // ����� ����������� �� �����
    void resize(int rows, int cols);// ������� �������
    double fullness();// ����������� �������������
    int rows() const; // ������
    int cols() const; // �������

};


