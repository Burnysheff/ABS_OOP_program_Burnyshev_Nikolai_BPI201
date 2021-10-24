#ifndef __SquareMatrix__
#define __SquareMatrix__

#include <fstream>
#include "Matrix.h"

// Структура обычной матрицы - в качестве полей размер и элементы матрицы

struct SquareMatrix : Matrix {
private:

    int size;
    int **array;

public:

    virtual ~SquareMatrix() {};

    // Виртуальные методы ввода, вывода и подсчета среднего
    virtual void Enter(std::ifstream &enterstr);

    virtual void EnterRandom(std::ofstream &outfila);

    virtual void Print(std::ofstream &outstr);

    virtual double Average();
};

#endif //__SquareMatrix__