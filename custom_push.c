#include "monty.h"
#include <ctype.h>
#include <stdio.h>
/**
 * custom_push - pushes an element to the stack
 * @custom_stack: double-pointer denoting the custom_stack
 * @custom_line_index: line index in the file
 *
 * Description: adds an element into either the stack or the queue
 * Return: void
 */
void custom_push(stack_t **custom_stack, unsigned int custom_line_index)
{
	int custom_num_of_digits = 0;
	stack_t *custom_new_node;

	custom_new_node = malloc(sizeof(stack_t));
	if (custom_new_node == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (global.tokens[1] == NULL)
	{
		free(custom_new_node);
		dprintf(2, "L%u: usage: push integer\n", custom_line_index);
		exit_status();
	}
	if (global.tokens[1][0] == '-')
	{
		custom_num_of_digits++;
	}
	while (global.tokens[1][custom_num_of_digits] != '\0')
	{
		if (!isdigit(global.tokens[1][custom_num_of_digits]))
		{
			free(custom_new_node);
			dprintf(2, "L%u: usage: push integer\n", custom_line_index);
			exit_status();
		}
		custom_num_of_digits++;
	}
	custom_new_node->n = atoi(global.tokens[1]);
	custom_new_node->prev = NULL;
	custom_new_node->next = *custom_stack;
	if (*custom_stack != NULL)
	{
		(*custom_stack)->prev = custom_new_node;
	}
	*custom_stack = custom_new_node;
}
