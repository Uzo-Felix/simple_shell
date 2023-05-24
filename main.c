#include "main.h"
/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0
 */
int main(int ac, char **av)
{
	info_t info[] = { INFO_INIT };
	int x = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (x)
		: "r" (x));

	if (ac == 2)
	{
		x = open(av[1], O_RDONLY);
		if (x == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = x;
	}
	/*populate_env_list(info);
	read_history(info);
	hsh(info, av);*/
	return (EXIT_SUCCESS);
}
