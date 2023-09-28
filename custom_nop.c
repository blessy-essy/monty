#include "monty.h"

/**
 * custom_nop - doesn't do anything
 * @custom_stack: double-pointer denoting the custom_stack
 * @custom_line_index: line index in the file
 * Return: void
 */
void custom_nop(stack_t **custom_stack, unsigned int custom_line_index)
{
	(void) *custom_stack;
	(void) custom_line_index;
}
