#include "main.h"

/**
 * main - test _printf function
 *
 * Return: 0
 */
int main(void)
{
    _printf("Hello World\n");
    _printf("Character: %c\n", 'A');
    _printf("String: %s\n", "Ali");
    _printf("Percent: %%\n");

    return (0);
}
