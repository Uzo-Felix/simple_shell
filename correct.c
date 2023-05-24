#include "main.h"

/**
 *_eputs - it prints input
 * @str: its str
 *
 * Return: it returns Nothing
 */
void _eputs(char *str)
{
	int c = 0;

	if (!str)
		return;
	while (str[c] != '\0')
	{
		_eputchar(str[c]);
		c++;
	}
}

/**
 * _eputchar - it writes the character
 * @c: charac
 *
 * Return: On success 1 and -1 on error
 */
int _eputchar(char c)
{
	static int d;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || d >= WRITE_BUF_SIZE)
	{
		write(2, buf, d);
		d = 0;
	}
	if (c != BUF_FLUSH)
		buf[d++] = c;
	return (1);
}

/**
 * _putfd - it writes the char c given fd
 * @c: char
 * @fd:filedescrip
 *
 * Return: On success 1.
 */
int _putfd(char c, int fd)
{
	static int d;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || d >= WRITE_BUF_SIZE)
	{
		write(fd, buf, d);
		d = 0;
	}
	if (c != BUF_FLUSH)
		buf[d++] = c;
	return (1);
}

/**
 *_putsfd - it prints str
 * @str: string to printed
 * @fd: its filedescripto
 *
 * Return: its num of char
 */
int _putsfd(char *str, int fd)
{
	int d = 0;

	if (!str)
		return (0);
	while (*str)
	{
		d += _putfd(*str++, fd);
	}
	return (d);
}
