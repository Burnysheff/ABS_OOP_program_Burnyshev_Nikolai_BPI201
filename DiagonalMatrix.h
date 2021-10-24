#ifndef __DiagonalMatrix__
#define __DiagonalMatrix__

#include <fstream>
#include "Matrix.h"

// Диагональная матрица на основе одномерного массива (параметры - размер и элементы массива)

struct DiagonalMatrix : public Matrix {
private:

    int size;
    int *array;
public:

    virtual ~DiagonalMatrix() { };

    // Виртуальные методы ввода, вывода и подсчета среднего
    void Enter(std::ifstream &enterstr);

    void EnterRandom(std::ofstream &outfila);

    void Print(std::ofstream &outstr);

    double Average();
};

#endif //__DiagonalMatrix__