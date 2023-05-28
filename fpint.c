#include "monty.h"
/**
 * f_pint - prints the top
 * @head: stack head
 * @line_n: line_number
 * Return: no return
*/
void f_pint(stack_t **head, unsigned int line_n)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_n);
		fclose(bus.file);
		free(bus.ln);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

