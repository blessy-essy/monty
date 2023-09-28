#include "monty.h"
/**
 * custom_pstr - prints the string that begins at the top of the custom stack
 * followed by a newline
 * @custom_stack: double-pointer denoting the custom_stack
 * @custom_line_index: line index in the file
 * Return: void
 */
void custom_pstr(stack_t **custom_stack, unsigned int custom_line_index)
{
	stack_t *custom_ptr;

	(void) custom_line_index;
	custom_ptr = *custom_stack;
	while (custom_ptr != NULL && custom_ptr->n != 0 &&
			custom_ptr->n >= 0 && custom_ptr->n <= 127)
	{
		printf("%c", custom_ptr->n);
		custom_ptr = custom_ptr->next;
	}
	printf("\n");
}
