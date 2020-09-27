#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H
#include <stdarg.h>
#include <unistd.h>
/**
 * struct op - struct of type and associated function.
 *@op: type including int, float, char, and string.
 *@f: associated function.
 */
typedef struct op
{
	char *op;
	int (*f)(va_list a);
} op_t;

/*op_functions*/
int print_ch(va_list a);
int print_st(va_list a);
int print_in(va_list a);
int print_di(va_list a);

/*digit_conversion*/
int count_digit(int n);
int _itoa(int n);

/*utility*/
int _printf(const char *format, ...);
int _putchar(char c);
int _strlen(char *S);

#endif
