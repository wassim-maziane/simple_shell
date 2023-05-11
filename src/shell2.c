#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
	char *buffer = NULL;
	size_t n = 0;
	char *command = NULL;
	char *real_command = NULL;
	char *folder;
	pid_t pid;
	int val;
	char *delim = "\n";
	
	folder = strdup("/bin/");
	printf("#cisfun$ ");
	command = malloc(sizeof(command) + sizeof("/bin/"));
	getline(&buffer, &n, stdin);
	command = strcat(folder,buffer);
	real_command = strtok(command, delim);
	char *argv[] = {real_command, NULL};
	pid = fork();
	if (pid == 0)
		val = execve(argv[0], argv, NULL);
	free(command);
	return (0);
}
