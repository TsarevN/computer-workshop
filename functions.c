﻿#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

#include "functions.h"

int EvenCount(int t_)
{
   int count = 0;
   
   while (t_ != 0)
   {
      int x = t_ % 10;

      if (x % 2 == 0)
         count++;

      t_ /= 10; // t_ = t_ / 10;
   }

   return count;
}

int PI(int x_)
{
   if (x_ < 2)
      return 0;

   int count = 0;

   for (unsigned int number = 2; number != x_; ++number)
      if (IsPrime(number))
         ++count;

   return count;
}

bool IsPrime(int number_)
{
   
   if (number_ < 2)
      return false;

   unsigned int nSqrt = (int)sqrt(number_) + 1; 

   if (number_ == 2)
      return true;

   if (number_ % 2 == 0)
      return false;

   for (unsigned int i = 3; i <= nSqrt; i += 2)
   {
      if (number_ % i == 0)
         return false;
   }

   return true;
}

int FI(int x_)
{
   if (x_ < 1)
      return 0;

   int count = 0;

   for (int i = 1; i < x_; ++i)
      if (Gcd(i, x_) == 1)
         ++count;

   return count;
}

int Gcd(int a, int b)
{
   if (a < 0)
      a = abs(a);

   if (b < 0)
      b = abs(b);

   while (a != b)
   {
      if (a > b)
         a -= b;
      else
         b -= a;
   }

   return a;
}

unsigned long long Fact(int x_)
{
   if (x_ < 0)
   {
      printf("Что-то\n", x_);
      exit(1);
   }

   if (x_ == 0)
      return 1;

   unsigned long long res = 1;

   for (int i = 1; i <= x_; ++i)
      res *= i;

   return res;
}

unsigned long long DFact(int x_)
{
   if (x_ < 0)
   {
      printf("Ошибка\n", x_);
      exit(1);
   }

   if (x_ == 0)
      return 1;

   unsigned long long res = 1;

   int i = 0;
   if (x_ % 2 == 0)
      i = 2;
   else
      i = 1;

   for (; i <= x_; i += 2)
      res *= i;

   return res;
}

unsigned long long Euler_2(int x_)
{
   unsigned long long sum = 0;

   unsigned long long prev = 0;
   unsigned long long cur = 1;

   while (cur <= x_)
   {
      if (cur % 2 == 0)
         sum += cur;

      unsigned long long next = cur + prev;

      prev = cur;
      cur = next;
   }

   return sum;
}

unsigned long long Fib(int n_)
{
   if (n_ < 0)
   {
      printf("Ошибка\n", n_);
      exit(1);
   }

   if (n_ < 2)
      return n_;

   return Fib(n_ - 1) + Fib(n_ - 2);
}

int SumFib()
{
   int a = 0;
   int b = 1;
   int sum = 0;
   int sum_even = 0;

   while (b < 4000000)
   {
      sum = a + b;   //Ряд Фибоначчи
      b = a;         //
      a = sum;       // 
      
      if (a % 2 == 0)   //Проверка на четность
      {
         sum_even = sum_even + a;  //Сумма четных цифр
      }
   }
   return sum_even;
}
