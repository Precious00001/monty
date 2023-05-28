#include "monty.h"
/**
 * f_pstr - prints the string starting at the top of the stack,
 * followed by a new
 * @head: stack head
 * @line_n: line_number
 * Return: no return
*/
void f_pstr(stack_t **head, unsigned int line_n)
{
	stack_t *t;
	(void)line_n;

	t = *head;
	while (t)
	{
		if (t->n > 127 || t->n <= 0)
		{
			break;
		}
		printf("%c", t->n);
		t = t->next;
	}
	printf("\n");
}

