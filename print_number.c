#include "main.h"

/**
 * print_number - prints an integer
 * @n: number to print
 * Return: number of characters printed
 */
int print_number(int n)
{
	int count = 0;
	unsigned int num;

	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		num = -n;
	}
	else
	{
		num = n;
	}

	if (num / 10)
		count += print_number(num / 10);

	count += write(1, &"0123456789"[num % 10], 1);

	return (count);
}
