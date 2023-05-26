#include "monty.h"
/**
 **_realloc -  Reallocates A Memory Block Using Malloc And Free
 *@ptr: Pointer
 *@size_o: Previous Size Of The Pointer
 *@size_n: New Size Of The Pointer
 *Return: Void Pointer Rellocated Memory
 */
void *_realloc(void *ptr, unsigned int size_o, unsigned int size_n)
{
	void *result;

	if (size_n == size_o)
		return (ptr);
	if (size_n == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	result = malloc(size_n);
	if (result == NULL)
		return (NULL);
	if (ptr == NULL)
	{
		fill_an_array(result, '\0', size_n);
		free(ptr);
	}
	else
	{
		_memcpy(result, ptr, size_o);
		free(ptr);
	}
	return (result);

}
/**
 * _memcpy - Copy Byte From Source To Destination
 * @des_p: Destination Pointer
 * @sp: Source Pointer
 * @s: Size.
 *Return: Void Pointer
 */
char *_memcpy(char *des_p, char *sp, unsigned int s)
{
	unsigned int t;

	for (t = 0; t < s; t++)
	{
		des_p[t] = sp[t];
	}
	return (des_p);
}
/**
 * fill_an_array - Fill An Array By Constant Byte
 * @vp:Void Pointer
 * @el: Int
 * @leng:Length Int
 *Return: Void Pointer
 */
void *fill_an_array(void *vp, int el, unsigned int leng)
{
	char *p = vp;
	unsigned int t = 0;

	while (t < leng)
	{
		*p = el;
		p++;
		t++;
	}
	return (vp);
}
/**
 * _isdigit - checks for a digit from 0 to 9
 * @s: the integer to be checked
 *
 * Return: 1 if is digit, 0 otherwise
 */
int _isdigit(char *s)
{
	int t = 0;

	if (s == NULL)
		return (1);
	while (s[t])
	{
		if (isdigit(*s) == 0)
			return (1);
		t++;
	}
	return (0);
}

