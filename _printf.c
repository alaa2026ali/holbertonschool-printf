#include "main.h"

/**
 * _printf - prints formatted output
 * @format: format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0, count = 0;
	va_list arg_list;
	/* Check if format is NULL */
	if (format == NULL)
		return (-1);
	va_start(arg_list, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			/* Handle case: '%' at end of string */
			if (format[i] == '\0')
			{
				va_end(arg_list);
				return (-1);
			}

			if (format[i] == 'c')
			{
				/* Print character */
				char c;
				c = va_arg(arg_list, int);
				count += write(1, &c, 1);
			}
			else if (format[i] == 's')
			{
				/* Print string */
				char *str;
				int j = 0;
				str = va_arg(arg_list, char *);
				/* Handle NULL string */
				if (str == NULL)
					str = "(null)";
				while (str[j])
				{
					count += write(1, &str[j], 1);
					j++;
				}
			}
			else if (format[i] == '%')
			{
				/* Print '%' */
				count += write(1, "%", 1);
			}
			else if (format[i] == 'd' || format[i] == 'i')
			{
				/* Print integer */
				int num;
				num = va_arg(arg_list, int);
				count += print_number(num);
			}
			else
			{
				/* Handle unknown specifier */
				count += write(1, "%", 1);
				count += write(1, &format[i], 1);
			}
		}
		else
		{
			/* Print normal character */
			count += write(1, &format[i], 1);
		}

		i++;
	}
	va_end(arg_list);
	return (count);
}
