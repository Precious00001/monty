#include "monty.h"
/**
 * rotl_monty -  rotates the stack to the top
 * @stack: Pointer To The head
 * @ln: The Line Number
 * Return:Void
 */
void rotl_monty(stack_t **stack, unsigned int ln)
{
	int tmp;
	stack_t *copy;

	(void)ln;

	if (stack && *stack)
	{
		tmp = (*stack)->n;

		for (copy = *stack; copy->next; copy = copy->next)
			copy->n = copy->next->n;
		copy->n = tmp;
	}
}
/**
 * rotr_monty - rotates the stack to the bottom.
 * @stack: Pointer To The head
 * @ln: The Line Number
 * Return:Void
 */
void rotr_monty(stack_t **stack, unsigned int ln)
{
	int next, current;
	stack_t *copy;

	(void)ln;

	if (stack && *stack)
	{
		copy = *stack;
		next = copy->n;

		while (copy->next)
		{
			current = next;
			next = copy->next->n;
			copy->next->n = current;
			copy = copy->next;
		}
		(*stack)->n = next;
	}
}
