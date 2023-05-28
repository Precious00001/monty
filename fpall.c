#include "monty.h"
/**
 * f_pall - prints the stack
 * @head: stack head
 * @num: no used
 * Return: no return
*/
void f_pall(stack_t **head, unsigned int num)
{
	stack_t *t;
	(void)num;

	t = *head;
	if (t == NULL)
		return;
	while (t)
	{
		printf("%d\n", t->n);
		t = t->next;
	}
}

