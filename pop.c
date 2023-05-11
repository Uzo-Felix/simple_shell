#include "main.h"
#include <sys/wait.h>
/**
 * prompt - display prompt
 * @av: the argument vector
 * @env: parameter environ
 *
 * Return: void
 */

void prompt(char **av, char **env)
{
	char *string = NULL;
	int x, status;
	size_t n = 0;
	ssize_t num_char;
	char *argv[] = {NULL, NULL};
	pid_t child_pid;

	while (1)
	{
		printf("cisfun$ ");
		num_char = getline(&string, &n, stdin);
		if (num_char == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}
		x = 0;
		while (string[x])
		{
			if (string[x] == '\n')
				string[x] = 0;
			x++;
		}
		argv[0] = string;
		child_pid = fork();
		if (child_pid == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, env) == -1)
				printf("%s: No such file or directory\n", av[0]);
		}
		else
			wait(&status);
	}
}
