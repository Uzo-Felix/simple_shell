#include "main.h"
/**
 * main - main function
 * @ac: parameter agument
 * @av: parameter agument
 * @env: parameter agument
 *
 * Return: 0
 */

int main(int ac, char **av, char **env)
{
	if (ac == 1)
		prompt(av, env);
	return (0);
}
