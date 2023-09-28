#include "monty.h"

/**
 * custom_mul - multiplies second top element of custom_stack with top element
 * @custom_stack: double-pointer denoting the custom_stack
 * @custom_line_index: line index in the file
 * Return: void
 */
void custom_mul(stack_t **custom_stack, unsigned int custom_line_index)
{
	stack_t *custom_ptr2;

	if (*custom_stack == NULL || (*custom_stack)->next == NULL)
	{
		dprintf(2, "L%u: can't mul, custom_stack too short\n", custom_line_index);
		exit(EXIT_FAILURE);
	}

	custom_ptr2 = (*custom_stack)->next;
	custom_ptr2->n = custom_ptr2->n * (*custom_stack)->n;
	custom_pop(custom_stack, custom_line_index);
}
