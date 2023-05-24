#include "main.h"

/**
 * interactive - it returns true
 * @info: it struct
 *
 * Return: it returns 1 if interactive mode
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - it check delimeter
 * @p: its char
 * @delim: the string
 * Return: 0
 */
int is_delim(char p, char *delim)
{
	while (*delim)
		if (*delim++ == p)
			return (1);
	return (0);
}

/**
 *_isalpha - looks alpha
 *@p: char
 *Return: 0
 */

int _isalpha(int p)
{
	if ((p >= 'a' && p <= 'z') || (p >= 'A' && p <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - it converts str
 *@y: str
 *Return: 0 if no numbers in string
 */

int _atoi(char *y)
{
	int a, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (a = 0;  y[a] != '\0' && flag != 2; a++)
	{
		if (y[a] == '-')
			sign *= -1;

		if (y[a] >= '0' && y[a] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (y[a] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
