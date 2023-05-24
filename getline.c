#include "shell.h"
/**
 * _getline - getline for shell
 *
 * Return:void
 *
 **/
void _getline(void)
{
	char *cmd = NULL;
	size_t n;

	printf("#cisfun$ ");
	if (getline(&cmd, &n, stdin) == -1)
	{
		free(cmd);
		exit(0);
	}
	tokenizer(cmd);
}
