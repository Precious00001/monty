#include "monty.h"
/**
 *push_use - push cmd error.
 */
void push_use(void)
{
	fprintf(stderr, "L%d: usage: push integer\n", info.l_num);
	free_info();
}
/**
 * pint_error - error.
 */
void pint_error(void)
{
	fprintf(stderr, "L%d: can't print, stack empty\n", info.l_num);
	free_info();
}
/**
 * pop_error - error.
 */
void pop_error(void)
{
	fprintf(stderr, "L%d: can't pop an empty stack\n", info.l_num);
	free_info();
}
/**
 * swap_error - error.
 */
void swap_error(void)
{
	fprintf(stderr, "L%d: can't swap, stack too short\n", info.l_num);
	free_info();
}

