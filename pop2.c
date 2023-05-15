#include "main.h"
#include <sys/wait.h>
#define MAX_COMMAND 10
/**
 * prompted - prompt function
 * @av: argument vector
 * @env: environ parameter
 *
 * Return: void
 */
void prompted(char **av, char **env)
{
	char *string = NULL;
	int q, p, status;
	size_t n = 0;
	ssize_t num_char;
	char *argv[MAX_COMMAND];
	pid_t child_pid;

	while (1)
	{
		(isatty(STDIN_FILENO)) ?
		(printf("cisfun$ "), num_char = getline(&string, &n, stdin)) : (0);
		if (num_char == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}
		q = 0;
		while (string[q])
		{
			(string[q] == '\n') ? (string[q] = 0, q++) : (0);
		}
		p = 0;
		argv[p] = strtok(string, "");
		while (argv[p])
			argv[++p] = strtok(NULL, "");
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

