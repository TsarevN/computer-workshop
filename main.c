#include <stdio.h> 
#include <locale.h> 
#include <stdbool.h> 
#include <string.h> 
#include <math.h> 
#include <ctype.h> 
#include <stdlib.h> 
#include <time.h> 
#include "functions.h" 

int palindrome(long long n)
{
	long long reverse = 0;
	long long temp = 0;


	temp = n;

	while (temp != 0)
	{
		reverse = reverse * 10;
		reverse = reverse + temp % 10;
		temp = temp / 10;
	}

	if (n == reverse)
		return 1;
	else
		return 0;
}

int NumberOne()
{
	int c = 0;

	for (int i = 1; i < 1000; i++)
		if (i % 3 == 0 || i % 5 == 0)
			c += i;

	return c;
}

void NumberTwo()
{
	int a = 1;
	int b = 0;
	int c = 0;
	int sum = 0;
	while (c <= 4000000)
	{
		c = a + b;
		if (c % 2 == 0)
			sum += c;
		a = b;
		b = c;
	}
	printf("%d", sum);
}

void NumberThree()
{
	long long num = 600851475143;
	long long count = 2;
	while (1)
	{
		if (num % count == 0)
		{
			num /= count;
			if (num == 1)
			{
				printf("%lli", count);
				break;
			}
		}
		count += 1;
	}
}

void NumberFour()
{
	long long b = 1;
	long long c = 0;
	for (int i = 100; i < 999; i++)
	{
		for (int j = 100; j < 999; j++)
		{
			c = (long long)i * j;

			if (palindrome(c) == 1)
				if (c > b)
					b = c;
		}
	}
	printf("%lli", b);
}

void NumberSix()
{
	long long a = 0;
	long long b = 0;
	long long c = 0;
	for (long long i = 1; i <= 100; i++)
		a += i;
	a = pow(a, 2);

	for (long long i = 1; i <= 100; i++)
		b += pow(i, 2);

	c = a - b;
	printf("%lli", c);
}

void NumberSeven()
{
	long long c = 0;
	for (long long i = 1; i < 10000000000; i++)
	{
		if (isPrime(i) == 1)
		{
			c++;
		}
		if (c == 10002)
		{
			printf("%lli", i);
			break;
		}
	}
}

void NumberFive()
{
	long long c = 0;
	for (long long i = 1; i < 9000000000000000000; i++)
	{
		c = 0;
		for (long long  j = 1; j <= 20; j++)
		{
			if (i % j == 0)
			{
				c++;
			}
			if (c == 20)
			{
				printf("%lli\n", i);
				exit(0);
			}
		}
	}
}

int main()
{
	char* fileName = (char*)malloc(2048 * sizeof(char));
	if (!fileName)
	{
		return 1;
	}
	gets_s(fileName, 1024);

	char* arr = (char*)malloc(1015 * sizeof(char));
	if (!arr)
	{
		return 1;
	}

	writeFromFileAnArray(fileName, arr);

	char* temp = (char*)malloc(2037 * sizeof(char));
	if (!temp)
	{
		return 1;
	}
	char c;
	int size = 0;
	for (int i = 0; i < 2037; i++)
	{
		if (arr[size] == '\n')
		{
			size++;
		}
		temp[i] = arr[size];
		temp[i + 1] = ',';
		i++;
		size++;
	}
	temp[2000] = '\0';
	writingToFile("text1.txt", temp, 2001);
	
	return 0;
}
