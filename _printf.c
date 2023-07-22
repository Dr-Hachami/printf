#include "main.h"

#define BUFF_SIZE 1024 // Assuming BUFF_SIZE is defined somewhere

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
			{
				print_buffer(buffer, &buff_ind);
				/* write(1, buffer, buff_ind); */ // Alternative to print_buffer
			}
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind); // Print any existing characters in the buffer
			flags = get_flags(format, &i); // Extract flags from the format
			width = get_width(format, &i, list); // Extract width from the format
			precision = get_precision(format, &i, list); // Extract precision from the format
			size = get_size(format, &i); // Extract size from the format
			++i; // Move to the next character after '%'
			// Handle the conversion specifier and store the number of characters printed
			printed = handle_print(format, &i, list, buffer, flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind); // Print any remaining characters in the buffer

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exists
 * @buffer: Array of chars
 * @buff_ind: Index at which to add the next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, buffer, *buff_ind); // Write the characters in the buffer to the output

	*buff_ind = 0; // Reset the buffer index after printing
}

