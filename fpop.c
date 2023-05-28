#include "monty.h"
/**
 * f_pop - prints the top
 * @head: stack head
 * @line_n: line_number
 * Return: no return
*/
void f_pop(stack_t **head, unsigned int line_n)
{
	stack_t *t;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_n);
		fclose(bus.file);
		free(bus.ln);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	t = *head;
	*head = t->next;
	free(t);
}

