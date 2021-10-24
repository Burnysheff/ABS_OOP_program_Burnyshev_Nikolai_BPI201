
#include "Matrix.h"
#include "TriangleMatrix.h"
#include "SquareMatrix.h"
#include "DiagonalMatrix.h"

Matrix* Matrix::Static_enter(std::ifstream &enterstr) {
    // Ключ, показывающий, какую матрицу мы формируем (1 - обычную, 2 - треугольную, 3 - диагональную)
    int key;
    enterstr >> key;
    // Создаем пустой указатель
    Matrix* mat = nullptr;
    switch (key) {
        // В указатель дефолтный объект одного из производных классов
        case 1:
            mat = new SquareMatrix;
            break;
        case 2:
            mat = new TriangleMatrix;
            break;
        case 3:
            mat = new DiagonalMatrix;
            break;
    }
    // Если ключ некорректен, возвращаем пустой указатель
    if (key > 3 || key < 1) {
        return mat;
    }
    // Формируем объект производного класса с помощью определенной в нем виртуальной функции
    mat->Enter(enterstr);
    // Возвращаем указатель
    return mat;
}

// Все то же самое, но ключ генерируем рандомно
Matrix* Matrix::Static_random_enter(std::ofstream &outfila) {
    int key = rand() % 3 + 1;
    Matrix* mat;
    switch (key) {
        case 1:
            mat = new SquareMatrix;
            break;
        case 2:
            mat = new TriangleMatrix;
            break;
        case 3:
            mat = new DiagonalMatrix;
            break;
    }
    mat->EnterRandom(outfila);
    return mat;
}