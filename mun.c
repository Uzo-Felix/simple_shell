#include "main.h"

/**
 * string_long - it convert  num to a str.
 * @number: num to be converten.
 * @string: buffer to save.
 * @base: base
 *
 * Return: void.
 */
void string_long(long number, char *string, int base)
{
	int z = 0, a = 0;
	long d = number;
	char p[] = {"0123456789abcdef"};

	if (d == 0)
		string[z++] = '0';

	if (string[0] == '-')
		a = 1;

	while (d)
	{
		if (d < 0)
			string[z++] = p[-(d % base)];
		else
			string[z++] = p[d % base];
		d /= base;
	}
	if (a)
		string[z++] = '-';

	string[z] = '\0';
	str_reverse(string);
}


/**
 * _vert - it converts a str to int.
 *
 * @p: pointer.
 * Return: 0.
 */
int _vert(char *p)
{
	int w = 1;
	unsigned int number = 0;

	while (!('0' <= *p && *p <= '9') && *p != '\0')
	{
		if (*p == '-')
			w *= -1;
		if (*p == '+')
			w *= +1;
		p++;
	}

	while ('0' <= *p && *p <= '9' && *p != '\0')
	{

		number = (number * 10) + (*p - '0');
		p++;
	}
	return (number * w);
}

/**
 * charac_count - it count coincidences of character.
 *
 * @string: pointer
 * @character: it is string with  chars
 * Return: 0.
 */
int charac_count(char *string, char *character)
{
	int y = 0, j = 0;

	for (; string[y]; y++)
	{
		if (string[y] == character[0])
			j++;
	}
	return (j);
}
