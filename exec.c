#include "monty.h"
/**
* execute - executes the opcode
* @stack: head linked list - stack
* @line_n: line_counter
* @file: poiner to monty file
* @ln: line content
* Return: no return
*/
int execute(char *ln, stack_t **stack, unsigned int line_n, FILE *file)
{
	instruction_t opst[] = {
				{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
				{"pop", f_pop},
				{"swap", f_swap},
				{"add", f_add},
				{"nop", f_nop},
				{"sub", f_sub},
				{"div", f_div},
				{"mul", f_mul},
				{"mod", f_mod},
				{"pchar", f_pchar},
				{"pstr", f_pstr},
				{"rotl", f_rotl},
				{"rotr", f_rotr},
				{"queue", f_queue},
				{"stack", f_stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(ln, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.v = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, line_n);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", line_n, op);
		fclose(file);
		free(ln);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}

