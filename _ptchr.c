#include "monty.h"
/**
 * f_pchar - prints the char at the top of the stack,
 * followed by a new line
 * @head: stack head
 * @line_n: line_number
 * Return: no return
*/
void f_pchar(stack_t **head, unsigned int line_n)
{
	stack_t *t;

	t = *head;
	if (!t)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_n);
		fclose(bus.file);
		free(bus.ln);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (t->n > 127 || t->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_n);
		fclose(bus.file);
		free(bus.ln);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", t->n);
}

