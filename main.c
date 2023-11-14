#include <stdio.h>
#include <stdarg.h>
/**
 * _printf - Custom printf function
 * @format: Format string containing conversion specifiers
 *          that specify how to format the output.
 *          Supported specifiers: %c, %s, and %%
 *
 * Return: The number of characters printed (excluding the null byte
 *         used to end output to strings).
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);

	while (*format != '\0')
{
	if (*format == 'c')
{
	char letter = va_arg(args, int);

	putchar(letter);
	count++;
}
	else if (*format == 's')
{
	char *word = va_arg(args, char *);

	while (*word != '\0')
{
	putchar(*word);
	word++;
	count++;
}
}
	else if (*format == '%')
{
	putchar('%');
	count++;
}

	format++;
}

	va_end(args);

	return (count);
}
