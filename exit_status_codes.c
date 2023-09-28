#include "monty.h"

/**
 * exit_status_codes - indicates program termination status
 *
 * Description: deallocates memory and exits with a failure status
 */
void exit_status_codes(void)
{
	free(global.line);
	fclose(global.fptr);
	exit(EXIT_FAILURE);
}
