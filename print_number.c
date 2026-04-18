#include "main.h"

/**
 * print_number - prints an integer
 * @n: number to print
 *
 * Return: number of characters printed
 */
int print_number(int n)
{
	int count = 0;
	unsigned int num;

	/* Handle negative numbers */
	if (n < 0)
	{
		count += write(1, "-", 1); /* print '-' */
		num = (unsigned int)(-n);  /* convert to positive safely */
	}
	else
	{
		num = n;
	}

	/* Print digits recursively (left to right) */
	if (num / 10)
		count += print_number(num / 10);

	/* Print last digit */
	count += write(1, &"0123456789"[num % 10], 1);

	return (count);
}
