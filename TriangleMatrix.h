#ifndef __TriangleMatrix__
#define __TriangleMatrix__

#include <fstream>
#include "Matrix.h"

// Нижняя треугольная матрица (на основе одномерного массива);
// Параметры - размер массива, его элементы и шаг (для того, чтобы заполнить элементы под диагональю)
// Элемент [i][j] на (i - j) * step больше элемента на диагонали

class TriangleMatrix : public Matrix {
private:
    int step;
    int size;
    int **array;
public:

    virtual ~TriangleMatrix() { };

    // Виртуальные методы ввода, вывода и подсчета среднего
    void Enter(std::ifstream &enterstr);

    void EnterRandom(std::ofstream &outfila);

    void Print(std::ofstream &outstr);

    double Average();
};

#endif //__TriangleMatrix__