#include "main.h"

/**
 * is_chain - it test for current char
 * @info: para struct
 * @buf: buf char
 * @p: address
 *
 * Return: 1
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t q = *p;

	if (buf[q] == '|' && buf[q + 1] == '|')
	{
		buf[q] = 0;
		q++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[q] == '&' && buf[q + 1] == '&')
	{
		buf[q] = 0;
		q++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[q] == ';')
	{
		buf[q] = 0;
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = q;
	return (1);
}

/**
 * check_chain - checks on last status
 * @info: struct
 * @buf: its char buf
 * @p: buf addres
 * @i: its position in buf
 * @len: len buf
 *
 * Return: Void
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t q = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			q = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			q = len;
		}
	}

	*p = q;
}

/**
 * replace_alias - function replace
 * @info: its p struct
 *
 * Return: 1
 */
int replace_alias(info_t *info)
{
	int a;
	list_t *node;
	char *p;

	for (a = 0; a < 10; a++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}

/**
 * replace_vars - function vars
 * @info: struct
 *
 * Return: 0
 */
int replace_vars(info_t *info)
{
	int a = 0;
	list_t *node;

	for (a = 0; info->argv[a]; a++)
	{
		if (info->argv[a][0] != '$' || !info->argv[a][1])
			continue;

		if (!_strcmp(info->argv[a], "$?"))
		{
			replace_string(&(info->argv[a]),
				_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[a], "$$"))
		{
			replace_string(&(info->argv[a]),
				_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[a][1], '=');
		if (node)
		{
			replace_string(&(info->argv[a]),
				_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[a], _strdup(""));

	}
	return (0);
}

/**
 * replace_string - func str replace
 * @old: addres
 * @new: new string
 *
 * Return: 1
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
