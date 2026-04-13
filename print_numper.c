#include "main.h"

/**
* print_numper - prints an intreger 
* @n: numper
*
* Return: numper of characters printed 
*/ 
int print_numper(int n)
{
     int count = 0;
     char c;

     if (n < 0)
     {
        write(1, "-", 1);
        count++;

        n = -n;
     }

     if (n / 10)
          count += print_numper(n / 10);

     c = (n % 10 ) + '0';
     write(1, &c, 1);
     count++;

     return (count);
}

