#include <stdio.h>
#include <locale.h>

#include "functions.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	//int x = 0;

	//printf("Введите число: ");
	//scanf_s("%d", &x);
	
	//printf("Функция FI(%d) = %d\n", x, FI(x));

	//printf("Функция Fact(%d) = %llu\n", x, Fact(x));

	//printf("Функция DFact(%d) = %llu\n", x, DFact(x));

	//printf("Задача Эйлера №2 при входном параметре %d равна %llu\n", x, Euler_2(x));

	//printf("%d-й член ряда Фибоначчи равен %llu", x, Fib(x));

	printf("Сумма всех четных элементов ряда Фибоначчи(меньше 4 млн) равна %d\n", SumFib());

	return 0;
	

	
}
