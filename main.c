#include "main.h"

/**
 * main - test _printf function
 *
 * Return: 0
 */
int main(void)
{
    _printf("----- Basic Test -----\n");
    _printf("Hello World\n");

    _printf("\n----- Character -----\n");
    _printf("Char: %c\n", 'A');

    _printf("\n----- String -----\n");
    _printf("String: %s\n", "Ali");
    _printf("NULL String: %s\n", NULL);

    _printf("\n----- Percent -----\n");
    _printf("Percent: %%\n");

    _printf("\n----- Integers -----\n");
    _printf("Positive: %d\n", 123);
    _printf("Negative: %i\n", -456);
    _printf("Zero: %d\n", 0);

    _printf("\n----- Edge Case -----\n");
    _printf("INT_MIN: %d\n", -2147483648);

    return (0);
}
