// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#pragma once
#include <stdbool.h>

/*
* ���� ������ �����.
*/
void GameOne();

/*
* ���� ���������.
*/
void GameTwo();

/*
* ���������� ����������� ������� ���������.
* @param array - ����������� ������
* @param size - ������ �������
*/
void sortArrayBubble(int* array, int size);

/*
* ������ ���������� ����������� �������.
* @param array - ����������� ������
* @param size - ������ �������
*/
void sortArrayDwarf(int* array, int size);

/*
* ����� ����������� ������� ���� int.
* @param array - ������
* @param size - ������ �������
*/
void printIntArray(int* array, int size);

/*
* ����� ���������� ������� ���� int.
* @param array - ������
* @param rows - ���-�� �����
* @param cows - ���-�� ��������
*/
void printIntDoubleArray(int** array, int rows, int cows);

/*
* ����� ������� ���� char (������).
* @param array - ����������� ������
* @param size - ������ �������
*/
void printCharArray(char* array, int size);

/*
* ������������� ����������� ������� ���������� �������.
* @param array - ������
* @param size - ������ �������
* @param min - ����������� ��������� �����
* @param max - ������������ ��������� �����
*/
void randomInitialArray(int* array, int size, int min, int max);

/*
* ������������� ���������� ������� ���������� �������.
* @param array - ������
* @param rows - ���-�� �����
* @param cols - ���-�� ��������
* @param min - ����������� ��������� �����
* @param max - ������������ ��������� �����
*/
void randomInitialDoubleArray(int** array, int rows, int cols, int min, int max);

/*
* ������� ��������� �������� (w+) � ���������� ������.
* @param filename - ��� ����� (������: "document.txt")
* @param message - ������, ������� ��������� � ��������� ��������
* @param sizeMessage - ������ ������
*/
void writingToFile(char* filename, char* message, int sizeMessage);

/*
* ��������� ����� �� ����� � ������� � ������� (���� char).
* @param filename - ��� ����� (������: "document.txt")
*/
void readingFromFile(char* filename);

/*
* ��������� ������ �� ����� � ���������� � ������.
* @param filename - ��� ����� (������ "document.txt")
* @param str - ������ � ������� ��������� ������
*/
void writeFromFileAnArray(char* filename, char* str);

/*
* �������������� ������ � ������� �����.
* @param str - ������
*/
void strToUpper(char* str);

/*
* �������������� ������ � ������ �������.
* @param str - ������
*/
void strToLower(char* str);

/*
* �������, ������������ �������� ������� � ������������ ����������.
* ������:
* ���� ������ ��� {1, 5, 6, 1, 4, 5, 9, 1},
* �� ������ ����� {1, 5, 6, 4, 9, 0, 0, 0}
* @return ������� ����� ������ ������� �� ���������� ���������, �� ������� = 5.
*/
int arrayUnique(int* array, int size);

/*
* ������� ��������� ��������� �����.
* @param N - �����
* @return ��������� ��������� �����.
*/
long double fact(int N);

/*
* ������� ���������� ������� �� �����.
* @return 1 - �������, 0 - ���������.
*/
int isPrime(unsigned int num);

/*
* ������� ������������ ������, ���������� ��� ��������� ������������ ������.
*/
void clearMemoryDoubArr(int** array, int size);

/*
* ����� ��������� ���� ��������.
* ������: 
* ar1 = { 2, 4 } 
* ar2 = { 3, 5 } 
* return = 14;
* @return ����� ��������� ��������.
*/
int addArray(int* array_1, int* array_2, int size);