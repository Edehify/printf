#include "main.h"
/**
 * _printf - program to prints and input into stdout
 * @format: the formate string
 * Return: number of bytes printed
 */

#define BUFF_SIZE 1024

int print_integer(int value, char buffer[], int buff_ind);
void print_buffer(char buffer[], int *buff_ind);

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int buff_ind = 0;
	char buffer[BUFF_SIZE];

	va_start(args, format);

	while (*format)
	{
	if (*format == '%')
	{
		format++;

		if (*format == '%')
		{
			buffer[buff_ind++] = '%';
		}
		else if (*format == 'c')
		{
			buffer[buff_ind++] = va_arg(args, int);
		}
		else if (*format == 's')
		{
			char *str = va_arg(args, char *);
			while (*str)
			{
				buffer[buff_ind++] = *str++;
			}
		}
		else if (*format == 'd' || *format == 'i')
		{
			int value = va_arg(args, int);
			buff_ind = print_interger(value, buffer, buff_ind);
		}
	}
	else
	{
		buffer[buff_ind++] = *format;
	}

		format++;
	}

	va_end(args);

	print_buffer(buffer, &buff_ind);

	return count;
}
/**
 * print_interger- program to prints interger
 * @value: interger
 * @buffer: array
 * @buff_ind: interger
 * Return: number of int
 */
int print_interger(int value, char buffer[], int buff_ind)
{
	return buff_ind;
}
/**
 * printf_buffer - program to print buffer
 * @buffer: array of buffeer
 * @buff_ind: pointer of int
 * Return: nil
 */
void print_buffer(char buffer[], int *buff_ind)
{
	int i;

	if (*buff_ind > 0)
	{
		for (i = 0; i < *buff_ind; i++)
		{
		_putchar(buffer[i]);
		}
	}

	*buff_ind = 0;
}
