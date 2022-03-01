// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#pragma once
#include <stdbool.h>

/*
* Игра угадай число.
*/
void GameOne();

/*
* Игра викторина.
*/
void GameTwo();

/*
* Сортировка одномерного массива пузырьком.
* @param array - сортируемый массив
* @param size - размер массива
*/
void sortArrayBubble(int* array, int size);

/*
* Гномья сортировка одномерного массива.
* @param array - сортируемый массив
* @param size - размер массива
*/
void sortArrayDwarf(int* array, int size);

/*
* Вывод одномерного массива типа int.
* @param array - массив
* @param size - размер массива
*/
void printIntArray(int* array, int size);

/*
* Вывод двумерного массива типа int.
* @param array - массив
* @param rows - кол-во строк
* @param cows - кол-во столбцов
*/
void printIntDoubleArray(int** array, int rows, int cows);

/*
* Вывод массива типа char (строка).
* @param array - сортируемый массив
* @param size - размер массива
*/
void printCharArray(char* array, int size);

/*
* Инициализация одномерного массива случайными числами.
* @param array - массив
* @param size - размер массива
* @param min - минимальное случайное число
* @param max - максимальное случайное число
*/
void randomInitialArray(int* array, int size, int min, int max);

/*
* Инициализация двумерного массива случайными числами.
* @param array - массив
* @param rows - кол-во строк
* @param cols - кол-во столбцов
* @param min - минимальное случайное число
* @param max - максимальное случайное число
*/
void randomInitialDoubleArray(int** array, int rows, int cols, int min, int max);

/*
* Создает текстовый документ (w+) и записывает строку.
* @param filename - имя файла (пример: "document.txt")
* @param message - строка, которая запишется в текстовый документ
* @param sizeMessage - размер строки
*/
void writingToFile(char* filename, char* message, int sizeMessage);

/*
* Считывает текст из файла и выводит в консоль (типа char).
* @param filename - имя файла (пример: "document.txt")
*/
void readingFromFile(char* filename);

/*
* Считывает строку из файла и записывает в массив.
* @param filename - имя файла (пример "document.txt")
* @param str - массив в который запишется строка
*/
void writeFromFileAnArray(char* filename, char* str);

/*
* Преобразование строки в верхний буквы.
* @param str - строка
*/
void strToUpper(char* str);

/*
* Преобразование строки в нижний регистр.
* @param str - строка
*/
void strToLower(char* str);

/*
* Функция, определяющая элементы массива в единственном экземпляре.
* Пример:
* если массив был {1, 5, 6, 1, 4, 5, 9, 1},
* то станет таким {1, 5, 6, 4, 9, 0, 0, 0}
* @return функция вернёт размер массива из уникальных элементов, из примера = 5.
*/
int arrayUnique(int* array, int size);

/*
* Функция вычисляет факториал числа.
* @param N - число
* @return Факториал заданного числа.
*/
long double fact(int N);

/*
* Функция определяет простое ли число.
* @return 1 - простое, 0 - непростое.
*/
int isPrime(unsigned int num);

/*
* Функция освобождения памяти, выделенной под двумерный динамический массив.
*/
void clearMemoryDoubArr(int** array, int size);

/*
* Сумма элементво двух массивов.
* пример: 
* ar1 = { 2, 4 } 
* ar2 = { 3, 5 } 
* return = 14;
* @return сумма элементов массивов.
*/
int addArray(int* array_1, int* array_2, int size);