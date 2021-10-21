#include "functions.h"
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
/////////////////////////////////////////             дз модуль  (сдать до 25.10)         /////////////////////////////////////////////////////////////////////////////////

float Ex_1()
{
	float a = 0;
	float x = 0;
	float c = 0;
	scanf_s("%f", &a);
	scanf_s("%f", &x);
	scanf_s("%f", &c);
	float L = (sqrt(exp(x) - pow(cos(pow(x, 2) * pow(a, 5)), 4)) + pow(atan(a - pow(x, 5)), 4)) / (exp(1) * sqrt(abs(a + x * pow(c, 4))));
	return L;
}

float Ex_2(t)
{
	float v = 0;
	v = 3 * t * t - 6 * t;
	return v;
}

float Ex_3()
{
	float a = 0;
	float b = 0;
	float c = 0;
	float D = 0;
	float x1 = 0;
	float x2 = 0;
	printf("Введите a:");
	scanf_s("%f", &a);
	printf("Введите b:");
	scanf_s("%f", &b);
	printf("Введите c:");
	scanf_s("%f", &c);
	
	D = (b*b) - (4 * a * c);


	if (a == 0)
	{
		printf("Введите другой параметр");
		exit(1);
	}
	else
	{
		if (D < 0)
		{
			printf("Нет решений");
			exit(1);
		}
		else
		{
			if (D == 0)
			{
				x1 = -b / 2 * a;
				printf("x = %g", x1);
			}
			else
			{
				x1 = -((b + sqrt(D)) / 2 * a);
				x2 = -((b - sqrt(D)) / 2 * a);
				if (x1 == x2)
				{
					printf("Одно решение: %g", x1);
				}
				else
				{
					printf("x1 = %g\n", x1);
					printf("x2 = %g\n", x2);
				}
			}
		}
	}
}

float Ex_4(int x, double time)
{
	double res = 0; // стоимость разговора

	int num = 0;
	num = (x % 10) + ((x / 10) % 10); // номер города
	switch (num)
	{
		case 9:
		{
			res = 11.0*time;
			printf("Винница - код 045, %g", res); //11грн
			break;
		}
		case 10:
		{
			res = 13.0 * time;
			printf("Харьков - код 046, %g", res); //13грн
			break;
		}
		case 8:
		{
			res = 18.0 * time;
			printf("Киев - код 044, %g", res); //18грн
			break;
		}
		case 12:
		{ 
			res = 15.0 * time;
			printf("Одесса - код 048, %g", res); //15грн
			break;
		}
		default:
		{

			printf("Введён неверный код");
			break;
		}
	}
}

int Ex_5()
{
	int a = 0;
	for (int i = 1000; i <= 9999; i++)
	{
		a = pow(i % 10, 4) + pow((i / 10) % 10, 4) + pow((i / 100) % 10, 4) + pow(i / 1000, 4);
		if (a == i)
		{
			printf("%d\n", i);
		}
		else
		{
			continue;
		}
	}
}

int Ex_6()
{
	int* arr;
	int x = 0;
	int number = 0;

	scanf_s("%d", &x);

	arr = malloc(x * sizeof(int));

	for (int i = 0; i < x; ++i)
	{
		scanf_s("%d", &arr[i]);
	}

	for (int i = 0; i < x; ++i)
	{
		number += pow(2, i) * arr[x - 1 - i];
	}

	return number;
}

int Ex_7(int x, int y)
{
	srand(time(NULL));
	int* a;
	a = malloc(x * y * sizeof(int));
	for (int i = 0; i < x * y; i++)
	{
		a[i] = rand() % (10 - (-10) + 1) + (-10);  //rand() % (max - min + 1) + min  (рандом от - 10 до 10)
		a[i] *= 3;											 //увеличил на 3
		a[i] *= -1;											 //поменял знак на противоположный
	}
	for (int i = 0; i < x; i++)
	{

		for (int j = 0; j < y; j++)
		{
			printf_s("%d ", a[i * y + j]);
		}
		printf_s("\n");
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int factorial(x)
{
	unsigned long long int number = 1;
	for (int i = 1; i <= x; i++)
	{
		number *= i;
	}
	return number;
}

bool IsPrime(x)
{
	for (int i = 2; i <= sqrt(x); i++)
	{
		if (x % i == 0)
		{
			return false;
		}
	}
	return true;
}

int CountDel(x)
{
	int count = 0;
	for (int i = 1; i <= factorial(x); i++)
	{
		if (factorial(x) % i == 0)
		{
			count += 1;
		}
		else
		{
			count = count;
		}
	}
	return count;
}

int CoverChislo(x)
{
	int res = 1;
	for (int i = 2; i < x; i++)
	{
		if (x % i == 0)
		{
			res += i;
		}
		else
		{
			res = res;
		}
	}
	if (res == x)
	{
		printf("Число совершенно");
	}
	else
	{
		printf("Число Несовершенно");
	}
}

int CredAref(x)
{
	int count = 0;
	int sum = 0;
	int result = 0;
	while (x > 0)
	{
		if (((x % 10) % 2) == 0)
		{
			count += 1;
			sum += x%10;
		}
		x /= 10;
	}
	result = sum / count;
	return result;
}

int NOD(x)
{
	int res = 0;
	for (int i = 1; i < x; i++)
	{
		if (x % i == 0)
		{
			res = i;
		}
	}
	return res;
}

int CountPrimeDel(x)
{
	int count = 0;
	for (int i = 1; i <= x; i++)
	{
		if ((x % i == 0) && (IsPrime(i) == 1))
		{
			count = count + 1;
		}
		else
		{
			count = count;
		}
	}
	return count;
}

bool DelNeKvadart(x)
{
	int number = 0;
	for (int i = 1; i <= x; i++)
	{
		if (x % i == 0)
		{
			if (i * i == x)
			{
				return false;
			}
		}
	}
	return true;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

float SumChoTo(x)
{
	float number = 0;
	for (float i = 1; i <= x; i++)
	{
		number += 1 / i;
	}
	return number;
}

int TretieChislo(x)
{
	int res = 0;
	while (x > 1000)
	{
		x /= 10;
	}
	res = x % 10;
	return res;

}

int PoslednieChislo(x)
{
	x = x - (x / 10) * 10;
	return x;
	
}




