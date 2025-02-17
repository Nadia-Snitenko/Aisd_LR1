#include <iostream>
#include "Image.h"
#include <time.h>


image::image(const image& other) {
    this->M = other.M;
    this->N = other.N;
    im_values = new int[M * N];
    for (int i = 0; i < M * N; i++) {
        im_values[i] = other.im_values[i];
    }
}

image::~image() {
   delete[] im_values;
    M = 0;
    N = 0;
};

bool image:: get(int i, int j) const {// ���������� �������� �� �������
    return im_values[i * N + j];
}

void image::change(int i, int j, bool new_val) const { // ������ ���������� �� ������� �� ����� �������� 
    im_values[i * N + j] = new_val;
}

bool image::can_multiply(const image& other) {// ����������� �����������/ ������������ ���� ����������� �� �������
    return ((M == other.M) && (N == other.N));
}


void image:: random_Image() { // ����������� ���������� �����������
    if ((M == NULL) || (N == NULL)) throw "exeption";
    srand(time(0));
    for (int i = 0; i < rows(); i++) {
        for (int j = 0; j < cols(); j++) {
            int p_1 = rand() % 2;
            change(i, j, p_1);
        }
    }
}

image image:: operator+(const image& other) {//�������� �����������

    if (!(can_multiply(other))) { // ���� �� �������� �� �������
         throw ("The images are of different sizes, they can not be combined");
        image empty;
        return empty;// ������ �����������
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
image image:: operator*(const image& other) { // ������������ �����������
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

image image:: operator!() { // �������� �����������
    image result(M, N);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            result.im_values[i * N + j] = !get(i, j);
        }
    }
    return result;
}

image image:: operator=(const image& other) { // �������� ������������
    image result(other);
    return result;
}

image image:: operator*(bool value) { //���������� ������� ������� �� ����������
    image result(M, N);
    for (int i = 0; i < M * N; ++i) {
        result.im_values[i] = im_values[i] && value;
    }
    return result;
}

image image:: operator+ (bool value) { //�������� ������� ������� � ����������
    image result(M, N);
    for (int i = 0; i < M * N; ++i) {
        result.im_values[i] = im_values[i] || value;
    }
    return result;
}

bool image::draw_using_the_keyboard() { // ���������� ������� �������, � ����������
    if (im_values == nullptr) {
        throw "Memory is not available";
        return false;
    }
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            int k = i + 1, l = j + 1;
            std::cout << "[" << k << "]" << "[" << l << "] = ";
            std::cin >> im_values[i * N + j];
        }
    }
    return true;
}

void image::print_to_screen() { // ����� ����������� �� �����
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (im_values[i * M + j] != NULL) {
                std::cout << "*" << " ";
            }
            else {
                std::cout << " " << " ";
            }
        }
        std::cout << std::endl;
    }
}

void image::resize(int rows, int cols) { //������� �������
    N = rows;
    M = cols;
    if (im_values)
        delete[] im_values;
    im_values = new int[M * N];
}

double image::fullness() { // ����������� �������������
    int fullness = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (im_values[i * M + j]) fullness++;
        }
    }
    return (double)fullness / (double)(M * N);
}

int image::get_size() const { 
    if ((M == NULL)||( N == NULL)) throw "exeption";
    return (M*N);
}

int image::rows() const { // ������
    if (M == NULL) throw "exeption";
    return M;
}

int  image:: cols() const { // �������
    if (N == NULL) throw "exeption";
    return N;
}

