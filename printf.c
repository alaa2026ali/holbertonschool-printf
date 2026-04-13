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
	/* initialize argument list */
	va_start(arg_list, format);
	/* loop through each character in format string */
	while (format[i] != '\0')
	{
		/* check if current character is '%' */
		if (format[i] == '%')
		{
			i++; /* move to next character (specifier) */
			/* if '%' is last character, return error */
			if (format[i] == '\0')
			{
				va_end(arg_list);
				return (-1);
			}
			/* handle character specifier */
			if (format[i] == 'c')
			{
				char c = va_arg(arg_list, int);
				printed_chars += write(1, &c, 1);
			}
			/* handle string specifier */
			else if (format[i] == 's')
			{
				char *str = va_arg(arg_list, char *);
				int j = 0;
				/* if string is NULL, print (null) */
				if (str == NULL)
					str = "(null)";
				/* print string character by character */
				while (str[j] != '\0')
				{
					printed_chars += write(1, &str[j], 1);
					j++;
				}
			}
			/* handle '%%' (print % symbol) */
			else if (format[i] == '%')
			{
				printed_chars += write(1, "%", 1);
			}
			/* handle unknown specifier */
			else
			{
				/* print '%' and the unknown character */
				printed_chars += write(1, "%", 1);
				printed_chars += write(1, &format[i], 1);
			}
		}
		else
		{
			/* print normal characters */
			printed_chars += write(1, &format[i], 1);
		}
		i++; /* move to next character */
	}
	/* clean up argument list */
	va_end(arg_list);
	return (printed_chars);
}
