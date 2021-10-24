#include "Container.h"

// Создание контейнера (без элементов)
void Container::Make() {
    this->length = 0;
}

// ввод содержимого контейнера из файла
void Container::Enter(std::ifstream &enterstr) {
    while (!enterstr.eof()) {
        // Если мы уже храним 9999 элементов, то прекращаем считывание
        if (this->length == 9999) {
            break;
        }
        // Вызываем статический метод формирования элементов и получаем указатель на матицу
        Matrix *mat = Matrix::Static_enter(enterstr);
        // Если элемент не пустой (данные в файле нормальные), то добавляем в контейнер
        if (mat != nullptr) {
            this->list[this->length] = mat;
            ++this->length;
        }
    }
}

// Случайный ввод содержимого контейнера
void Container::EnterRandom(int size, std::ofstream &outfila) {
    // повторная проверка количества генерируемых элемент (если сгенерировано >= 9999),
    // то прекращаем генерацию
    if (this->length == 9999) {
        return;
    }
    for (int i = 0; i < size; ++i) {
        // вызов статического метода случайного формирования
        this->list[this->length] = Matrix::Static_random_enter(outfila);
        ++this->length;
    }
}

// вывод контейнера на экран
void Container::Print(std::ofstream &outstr) {
    // Вывод количества элементов в контейнере
    outstr << "Totally " << this->length << " elements" << std::endl;
    for (int i = 0; i < this->length; ++i) {
        outstr << "\nElement №" << i + 1 << "\n";
        // Вызов виртуального метода вывода матрицы на экран
        this->list[i]->Print(outstr);
    }
}

// Удаление всех данных из контейнера (чисти память)
void Container::Free() {
    for (int i = 0; i < this->length; ++i) {
        delete(this->list[i]);
    }
    this->length = 0;
}

// Вычисление среднего значения для всех матриц
double Container::Average() {
    double result;
    for (int i = 0; i < this->length; ++i) {
        // Вызов виртуального метода счета среднего арифметического на экран
        result += this->list[i]->Average();
    }
    return result / this->length;
}

// Сортировка матриц пузырьком по среднему значению элементов матрицы
void Container::Sort() {
    for (int i = 0; i < this->length; ++i) {
        for (int j = 0; j < this->length - 1; ++j) {
            if (this->list[j]->Average() > this->list[j + 1]->Average()) {
                Matrix *mat = this->list[j + 1];
                this->list[j + 1] = this->list[j];
                this->list[j] = mat;
            }
        }
    }
}