#include "monty.h"

/**
 * custom_pint - prints the value located at the top of the stack
 * @custom_stack: double-pointer denoting the custom_stack
 * @custom_line_index: line index in the file
 *
 * Description: displays the value at the top of the stack
 * Return: void
 */
void custom_pint(stack_t **custom_stack, unsigned int custom_line_index)
{
	if (*custom_stack == NULL)
	{
		dprintf(2, "L%u: can't pint, stack empty\n", custom_line_index);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*custom_stack)->n);
}
