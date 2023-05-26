#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <ctype.h>

#define DELIMITER " \n\t\a"
#define LIFO 1
#define FIFO 0

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int ln);
} instruction_t;

/**
 * struct info_s - Data From The Monty File
 * @cmd: Line From File
 * @a: Argument To Excute
 * @l_num: Line Number
 * @fp: File Descriptor
 * @file_n: File Name
 * @type: FIFO LIFO
 * Description: Information About The Commands In The Monty File
 */
typedef struct info_s
{
	FILE *fp;
	char *cmd;
	char *file_n;
	char **a;
	int l_num;
	int type;
} info_t;
extern info_t info;
/**
 * struct error - print error to stderr
 * @out:error code
 * @error_type:function to handle error
 */
typedef struct error
{
	int out;
	void (*error_type)(void);
} error_t;

void handle_error(int code);
void malloc_fail(void);
void monty_usage(void);
void push_use(void);
void unknown_command(void);
void file_perm(void);
void pint_error(void);
void pop_error(void);
void swap_error(void);
void add_error(void);
void sub_error(void);
void div_error(void);
void _zero(void);
void mul_error(void);
void mod_error(void);
void pchar_error(void);
void pchar_error_2(void);

int treat_monty(char *filename);
int split(void);
int excute_monty(stack_t **stack);

void push_monty(stack_t **stack, unsigned int ln);
void pall_monty(stack_t **stack, unsigned int ln);
void pint_monty(stack_t **stack, unsigned int ln);
void pop_monty(stack_t **stack, unsigned int ln);
void swap_monty(stack_t **stack, unsigned int ln);
void add_monty(stack_t **stack, unsigned int ln);
void nop_monty(stack_t **stack, unsigned int ln);
void sub_monty(stack_t **stack, unsigned int ln);
void div_monty(stack_t **stack, unsigned int ln);
void mul_monty(stack_t **stack, unsigned int ln);
void mod_monty(stack_t **stack, unsigned int ln);
void pchar_monty(stack_t **stack, unsigned int ln);
void pstr_monty(stack_t **stack, unsigned int ln);
void rotr_monty(stack_t **stack, unsigned int ln);
void rotl_monty(stack_t **stack, unsigned int ln);
void _queue(stack_t **stack, unsigned int ln);
void _stack(stack_t **stack, unsigned int ln);

void free_info(void);
void free_list(stack_t *stack);
void *_realloc(void *ptr, unsigned int size_o, unsigned int size_n);
char *_memcpy(char *des_p, char *sp, unsigned int s);
void *fill_an_array(void *vp, int el, unsigned int leng);
int _isdigit(char *s);
int dlistint_len(stack_t *stack);
int delete_dnodeint_at_index(stack_t **head, int index);
void add_node_fifo(stack_t **stack, stack_t *new_node);
void add_node_lifo(stack_t **stack, stack_t *new_node);


#endif
