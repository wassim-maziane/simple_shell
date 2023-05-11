#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
/**
 * main - entry point
 *
 * Return: 0 (success)
 */
int main(void)
{
	char *buffer, *command, *delim = "\n";
	size_t n;
	pid_t pid;

	while (1)
	{
		buffer = NULL;
		n = 0;
		command = NULL;

		printf("#cisfun$ ");
		getline(&buffer, &n, stdin);

		command = strtok(buffer, delim);
		char *argv[] = {buffer, NULL};

		pid = fork();
		if (pid == 0)
		{
			execve(argv[0], argv, NULL);
			perror("./shell");
		}
		else if (pid > 0)
			wait(NULL);
		else
			perror("fork");
	}
	return (0);
}
