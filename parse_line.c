#include "monty.h"

/**
 * parse_line - break down the input line into tokens
 * @input_string: the string to tokenize
 * Return: void
 */
void parse_line(char *input_string)
{
	int num_count = 0;
	char *token = NULL;
	const char *delimiter = " \t\n\r";

	token = strtok(parse_line, delimiter);
	while (token != NULL)
	{
		token.list[num_count] = token;
		token = strtok(NULL, delimiter);
		num_count++;
	}
	token.list[num_count] = NULL;
}
