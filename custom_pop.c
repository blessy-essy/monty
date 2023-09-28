#include "monty.h"
#include <stdio.h>

/**
 * custom_pop - removes the top element of the stack
 * @custom_stack: double-pointer denoting the custom_stack
 * @custom_line_index: line index in the file
 *
 * Description: If the stack is empty, print the error message
 * Return: void
 */
void custom_pop(stack_t **custom_stack, unsigned int custom_line_index)
{
	stack_t *ptr;

	if (*custom_stack == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", custom_line_index);
		exit(EXIT_FAILURE);
	}

	ptr = *custom_stack;
	*custom_stack = (*custom_stack)->next;
	free(ptr);
}
