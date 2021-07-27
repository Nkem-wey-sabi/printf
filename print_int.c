/**
 * print_int - outputs an integer
 *
 * @list_args: list of arguments
 *
 * Return: int.
 */
int print_int(va_list list_args)
{
	int len;

	len = print_number(list_args);
	return (len);
}
