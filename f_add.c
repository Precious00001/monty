#include "monty.h"
/**
 * f_add - adds the top two elements of the stack.
 * @head: stack head
 * @line_n: line_number
 * Return: no return
*/
void f_add(stack_t **head, unsigned int line_n)
{
	stack_t *t;
	int len = 0, aux;

	t = *head;
	while (t)
	{
		t = t->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_n);
		fclose(bus.file);
		free(bus.ln);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	t = *head;
	aux = t->n + t->next->n;
	t->next->n = aux;
	*head = t->next;
	free(t);
}

