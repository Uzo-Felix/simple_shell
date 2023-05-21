#include "main.h"
/**
 * _strtok - it separate str with delimiters
 * @line: pointer to array
 * @delim: characters
 * Return: Pointer
*/
char *_strtok(char *line, char *delim)
{
	int m;
	static char *s;
	char *pys;

	if (line != NULL)
		s = line;
	for (; *s != '\0'; s++)
	{
		for (m = 0; delim[m] != '\0'; m++)
		{
			if (*s == delim[m])
			break;
		}
		if (delim[m] == '\0')
			break;
	}
	pys = s;
	if (*pys == '\0')
		return (NULL);
	for (; *s != '\0'; s++)
	{
		for (m = 0; delim[m] != '\0'; m++)
		{
			if (*s == delim[m])
			{
				*s = '\0';
				s++;
				return (pys);
			}
		}
	}
	return (pys);
}
