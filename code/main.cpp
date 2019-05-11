/* * * * * * * * * * *
 * * * main.cpp  * * *
 * * * * * * * * * * */

#include <iostream>
#include <string>
#include <cstdlib>
#include "vector.hpp"

using namespace std;

template <class T>
void reverseVecor(Vect<T> v)
{
    std::cout << "Reversive output for " << v.mark() << ":" << endl;
    size_t n = v.size();
    for (int i = n - 1; i >= 0; --i) {
        std::cout << v[i] << " ";
    }
    std::cout << endl;
}

int main()
{

    system("chcp 1251 >NULL");

    try {

        /* Создание шаблонного вектора из целых чисел и 10-и элементов */
        Vect<int> v1(10);

        /* Присвоение имени вектору v1 */
        v1.mark(string("v1"));

        /*
	 * Получение размера массива
	 *
	 * где size_t базовый беззнаковый целочисленный тип для хранения
	 * максимального размера теоретически возможного объекта любого типа
	 *
	 */
        size_t n = v1.size();

        /* Заполнение массива целыми числами от 1 до 10 */
        for (size_t i = 0; i < n; ++i) {
            v1[i] = i + 1;
        }

        /* Показать содержимое вектора v1 */
        v1.show();

        /* Вызов пользовательской функции для реверса вектора */
        reverseVecor(v1);
    }
    catch (VectorDebug& vre) {
        vre.ErrMsg();
    }

    try {

        /* Создание массива initStr из пяти элементов типа строка*/
        string initStr[5] = { "first", "second", "third", "fourth", "fifth" };

        /* Создание шаблонного вектора из 5-и элементов типа строка */
        Vect<string> v2(5);

        /* Присвоение имени вектору v2 */
        v2.mark(string("v2"));

        /* Получение размера массива */
        size_t n = v2.size();

        /* Заполнение шаблонного вектора v2 элементами массива initStr */
        for (size_t i = 0; i < n; ++i) {
            v2[i] = initStr[i];
        }

        /* Показ содержимого вектора v2 */
        v2.show();

        /* Вставка элемента под индексом 4 */
        v2.insert(v2.begin() + 3, "After_third");

        /* Показ содержимого вектора v2 */
        v2.show();

        /* Попытка вывести седьмой элемент приведет к порождению исключения */
        // cout << v2[6] << endl;

        /* Добавление трех новых элементов в вектор v2 */
        v2.push_back("Add_1");
        v2.push_back("Add_2");
        v2.push_back("Add_3");

        /* Показ содержимого вектора v2 */
        v2.show();

        /* Удаление двух элементов из конца вектора v2 */
        v2.pop_back();
        v2.pop_back();

        /* Показ содержимого вектора v2 */
        v2.show();
    }
    catch (VectorDebug& vre) {
        vre.ErrMsg();
    }

    try {

        /* Создание шаблонного вектора v3 из целочисленных элементов */
        Vect<int> v3;

        /* Присвоение имени вектору v3 */
        v3.mark(string("v3"));

        /* Добавление трех новых элементов в вектор v3 */
        v3.push_back(41);
        v3.push_back(42);
        v3.push_back(43);

        /* Показ содержимого вектора v3 */
        v3.show();

        /* Создание шаблонного вектора v4 из целочисленных элементов */
        Vect<int> v4;

        /* Присвоение имени вектору v4 */
        v4.mark(string("v4"));

        /* Создание шаблонного вектора v4 из целочисленных элементов */
        v4 = v3;

        /* Показ содержимого вектора v4 */
        v4.show();

        /*
		 * Удаление большего числа элементов чем в нем есть
		 * на самом деле приведет к ошибке
		 */
        v3.pop_back();
        v3.pop_back();
        v3.pop_back(); // v3.pop_back();

        /* Показ содержимого вектора v3 */
        v3.show();
    }

    catch (VectorDebug& vre) {
        vre.ErrMsg();
    }

    system("pause >nul");
}

/* * * * * * * * * * */
