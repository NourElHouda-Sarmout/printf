#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "holberton.h"
/**
 * _printf - produces output according to a specified format.
 * @format: format specified by user.
 * Return: number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	op_t arg_format[] = {
		{"c", print_ch},
		{"s", print_st},
		{"i", print_in},
		{"d", print_di},
		{NULL, NULL}
	};
	int temp; int i = 0; int j = 0; int char_count = 0;

	va_start(args, format);
	if (format == NULL)
		return (-1);
	while (format[j] != '\0')
	{
		if (format[j] == '%' && format[j + 1] == '%')
		{_putchar(format[j]);
			j++;
			char_count++;
		}
		else if (format[j] == '%')
		{
			j++;
			while (format[j] == ' ')
			{
				j++;
			}
			if (format[j] == '%')
			{
				_putchar(format[j]);
				char_count++;
				_putchar(' ');
				j++;
				char_count++;
			}
			while (arg_format[i].op != NULL)
			{
				if (format[j] == *arg_format[i].op)
				{
					temp = arg_format[i].f(args);
					char_count += temp;
				}
				i++;
			}
			i = 0;
		}
		else
		{
			_putchar(format[j]);
			char_count++;
		}
		j++;
	}
	va_end(args);
	return (char_count);
}
