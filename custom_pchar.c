#include "monty.h"

/**
 * custom_pchar -  displays the character from the custom_stack's top position
 * @custom_stack: double-pointer denoting the custom_stack
 * @custom_line_index: line index in the file
 * Return: void
 */
void custom_pchar(stack_t **custom_stack, unsigned int custom_line_index)
{
	if (*custom_stack == NULL)
	{
		dprintf(2, "L%u: can't pchar, custom_stack empty\n", custom_line_index);
		exit(EXIT_FAILURE);
	}

	if ((*custom_stack)->n < 32 || (*custom_stack)->n > 127)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", custom_line_index);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*custom_stack)->n);
}
