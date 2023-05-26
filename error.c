#include "monty.h"
/**
 * handle_error - print errors
 * @code: exit code
 */
void handle_error(int code)
{
	error_t er[] = {
		{1, malloc_fail},
		{2, monty_usage},
		{3, file_perm},
		{4, unknown_command},
		{5, push_use},
		{6, pint_error},
		{7, pop_error},
		{8, swap_error},
		{9, add_error},
		{10, sub_error},
		{11, div_error},
		{12, _zero},
		{13, mul_error},
		{14, mod_error},
		{0, NULL}
	};
	int t = 0;

	while ((er + t)->out)
	{
		if ((er + t)->out == code)
		{
			(er + t)->error_type();
			exit(EXIT_FAILURE);
		}
		t++;
	}
}
/**
 * malloc_fail - error in case malloc fail
 */
void malloc_fail(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	free_info();
}
/**
 * file_perm - error for no permession or can t open file
 */
void file_perm(void)
{
	fprintf(stderr, "Error: Can't open file %s\n", info.file_n);
}
/**
 * unknown_command - Unknown command error
 */
void unknown_command(void)
{
	fprintf(stderr, "L%d: unknown instruction %s\n",
			info.l_num, info.a[0]);
		free_info();
}

