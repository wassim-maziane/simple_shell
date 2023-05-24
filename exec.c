#include "shell.h"
/**
 * exec - functions that handles executing commands
 * @argv: command
 *
 * Return: void
 */
void exec(char **argv)
{
	if (fork() == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
			perror("");
	}
	else
	{
		wait(NULL);
		_getline();
	}
}
