#include "holberton.h"

/**
 * print_hex - prints a base 10 number in base 16
 *
 * @list: list of arguments
 *
 * Return: number of printed characters
 */
int print_hex(va_list list)
{
  unsigned int num;
  int len;
  int rem_num;
  char *hex_rep;
  char *rev_hex;
  
  num = va_arg(list, unsigned int);
  
  if (num == 0)
    return (_putchar('0'));
  if (num < 1)
    return (-1);
  len = base_length(num, 16);
  hex_rep = malloc(sizeof(char) * len + 1);
  if (hex_rep == NULL)
    return (-1);
  for (len = 0; num > 0; len++)
  {
    rem_num = num % 16;
    if (rem_num > 9)
    {
      rem_num = hex_check(rem_num, 'x');
      hex_rep[len] = rem_num;
    }
    else
      hex_rep[len] = rem_num;
      num = num / 16;
  }
  hex_rep[len] = '\0';
  rev_hex = rev_str(hex_rep);
  if (rev_hex == NULL)
    return (-1);
  _base(rev_hex);
  free(hex_rep);
  free(rev_hex);
  return (len);
}

/**
 * print_octal - prints a number in base 8
 * @list: list of arguments
 * Return: number of symbols printed to stdout
 */
int print_octal(va_list list)
{
  unsigned int num;
  int len;
  char *octal_rep;
  char *rev_s;
  
  num = va_arg(list, unsigned int);
  
  if (num == 0)
    return (_putchar('0'));
  if (num < 1)
    return (-1);
  len = base_length(num, 8);
  
  octal_rep = malloc(sizeof(char) * len + 1);
  if (octal_rep == NULL)
    return (-1);
  for (len = 0; num > 0; len++)
  {
    octal_rep[len] = (num % 8) + 48;
    num = num / 8;
  }
  
  octal_rep[len] = '\0';
  rev_s = rev_str(octal_rep);
  if (rev_s == NULL)
    return (-1);
  
  _base(rev_s);
  free(octal_rep);
  free(rev_s);
  return (len);
}

/**
 * hex_check - checks which hex function is calling it
 *
 * @num: number to convert into letter
 *
 * @x: Which hex function is calling
 *
 * Return: the ascii value of a letter
 */
int hex_check(int num, char x)
{
  char *hex = "abcdef";
  char *Hex = "ABCDEF";
  
  num = num - 10;
  if (x == 'x')
    return (hex[num]);
  else
    return (Hex[num]);
  return (0);
}

/**
 * print_heX - prints a decimal number in base 16 Uppercase
 *
 * @list: list of arguments
 *
 * Return: number of printe characters
 */
int print_heX(va_list list)
{
  unsigned int num;
  int len;
  int rem_num;
  char *hex_rep;
  char *rev_hex;
  
  num = va_arg(list, unsignedd int);
  
  if (num == 0)
    return (_putchar('\0'));
  if (num < 0)
    return (-1);
  len = base_length(num, 16);
  hex_rep = malloc(sizeof(char) * len + 1);
  if (hex_rep == NULL)
    return (-1);
  for (len = 0; num > 0; len++)
  {
    rem_num = num % 16;
    if (rem_num > 9)
    {
      rem_num = hex_check(rem_num, 'X');
      hex_rep[len] = rem_num;
    }
    hex_rep[len] = rem-num + 48;;
    num = num / 16;
  }
  hex_rep[len] = '\0';
  rev_hex = rev_str(hex_rep);
  
  if (rev_hex == NULL)
    return (-1);
  _base(rev_hex);
  free(hex_rep);
  free(rev_hex);
  return (len);
}
