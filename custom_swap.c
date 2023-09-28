#include "monty.h"

/**
 * custom_swap - swaps top two stack elements
 * @custom_stack: double-pointer denoting the custom_stack
 * @custom_line_index: line index in the file
 *
 * Description: swaps top two stack elements, if stack has
 * less than two elements it prints an error message.
 * Return: void
 */
void custom_swap(stack_t **custom_stack, unsigned int custom_line_index)
{
	stack_t *custom_ptr2;
	stack_t *custom_ptr3;

	if (*custom_stack == NULL || (*custom_stack)->next == NULL)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", custom_line_index);
		exit(EXIT_FAILURE);
	}

	custom_ptr2 = (*custom_stack)->next;
	custom_ptr3 = (*custom_stack)->next->next;
	custom_ptr2->next = *custom_stack;
	(*custom_stack)->next = custom_ptr3;
	*custom_stack = custom_ptr2;
}
