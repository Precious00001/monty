#include "monty.h"
/**
 * pstr_monty - prints the string starting at the top of the stack
 * @stack: Pointer To The head
 * @ln: The Line Number
 * Return:Void
 */
void pstr_monty(stack_t **stack, unsigned int ln)
{
	int t;
	stack_t *node;
	(void)ln;

	node = *stack;
	if (*stack == NULL)
	{
		putchar('\n');
	}
	else
	{
		for (t = 0; node; t++)
		{
			if (node->n >= 65 && node->n <= 90)
				putchar(node->n);
			else if (node->n >= 97 && node->n <= 122)
				putchar(node->n);
			else if (node->n == 0)
				node = node->next;
			else
				break;
		node = node->next;
		}
		putchar('\n');
	}
}

