#include <stdio.h>
#include <locale.h>

#include "functions.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	//int x = 0;

	//printf("������� �����: ");
	//scanf_s("%d", &x);
	
	//printf("������� FI(%d) = %d\n", x, FI(x));

	//printf("������� Fact(%d) = %llu\n", x, Fact(x));

	//printf("������� DFact(%d) = %llu\n", x, DFact(x));

	//printf("������ ������ �2 ��� ������� ��������� %d ����� %llu\n", x, Euler_2(x));

	//printf("%d-� ���� ���� ��������� ����� %llu", x, Fib(x));

	printf("����� ���� ������ ��������� ���� ���������(������ 4 ���) ����� %d\n", SumFib());

	return 0;
	

	
}