#ifndef __Container__
#define __Container__

#include "Matrix.h"

// Контейнер для хранения матриц

class Container {

private:

    // Массив указателей на матрицы (максимум 10000)
    Matrix *list[10000];

public:

    // Переменная, показывающая, сколько мы храним матриц
    int length;

    // Инициализация контейнера
    void Make();

    // Ручной ввод в контейнер
    void Enter(std::ifstream &enterstr);

    // Автоматическое формирование элементов контейнера
    void EnterRandom(int size, std::ofstream &outfila);

    // Вывод элементов контейнера
    void Print(std::ofstream &outstr);

    // Очищение памяти контейнера
    void Free();

    // Среднее значение всех матриц в контейнере
    double Average();

    // Сортировка элементов контейнера пузырьком
    void Sort();
};

#endif
