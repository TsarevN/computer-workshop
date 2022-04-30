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

void giveTegStart(char* str, char* tegStart)
{
	int size = 0;
	while (str[size])
		size++;

	for (int i = 1; i < size + 1; i++)
		tegStart[i] = str[i - 1];
	tegStart[0] = '<';
	tegStart[size + 1] = '>';
	tegStart[size + 2] = '\0';
}

void giveTegFinish(char* str, char* tegFinish)
{
	int size = 0;
	while (str[size])
		size++;
	tegFinish[0] = '<';
	tegFinish[1] = '/';
	for (int i = 2; i < size + 2; i++)
		tegFinish[i] = str[i - 2];

	tegFinish[size + 2] = '>';
	tegFinish[size + 3] = '\0';
}

char* my_strstr(const char* haystack, const char* needle)
{
	const char* temp;
	const char* c;
	temp = needle;
	while (*haystack)
	{
		c = haystack;
		while (*(haystack++) == *(needle++))
		{
			if (!(*needle))
				return (char*)c;
			if (!(*haystack))
				return NULL;
		}
		needle = temp;
	}
	return NULL;
}

void Zamena(char* fileName, char* teg, char* str)
{
	int sizeTeg = 0;
	while (teg[sizeTeg] != '\0')
	{
		sizeTeg++;
	}
	char* tegStart = (char*)malloc(sizeTeg + 2 * sizeof(int));
	if (!tegStart)
		exit(EXIT_FAILURE);
	char* tegFinish = (char*)malloc(sizeTeg + 3 * sizeof(int));
	if (!tegFinish)
		exit(EXIT_FAILURE);
	char* fileArray = (char*)malloc(1024 * sizeof(int));
	if (!fileArray)
		exit(EXIT_FAILURE);

	giveTegStart(teg, tegStart);									// tegStart  = "<teg>"      size = 5;
	giveTegFinish(teg, tegFinish);								// tegFinish = "</teg>"     size = 6;

	int sizeTegStart = 0;
	while (tegStart[sizeTegStart])
		sizeTegStart++;

	
	//—читываем файл и записываем в fileArray
	FILE* fp;
	int c;
	int i = 0;
	fopen_s(&fp, fileName, "r");
	if (!fp)
	{
		printf("Ќе удалось открыть файл");
		getchar();
		exit(1);
	}
	while ((c = getc(fp)) != EOF)
	{
		fileArray[i] = c;
		i++;
	}
	fileArray[i] = '\0';
	fclose(fp);

	char* indexStart = my_strstr(fileArray, tegStart);
	if (indexStart == NULL)
	{
		printf("Teg not found");
		exit(1);
	}
	int indexStart2 = indexStart - fileArray + sizeTegStart - 1;

	char* indexFinish = my_strstr(fileArray, tegFinish);
	if (indexFinish == NULL)
	{
		printf("Teg not found");
		exit(1);
	}
	int indexFinish1 = indexFinish - fileArray;
	int countIndex = indexFinish1 - indexStart2 - 1;
	int sizeStr = 0;
	while (str[sizeStr])
		sizeStr++;

	//≈сли размер строки в теге и в заданной строке равен
	if (countIndex - sizeStr == 0)
	{
		for (int i = 1; i <= countIndex; i++)
			fileArray[indexStart2 + i] = str[i - 1];
		int k = 0;
		while (fileArray[k])
			k++;
		fileArray[k] = '\0';
	}

	int sizeFileArray = 0;
	while (fileArray[sizeFileArray])
		sizeFileArray++;

	//≈сли размер строки в теге больше размера заданной строки str.
	int limiter = sizeFileArray - indexFinish1;
	if (countIndex - sizeStr > 0)
	{
		for (int i = 1; i <= sizeStr; i++)
			fileArray[indexStart2 + i] = str[i - 1];
		for (int i = 1; i <= limiter; i++)
			fileArray[indexStart2 + i + sizeStr] = fileArray[indexFinish1 - 1 + i];
		fileArray[indexStart2 + 1 + sizeStr + limiter] = '\0';
	}

	//≈сли размер строки в теге меньше размера заданной строки str.
	if (countIndex - sizeStr < 0)
	{

		int h = sizeStr - countIndex; //на сколько надо сдвинуть.
		char* temp = (char*)malloc(sizeFileArray + h * sizeof(char));
		if (!temp)
			exit(EXIT_FAILURE);
		for (int i = 0; i < indexStart2 + 1; i++)
		{
			temp[i] = fileArray[i];
		}
		for (int i = 0; i < sizeStr; i++)
		{
			temp[indexStart2 + 1 + i] = str[i];
		}
		for (int i = 0; i < sizeFileArray - indexFinish1; i++)
		{
			temp[indexStart2 + 1 + i + sizeStr] = fileArray[indexFinish1 + i];
		}
		for (int i = 0; i < sizeFileArray + h; i++)
			fileArray[i] = temp[i];
		fileArray[sizeFileArray + h] = '\0';
		free(temp);
	}

	//ќткрываем файл на перезапись
	FILE* f;
	fopen_s(&f, fileName, "w");
	if (!f)
	{
		printf("Ќе удалось открыть файл");
		getchar();
		exit(1);
	}
	int size = 0;
	while (fileArray[size])
		size++;
	for (int i = 0; i < size; i++)
	{
		putc(fileArray[i], f);
	}

	fclose(f);

	free(tegStart);
	free(tegFinish);
	free(fileArray);
}

void removeSpace(char* arr)
{
	int n = 0;
	while (arr[n])
		n++;

	int space = 0;
	int k = 0;

	for (int i = 0; i < n; i++)
	{
		while (k == 0 && i < n && arr[i] == ' ')
			i++;

		if (arr[i] == ' ')
		{
			if (!space)
			{
				arr[k++] = arr[i];
				space = 1;
			}
		}
		else if (ispunct(arr[i]))
		{
			if (k > 0 && arr[k - 1] == ' ')
				arr[k - 1] = arr[i];
			else
				arr[k++] = arr[i];

			space = 0;
		}
		else
		{
			arr[k++] = arr[i];
			space = 0;
		}
	}
	arr[k] = '\0';
	if (arr[k - 1] = ' ')
		arr[k - 1] = '\0';
}