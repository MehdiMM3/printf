#include"main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Custom implementation of printf
 * @format: The format string
 *
 * Return: The number of characters printed
 *	(excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	int chars_printed = 0;

	char ch;

	while ((ch = *format) != '\0')
	{
		if (ch != '%')
		{
			putchar(ch);
			chars_printed++;
		}
		else
		{
			format++;
			ch = *format;

			if (ch == '%')
			{
				putchar(ch);
				chars_printed++;
			}
			else if (ch == 'c')
			{
				char c = va_arg(args, int);

				putchar(c);
				chars_printed++;
			}
			else if (ch == 's')
			{
				char *str = va_arg(args, char*);

				while (*str)
				{
					putchar(*str);
					chars_printed++;
					str++;
				}
			}
			else if (ch == 'd' || ch == 'i')
			{
				int num = va_arg(args, int);

				printf("%d", num);
				chars_printed++;
			}
		}

		format++;
	}

	va_end(args);

	return (chars_printed);
}
