#include "main.h"

/**
 * _myenv - it prints environ
 * @info: Struc
 *
 * Return: 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - it gets the value
 * @info: its Struc
 * @name: name
 *
 * Return: value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *x;

	while (node)
	{
		x = starts_with(node->str, name);
		if (x && *x)
			return (x);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - gives new environ
 * @info: Struct
 *
 *  Return: 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - takeout  envi var
 * @info: Struc
 *
 *  Return: 0
 */
int _myunsetenv(info_t *info)
{
	int c;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (c = 1; c <= info->argc; c++)
		_unsetenv(info, info->argv[c]);

	return (0);
}

/**
 * populate_env_list - it populates env list
 * @info: Struct
 *
 * Return: 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t c;

	for (c = 0; environ[c]; c++)
		add_node_end(&node, environ[c], 0);
	info->env = node;
	return (0);
}
