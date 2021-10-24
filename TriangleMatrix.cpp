
#include "TriangleMatrix.h"
#include <stdlib.h>

// Ввод из файла
void TriangleMatrix::Enter(std::ifstream &enterstr) {
    enterstr >> this->size >> this->step;
    this->array = new int* [this->size];
    for(int i = 0; i < this->size; i++) {
        this->array[i] = new int[this->size];
    }
    for (int i = 0; i < this->size; ++i) {
        for (int j = 0; j < this->size; ++j) {
            if (i == j) {
                enterstr >> this->array[i][j];
                // Если элемент на диагонали равен 0 (или если закончился файл, что даст
                // тот же результат), то добиваем матрицу единицами
                if (this->array[i][j] == 0) {
                    this->array[i][j] = 1;
                }
            } else {
                // Вычисление значения элемента под диагональю
                if (i > j) {
                    this->array[i][j] = this->array[j][j] + this->step * (i - j);
                }
            }
        }
    }
}

// Случайное заполнение
void TriangleMatrix::EnterRandom(std::ofstream &outfila) {
    this->size = random() % 10 + 2;
    this->array = new int* [this->size];
    for(int i = 0; i < this->size; i++) {
        this->array[i] = new int[this->size];
    }
    for (int i = 0; i < this->size; ++i) {
        for (int j = 0; j < this->size; ++j) {
            if (i >= j) {
                this->array[i][j] = random() % 100;
                outfila << this->array[i][j] << " ";
                // Если число на диагонали и равно 0, то делаем его единицей (чтобы было красиво)
                if (i == j && this->array[i][j] == 0) {
                    this->array[i][j] = 1;
                }
            } else {
                this->array[i][j] = 0;
                outfila << this->array[i][j] << "\n";
            }
        }
    }
}

// Вычисление среднего значения
double TriangleMatrix::Average() {
    double result = 0;
    for (int i = 0; i < this->size; ++i) {
        for (int j = 0; j < this->size; ++j) {
            result += this->array[i][j];
        }
    }
    return (result / (this->size * this->size));
}

//Вывод на экран
void TriangleMatrix::Print(std::ofstream &outstr) {
    outstr << "This is a triangle matrix:\n";
    for (int i = 0; i < this->size; ++i) {
        for (int j = 0; j < this->size; ++j) {
            outstr << this->array[i][j] << " ";
        }
        outstr << "\n";
    }
    outstr << "An average is " << this->Average() << "\n";
}
