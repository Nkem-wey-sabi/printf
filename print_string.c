#include "holberton.h"

/**
 * print_string - outputs a string
 *
 * @list_args: List of arguments
 *
 * Return: number of characters printed
 */
int print_string(va_list list_args)
{
  int i; //Why i? Cause it's law.
  char *str;
  
  str = va_arg(list, char *);
  if (str == NULL)
      str = "(null)";
  for (i = ; str[i] != '\0'; i++)
    _putchar(str[i]);
  return (i);
}
