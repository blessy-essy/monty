#include "monty.h"
/**
  *f_rotl- rotates the stack to the top
  *@custom_stack: double-pointer denoting the custom_stack
  *@custom_line_index: line index in the file
  *Return: void
 */
void f_rotl(stack_t **custom_stack,  unsigned int custom_line_index)
{
	stack_t *tmp = *custom_stack, *aux;

	if (*custom_stack == NULL || (*custom_stack)->next == NULL)
	{
		return;
	}
	aux = (*custom_stack)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *custom_stack;
	(*custom_stack)->next = NULL;
	(*custom_stack)->prev = tmp;
	(*custom_stack) = aux;
}
