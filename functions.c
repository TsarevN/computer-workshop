// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "functions.h"
#include <stdio.h> //ввод и вывод.
#include <locale.h> //русский €зык.
#include <stdbool.h> //тип данных bool. false or true.
#include <string.h> //работа со строками.
#include <math.h> //математические функции.
#include <ctype.h> //обработка символов.
#include <stdlib.h> //работа с динамическими массивами.
#include <time.h> //рандомные числа.

void writeFromFileAnArray(char* filename, char* str)
{
	FILE* f;
	int c;
	int i = 0;
	fopen_s(&f, filename, "r");
	if (!f)
	{
		exit(1);
	}
	while ((c = getc(f)) != EOF)
	{
		str[i] = c;
		i++;
	}
	fclose(f);
}

void readingFromFile(char* filename)
{
	FILE* f;
	int c;
	fopen_s(&f, filename, "r");
	if (!f)
	{
		exit(1);
	}
	while ((c = getc(f)) != EOF)
	{
		printf("%c", c);
	}
	fclose(f);
}

void writingToFile(char* filename, char* message, int sizeMessage)
{
	FILE* f;
	fopen_s(&f, filename, "w+");
	if (!f)
	{
		printf("error");
		exit(1);
	}
	for (int i = 0; i < sizeMessage; i++)
	{
		putc(message[i], f);
	}
	fclose(f);
}

void randomInitialDoubleArray(int** array, int rows, int cols, int min, int max)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			array[i][j] = (rand() % max) + min;
		}
	}
}

void randomInitialArray(int* array, int size, int min, int max)
{
	for (int i = 0; i < size; i++)
	{
		array[i] = (rand() % max) + min;
	}
}

void sortArrayDwarf(int* array, int size)
{
	int i = 1;
	int j = 2;
	while (i < size)
	{
		if (array[i - 1] <= array[i])
		{
			i = j;
			j++;
		}
		else
		{
			int t = array[i];
			array[i] = array[i - 1];
			array[i - 1] = t;
			i--;
			if (i == 0)
			{
				i = j;
				j++;
			}
		}
	}
}

void sortArrayBubble(int* array, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])	// <, если надо в пор€дке убывани€.
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

void printIntArray(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
}

void printIntDoubleArray(int** array, int rows, int cows)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cows; j++)
		{
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
}

void printCharArray(char* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%c", array[i]);
	}
}

void strToUpper(char* str)
{
	while (*str)
	{
		if (islower(*str))
		{
			*str = toupper(*str);
		}
		str++;
	}
}

void strToLower(char* str)
{
	while (*str)
	{
		if (isupper(*str))
		{
			*str = tolower(*str);
		}
		str++;
	}
}

void GameOne()
{
	const int MIN = 1;
	const int MAX = 100;
	int guess = 0;
	int guesses = 0;
	int answer;

	srand(time(0));

	answer = (rand() % MAX) + MIN;

	do
	{
		printf("Enter a guess: ");
		scanf_s("%d", &guess);
		if (guess > answer)
		{
			printf("To high!\n");
		}
		else if (guess < answer)
		{
			printf("To low\n");
		}
		else
			printf("CORRECT!\n");
		guesses++;
	} while (guess != answer);
	printf("********************\n");
	printf("answer: %d\n", answer);
	printf("guesses: %d\n", guesses);
	printf("********************");
}

void GameTwo()
{
	char questions[][100] = { "1. What year did the C language debut?: ",
									 "2. Who is credited with creating C: ",
									 "3. What is the predecessor of C: " };

	char options[][100] = { "A. 1969", "B. 1972", "C. 1975", "D. 1999",
								  "A. Dennis Ritchie", "B. Nikola Tesla", "C. John Carmack", "D. Doc Brown",
								  "A. Objective C", "B. B", "C. C++", "D. C#" };

	char answer[3] = { 'B', 'A', 'B' };

	int numberOfQuestions = sizeof(questions) / sizeof(questions[0]); // = 3

	char guess;
	int score = 0;

	printf("QUIZ GAME\n");

	for (int i = 0; i < numberOfQuestions; i++)
	{
		printf("***************\n");
		printf("%s\n", questions[i]);
		printf("***************\n");

		for (int j = (i * 4); j < (i * 4) + 4; j++)
		{
			printf("%s\n", options[j]);
		}
		printf("guess: ");
		scanf_s("%c", &guess); // error!!!!!!!
		while (getchar() != '\n');

		guess = toupper(guess);

		if (guess == answer[i])
		{
			printf("CORRECT\n");
			score++;
		}
		else
			printf("WRONG!\n");
	}

	printf("FINAL SCORE: %d/%d\n", score, numberOfQuestions);
}

void clearMemoryDoubArr(int** array, int size)
{
	for (int i = 0; i < size; i++)
	{
		free(array[i]);
	}
	free(array);
}

int arrayUnique(int* array, int size)
{
	for (int counter1 = 0; counter1 < size; counter1++)
	{
		for (int counter2 = counter1 + 1; counter2 < size; counter2++)
		{
			if (array[counter1] == array[counter2]) // если найден одинаковый элемент
			{
				for (int counter_shift = counter2; counter_shift < size - 1; counter_shift++)
				{
					array[counter_shift] = array[counter_shift + 1]; // выполнить сдвиг всех остальных элементов массива на -1, начина€ со следующего элемента, после найденного дубл€
				}
				size -= 1; // уменьшить размер массива на 1

				if (array[counter1] == array[counter2]) // если следующий элемент - дубль
				{
					counter2--; // выполнить переход на предыдущий элемент     
				}
			}
		}
	}
	return size;
}

long double fact(int N)
{
	if (N < 0) // если пользователь ввел отрицательное число
		return 0; // возвращаем ноль
	if (N == 0) // если пользователь ввел ноль,
		return 1; // возвращаем факториал от нул€ - не удивл€етесь, но это 1 =)
	else // ¬о всех остальных случа€х
		return N * fact(N - 1); // делаем рекурсию.
}

int isPrime(unsigned int num)
{
	 for (int i = 2; (i * i) <= num; i++) {
		  if (num % i == 0) {
				return 0;
		  }
	 }
	 return 1;
}

int addArray(int* array_1, int* array_2, int size)
{
	int temp = 0;
	for (int i = 0; i < size; i++)
	{
		temp += array_1[i] + array_2[i];
	}
	return temp;
}