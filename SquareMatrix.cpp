
#include "SquareMatrix.h"
#include <stdlib.h>

// Ввод из файла
void SquareMatrix::Enter(std::ifstream &enterstr) {
    enterstr >> this->size;
    this->array = new int* [this->size];
    for(int i = 0; i < this->size; i++) {
        this->array[i] = new int[this->size];
    }
    for (int i = 0; i < this->size; ++i) {
        for (int j = 0; j < this->size; ++j) {
            enterstr >> this->array[i][j];
            if (this->array[i][j] == 0) {
                this->array[i][j] = 1;
            }
        }
    }
}

// Случайное формирование элементов
void SquareMatrix::EnterRandom(std::ofstream &outfilea) {
    this->size = random() % 10 + 2;
    this->array = new int* [this->size];
    for(int i = 0; i < this->size; i++) {
        this->array[i] = new int[this->size];
    }
    for (int i = 0; i < this->size; ++i) {
        for (int j = 0; j < this->size; ++j) {
            this->array[i][j] = random() % 100;
            outfilea << this->array[i][j] << " ";
        }
    }
    outfilea << "\n";
}

// Подсчет среднего значения
double SquareMatrix::Average() {
    double result = 0;
    for (int i = 0; i < this->size; ++i) {
        for (int j = 0; j < this->size; ++j) {
            result += this->array[i][j];
        }
    }
    return (result / (this->size * this->size));
}

// Вывод матрицы на экран
void SquareMatrix::Print(std::ofstream &outstr) {
    outstr << "This is an ordinary square matrix:\n";
    for (int i = 0; i < this->size; ++i) {
        for (int j = 0; j < this->size; ++j) {
            outstr << this->array[i][j] << " ";
        }
        outstr << "\n";
    }
    outstr << "An average is " << this->Average() << "\n";
}
