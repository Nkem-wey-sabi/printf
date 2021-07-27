#include "holberton.h"

/**
 * parser - recieves the argument list, functions and specifiers to print a formatted 
 * string
 *
 * @format: A string containing all the desired characters.
 *
 * @function_list: A list of all the possible functions.
 *
 * @arg_list: List of arguments passed to the program
 *
 * Return: number of printed characters.
 */
int parser(const char *format, conver_t function_list[], va_list arg_list)
{
	int i, j, r_val, char_no;

	char_no = 0;
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%') /*Checks for format specifiers*/
		{
			for (j = 0; function_list[j].sym != NULL; j++)
			{
				if (format[i + 1] == function_list[j].sym[0])
				{
					r_val = function_list[j].f(arg_list);
					if (r_val == -1)
						return (-1);
					char_no += r_val;
					break;
				}
			}
			if (function_list[j].sym == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_putchar(format[i]);
					_putchar(format[i + 1]);
					char_no = char_no + 2;
				}
				else
					return (-1);
			}
			i = i + 1; 
		}
		else
		{
			_putchar(format[i]); 
			char_no++;
		}
	}
	return (char_no);
}
