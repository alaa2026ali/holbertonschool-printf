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

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;

			if (format[i] == 'c')
			{
				char c = va_arg(arg_list, int);
				count += write(1, &c, 1);
			}
			else if (format[i] == 's')
			{
				char *str = va_arg(arg_list, char *);
				int j = 0;

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
				count += write(1, "%", 1);
			}
			else if (format[i] == 'd' || format[i] == 'i')
			{
				int num = va_arg(arg_list, int);
				count += print_number(num);
			}
		}
		else
		{
			count += write(1, &format[i], 1);
		}

		i++;
	}

	va_end(arg_list);
	return (count);
}
