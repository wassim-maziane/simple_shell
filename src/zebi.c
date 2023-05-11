#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
int main(void)
{
	char *buffer = NULL;
	size_t n = 0;
	char *command = NULL;
	pid_t pid;
	int val;
	char *delim = "\n";
	
	printf("#cisfun$ ");
	getline(&buffer, &n, stdin);

	command = strtok(buffer, delim);
	char *argv[] = {buffer, NULL};
	pid = fork();
	if (pid == 0)
		val = execve(argv[0], argv, NULL);
	else
		wait(NULL);
	return (0);
}
