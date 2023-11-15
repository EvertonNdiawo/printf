#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
/**
 * handle_char - Helper function to handle 'c' specifier
 * @args: Variable argument list
 * @count: Pointer to the count of characters printed
 */
void handle_char(va_list args, int *count)
{
	char c = va_arg(args, int);

	write(1, &c, 1);
	(*count)++;
}

/**
 * handle_string - Helper function to handle 's' specifier
 * @args: Variable argument list
 * @count: Pointer to the count of characters printed
 */
void handle_string(va_list args, int *count)
{
	char *str = va_arg(args, char *);

	write(1, str, strlen(str));
	(*count) += strlen(str);
}

/**
 * handle_percent - Helper function to handle '%' specifier
 * @count: Pointer to the count of characters printed
 */
void handle_percent(int *count)
{
	write(1, "%", 1);
	(*count)++;
}

/**
 * _printf - Produces output according to a format.
 * @format: Format string with conversion specifiers.
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);

	while (*format)
{
	if (*format == '%' && *(format + 1) != '\0')
{
	format++;
	switch (*format)
{
	case 'c':
	handle_char(args, &count);
	break;

	case 's':
	handle_string(args, &count);
	break;

	case '%':
	handle_percent(&count);
	break;

	default:
	break;
}
}
	else
{
	write(1, format, 1);
	count++;
}

	format++;
}

	va_end(args);
	return (count);
}

