#include "monty.h"

/**
 * custom_print_all - prints all the elements of a stack.
 * @custom_stack: double-pointer denoting the custom_stack
 * @custom_line_index: line index in the file
 *
 * Description: prints all the elements of a stack
 * Return: void
 */
void custom_print_all(stack_t **custom_stack, unsigned int custom_line_index)
{
	stack_t *custom_current;
	size_t custom_num = 0;

	(void)custom_line_index;
	custom_current = *custom_stack;
	if (custom_current == NULL)
	{
		return;
	}
	while (custom_current != NULL)
	{
		printf("%d\n", custom_current->n);
		custom_current = custom_current->next;
		custom_num++;
	}
}
