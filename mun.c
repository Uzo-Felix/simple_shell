#include "main.h"

/**
 * communal - returns true if shell is in communal mode
 * @info: struct address
 *
 * Return: 1 if in communal mode, 0 otherwise
 */
int communal(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * trotter - looks if char is a delimeter
 * @a: char to check
 * @delim: the deli str
 * Return: Returns 0
 */
int trotter(char a, char *delim)
{
	while (*delim)
		if (*delim++ == a)
			return (1);
	return (0);
}

/**
 *betta - looks for alphabet character
 *@q: The char to input
 *Return: 0
 */

int betta(int q)
{
	if ((q >= 'a' && q <= 'z') || (q >= 'A' && q <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *dot - it converts a str to int
 *@y: its str to be converted
 *Return: it gives no numbers in string and return 0
 */

int dot(char *y)
{
	int f, hint = 1, mark = 0, product;
	unsigned int answer = 0;

	for (f = 0;  y[f] != '\0' && mark != 2; f++)
	{
		if (y[f] == '-')
			hint *= -1;

		if (y[f] >= '0' && y[f] <= '9')
		{
			mark = 1;
			answer *= 10;
			answer += (y[f] - '0');
		}
		else if (mark == 1)
			mark = 2;
	}

	if (hint == -1)
		product = -answer;
	else
		product = answer;

	return (product);
}
