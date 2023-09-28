#include "monty.h"
/**
  *f_rotr- rotates the stack to the bottom
  *@custom_stack: double-pointer denoting the custom_stack
  *@custom_line_index: line index in the file
  *Return: void
 */
void f_rotr(stack_t **custom_stack, unsigned int custom_line_index)
{
	stack_t *copy;

	copy = *custom_stack;
	if (*custom_stack == NULL || (*custom_stack)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *custom_stack;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*custom_stack)->prev = copy;
	(*custom_stack) = copy;
}
