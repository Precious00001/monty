#include "monty.h"
/**
 * f_push - add node to the stack
 * @head: stack head
 * @line_n: line_number
 * Return: no return
*/
void f_push(stack_t **head, unsigned int line_n)
{
	int n, k = 0, flag = 0;

	if (bus.v)
	{
		if (bus.v[0] == '-')
			k++;
		for (; bus.v[k] != '\0'; k++)
		{
			if (bus.v[k] > 57 || bus.v[k] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", line_n);
			fclose(bus.file);
			free(bus.ln);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", line_n);
		fclose(bus.file);
		free(bus.ln);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(bus.v);
	if (bus.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}

