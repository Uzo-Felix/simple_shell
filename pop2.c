#include "main.h"

/**
 * record - it displays the record list and line by one command
 * @info: its structure containing potential args
 *
 *  Return: 0
 */
int record(info_t *info)
{
	print_list(info->history);
	return (0);

/**
 * name - it sets names to str
 * @info: structure para
 * @str: its the string name
 *
 * Return: it returns 0 on success, 1 on error
 */
int name(info_t *info, char *str)
{
	char *r, z;
	int cet;

	r = _strchr(str, '=');
	if (!r)
		return (1);
	z = *r;
	*r = 0;
	cet = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*r = z;
	return (cet);
}

/**
 * named - gives names to str
 * @info: it is para structure
 * @str: its the str name
 *
 * Return: 0 on success and 1 on err
 */
int named(info_t *info, char *str)
{
	char *r;

	r = _strchr(str, '=');
	if (!r)
		return (1);
	if (!*++r)
		return (name(info, str));

	name(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * nameedd - it prints a named str
 * @node: the alias node
 *
 * Return: 0 on success and 1 on err
 */
int nameedd(list_t *node)
{
	char *r = NULL, *y = NULL;

	if (node)
	{
		r = _strchr(node->str, '=');
		for (y = node->str; y <= r; y++)
			_putchar(*y);
		_putchar('\'');
		_puts(r + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * damed - it imitates the alias builtn
 * @info: it is a struc containing potential argums
 *
 *  Return: 0
 */
int damed(info_t *info)
{
	int d = 0;
	char *r = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			nameedd(node);
			node = node->next;
		}
		return (0);
	}
	for (d = 1; info->argv[d]; d++)
	{
		r = _strchr(info->argv[d], '=');
		if (r)
			named(info, info->argv[d]);
		else
			nameedd(node_starts_with(info->alias, info->argv[d], '='));
	}

	return (0);
}
