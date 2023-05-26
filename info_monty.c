#include "monty.h"
info_t info;
/**
 * treat_monty - Treat The Monty File
 * @filename: Filename From Argument
 * Return: Data Of The Monty File
 */
int treat_monty(char *filename)
{
	ssize_t n_r = 1;
	size_t len = 0;
	stack_t *stack = NULL;

	info.file_n = filename;
	info.fp = fopen(info.file_n, "r");
	if (info.file_n == NULL)
		handle_error(3);
	while ((n_r = getline(&info.cmd, &len, info.fp)) > 0)
	{
		if (*info.cmd == '\n')
			continue;
		info.l_num++;
		free(info.a);
		if (split() < 0)
			continue;
		if (info.a == NULL)
			continue;
		excute_monty(&stack);
	}
	free_info();
	free_list(stack);
	return (0);
}
/**
 * split - Split The Line Into Command and Arguments
 *
 *Return: 0 On Success 1 On Failure
 */
int split(void)
{
	char *token;
	size_t bufsize = 20, t = 0;

	info.a = malloc(bufsize * sizeof(char *));
	if (info.a == NULL)
		handle_error(1);
	token = strtok(info.cmd, DELIMITER);
	while (token)
	{
		info.a[t++] = token;
		if (t >= bufsize)
		{
			info.a = _realloc(info.a, bufsize, bufsize * 2);
			if (info.a == NULL)
			{
				handle_error(1);
			}
		}
		token = strtok(NULL, DELIMITER);
	}
	info.a[t] = NULL;
	if (**info.a == '#')
		return (-1);
	return (0);
}
#include "monty.h"
/**
 * excute_monty - Verifie Monty Command And Excute it
 * @stack: Stack or Queue
 * Return: 0 On Valid Command 1 On Commant Not Found
 */
int excute_monty(stack_t **stack)
{
	instruction_t command[] = {
		{"push", push_monty},
		{"pall", pall_monty},
		{"pint", pint_monty},
		{"pop", pop_monty},
		{"swap", swap_monty},
		{"add", add_monty},
		{"nop", nop_monty},
		{"sub", sub_monty},
		{"div", div_monty},
		{"mul", mul_monty},
		{"mod", mod_monty},
		{"#", nop_monty},
		{"pchar", pchar_monty},
		{"pstr", pstr_monty},
		{"rotl", rotl_monty},
		{"rotr", rotr_monty},
		{"stack", _stack},
		{"queue", _queue},
		{NULL, NULL}
	};
	int t = 0;

	while ((command + t)->opcode)
	{
		if (strcmp((command + t)->opcode, *info.a) == 0)
		{
			(command + t)->f(stack, info.l_num);
			return (0);
		}
		t++;
	}
	handle_error(4);
	return (1);
}

