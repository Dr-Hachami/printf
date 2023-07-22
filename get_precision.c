#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: Pointer to the index in the format string
 * @list: List of arguments
 *
 * Return: Precision
 */
int get_precision(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int precision = -1;

	// Check if the next character after the current index is the precision specifier '.'
	if (format[curr_i] != '.')
		return (precision);

	precision = 0;

	// Loop through characters after the '.' to calculate the precision
	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		// If the current character is a digit, update the precision accordingly
		if (is_digit(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
		}
		// If the current character is '*', get the precision from the argument list
		else if (format[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(list, int);
			break;
		}
		// If the current character is not a digit or '*', break the loop
		else
			break;
	}

	// Update the index in the format string to the last character processed
	*i = curr_i - 1;

	return (precision);
}

