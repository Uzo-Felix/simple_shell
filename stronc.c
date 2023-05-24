#include "main.h"

/**
 **_strncpy - it copy a str
 *@dest: destinatio
 *@src: str
 *@n: amount of chars
 *Return: s
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, p;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		p = i;
		while (p < n)
		{
			dest[p] = '\0';
			p++;
		}
	}
	return (s);
}

/**
 **_strncat - it concat two str
 *@dest: first one
 *@src: second str
 *@n: amount
 *Return: s
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, p;
	char *s = dest;

	i = 0;
	p = 0;
	while (dest[i] != '\0')
		i++;
	while (src[p] != '\0' && p < n)
	{
		dest[i] = src[p];
		i++;
		p++;
	}
	if (p < n)
		dest[i] = '\0';
	return (s);
}

/**
 **_strchr - it locates a char
 *@s: str
 *@c: char
 *Return: it returns (s) a pointer to memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
