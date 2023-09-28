#include "monty.h"
void empty(void);
monty_globals_t global = {{NULL}, NULL, NULL};
/**
 * main - the entry point of Monty Interpreter
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */
int main(int argc, char **argv)
{
	int num_chars = 0;
	unsigned int custom_line_index = 1;
	char *filename;
	size_t line_buf_size = 0;
	void (*get_op_func)(stack_t **, unsigned int);
	stack_t *stack = NULL;
	stack_t *temp_stack;

	filename = argv[1];
	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	global.fptr = fopen(filename, "r");
	if (global.fptr == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((num_chars = getline(&global.line, &line_buf_size, global.fptr)) != -1)
	{
		parse_line(global.line);

		if (token.list[0] == NULL || token.list[0][0] == '#')
		{
			custom_line_index++;
			continue;
		}

		get_op_function = op_function(token.list[0]);
		if (get_op_function == NULL)
		{
			dprintf(2, "L%u: unknown instruction %s\n", custom_line_index,
					token.list[0]);
			exit_status_codes();
		}

		get_op_func(&stack, custom_line_index);
		custom_line_index++;
	}

	temp_stack = stack;
	while (temp_stack != NULL)
	{
		stack = temp_stack->next;
		free(temp_stack);
		temp_stack = stack;
	}

	free(global.line);
	fclose(global.fptr);

	return (0);
}
