
//Файл с реализацией структуры диагональной матрицы

#include "DiagonalMatrix.h"
#include <stdlib.h>

// Ввод вручную
void DiagonalMatrix::Enter(std::ifstream &enterstr) {
    enterstr >> this->size;
    this->array = new int [this->size];
    for (int i = 0; i < this->size; ++i) {
        enterstr >> this->array[i];
        // Если мы встретили 0 или конец файла (тоже будет 0), то
        // до заполняем матрицу единицами, чтобы получить диагональную
        if (this->array[i] == 0) {
            this->array[i] = 1;
        }
    }
}

// Случайное заполнение матрицы
void DiagonalMatrix::EnterRandom(std::ofstream &outfila) {
    // Размер от 2 до 11
    this->size = random() % 10 + 2;
    this->array = new int[this->size];
    // Числами до 100
    for (int i = 0; i < this->size; ++i) {
        this->array[i] = random() % 100 + 1;
        outfila << this->array[i] << " ";
    }
}

// Подсчет среднего из чисел матрицы
double DiagonalMatrix::Average() {
    double result = 0;
    for (int i = 0; i < this->size; ++i) {
        for (int j = 0; j < this->size; ++j) {
            if (i == j) {
                result += this->array[i];
            }
        }
    }
    return (result / (this->size * this->size));
}

// вывод матрицы на экран
void DiagonalMatrix::Print(std::ofstream &outstr) {
    outstr << "This is a diagonal square matrix:\n";
    for (int i = 0; i < this->size; ++i) {
        for (int j = 0; j < this->size; ++j) {
            if (i == j) {
                outstr << this->array[i] << " ";
            } else {
                outstr << "0" << " ";
            }
        }
        outstr << "\n";
    }
    outstr << "An average is " << this->Average() << "\n";
}
