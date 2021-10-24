#include <iostream>

#include <iostream>
#include <fstream>
#include <cstdlib> // для функций rand() и srand()
#include <ctime>
#include <cstring>

#include "Container.h"

int main(int argc, char* argv[]) {
    clock_t begin = clock();
    // Сообщение о начале работы
    std::cout << "Start" << "\n";
    // Если формирование вручную, в командной строке должно быть 4 аргумента
    // Если формирование автоматическое, то 5 аргументов (еще один - файл с псевдовходными данными) -
    // - теми, которые надо было бы ввести, чтобы получить тот же результат
    if (argc != 5 && strcmp(argv[1], "auto") || (argc != 6 && strcmp(argv[1], "file"))) {
        std::cout << "Please, check number of command line arguments!" << "\n";
        return 1;
    }

    // Создание контейнера
    Container c;
    c.Make();

    // Если введен неправильный способ формирования, то выдаем ошибку
    if (!strcmp(argv[1], "file") && !strcmp(argv[1], "auto")) {
        std::cout << "Invalid source of data!" << "\n";
        return 2;
    }

    // Случай, когда мы читаем из файла
    if (!strcmp(argv[1], "file")) {
        std::ifstream ifst(argv[2]);
        c.Enter(ifst);
        // Если нас остановили в цикле на 9999 элементе,
        // то предупреждаем о том, что мы отсекли все, что за ним
        if (c.length >= 9999) {
            std::cout << "The number of matrices cut at 9999" << "\n";
        }
    } else {
        // Случай, когда генерация происходит автоматически
        int size = atoi(argv[2]);
        // Если в размере не число, то выдаем ошибку
        if (size == 0) {
            std::cout << "Size is to be an integer!" << "\n";
            return 3;
        }
        // Обработка ситуации, когда введенный размер отрицателен или слишком большой
        if (size < 1 or size > 9999) {
            std::cout << "Size should be a natural number under 10000!" << "\n";
            return 4;
        }
        // Файл, куда будут помещаться псевдовходные данные
        std::ofstream outfilea (argv[5]);
        // Само формирование элементов
        c.EnterRandom(size, outfilea);
        outfilea.close();
    }

    // В первый файл записываем просто полученные данные и среднее значение каждой из матриц
    std::ofstream outfile (argv[3]);
    outfile << "Filled container: " << std::endl;
    c.Print(outfile);
    outfile.close();

    // Во второй файл помещаем отсортированные данные и вывод среднее значение по всем матрицам
    std::ofstream outfile2(argv[4]);
    outfile2 << "Average of all: " << c.Average() << "\n";
    c.Sort();
    c.Print(outfile2);

    // Очищаем память
    c.Free();
    std::cout << "Stop"<< std::endl;
    // Выводим результат по времени
    clock_t end = clock();
    std::cout << double(end - begin) / 1000000;
    return 0;
}