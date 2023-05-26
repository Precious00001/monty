#include "monty.h"
/**
 * main - an interpreter for Monty ByteCodes files.
 * @ac: Argument Count
 * @av: Argument Value
 * Return: 0 or 1
 */
int main(int ac, char **av)
{
	info.type = LIFO;
	if (ac != 2)
		handle_error(2);
	else
	{
	treat_monty(av[1]);
	}
	return (EXIT_SUCCESS);
}

