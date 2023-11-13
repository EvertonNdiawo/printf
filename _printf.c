#include "main.h"

/**
 * _putchar - writes a character to stdout
 *
 * @c:character to print
 *
 * Return: a character to standard output.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printf - prints output according to a specified format.
 *
 * @format: string to print
 *
 * Return: number of characters printed.
 */

int _printf(const char *format, ...)
{
	int char_counter = 0;
	va_list argumentList;

	if (!format)
		return (-1);

	va_start(argumentList, format);

	while (*format)
	{
		if (*format != '%' || (*format == '%' && *(format + 1) == '%'))
			char_counter += _putchar(*format++);
		else if (*(format + 1) == 'c')
			char_counter += _putchar(va_arg(argumentList, int)), format += 2;
		else
			char_counter += _putchar(*format++);
	}

	va_end(argumentList);

	return (char_counter);
}
