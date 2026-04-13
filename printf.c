#include "main.h"

/**
 * _printf - prints formatted output
 * @format: string containing text and format specifiers
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0, printed_chars = 0;
	va_list arg_list;
	/* check if format is NULL */
	if (format == NULL)
		return (-1);
	/* start reading arguments */
	va_start(arg_list, format);
	/* loop through the format string */
	while (format[i] != '\0')
	{
		/* if we find % */
		if (format[i] == '%')
		{
			i++;
			/* print character */
			if (format[i] == 'c')
			{
				char c = va_arg(arg_list, int);
				printed_chars += write(1, &c, 1);
			}
			/* print string */
			else if (format[i] == 's')
			{
				char *str = va_arg(arg_list, char *);
				int j = 0;
				if (str == NULL)
 				str = "(null)";
				/* loop through string */
				while (str[j] != '\0')
				{
					printed_chars += write(1, &str[j], 1);
					j++;
				}
			}
			/* print % */
			else if (format[i] == '%')
			{
				printed_chars += write(1, "%", 1);
			}
			/* unknown specifier */
			else
			{
				printed_chars += write(1, "%", 1);
				printed_chars += write(1, &format[i], 1);
			}
		}
		else
		{
			/* print normal character */
			printed_chars += write(1, &format[i], 1);
		}
	i++;
	}
	/* end using arguments */
	va_end(arg_list);
	return (printed_chars);
}
