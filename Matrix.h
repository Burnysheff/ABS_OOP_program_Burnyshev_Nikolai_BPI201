#ifndef __shape__
#define __shape__

#include <fstream>

class Matrix {
public:

    // Статический метод формирования элементов (нужен, чтобы мы могли
    // формировать элементы прямо из контейнера)
    static Matrix* Static_enter(std::ifstream &enterstr);

    // Статический метод случайного формирования элементов (нужен, чтобы мы могли
    // формировать элементы прямо из контейнера)
    static Matrix* Static_random_enter(std::ofstream &outfila);

    // Виртуальные методы, определяемые в производных классах

    // Метод формирования матрицы вручную
    virtual void Enter(std::ifstream &enterstr) = 0;

    //Метод автоматического формирования матрицы
    virtual void EnterRandom(std::ofstream &outfila) = 0;

    // Метод вывода матрицы на экран
    virtual void Print(std::ofstream &outstr) = 0;

    // Метод подсчета среднего арифметического чисел матрицы
    virtual double Average() = 0;
};

#endif
