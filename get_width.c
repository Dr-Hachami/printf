#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments
 * @i: Pointer to the index in the format string
 * @list: List of arguments
 *
 * Return: Width
 */
int get_width(const char *format, int *i, va_list list)
{
	int curr_i;
	int width = 0;

	// Loop through characters after the current index to calculate the width
	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		// If the current character is a digit, update the width accordingly
		if (is_digit(format[curr_i]))
		{
			width *= 10;
			width += format[curr_i] - '0';
		}
		// If the current character is '*', get the width from the argument list
		else if (format[curr_i] == '*')
		{
			curr_i++;
			width = va_arg(list, int);
			break;
		}
		// If the current character is not a digit or '*', break the loop
		else
			break;
	}

	// Update the index in the format string to the last character processed
	*i = curr_i - 1;

	return (width);
}

