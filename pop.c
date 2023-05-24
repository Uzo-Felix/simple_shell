#include "main.h"

/**
 * outit - goes out of the shell
 * @info: it is struc containing potential args
 *
 *  Return: it gives (0) if info.argv[0] != "exit"
 */
int outit(info_t *info)
{
	int goesout;

	if (info->argv[1])
	{
		goesout = _erratoi(info->argv[1]);
		if (goesout == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * bet - it changes the present dir of the process
 * @info: it is struc containing potential argus
 *
 *  Return: 0
 */
int bet(info_t *info)
{
	char *p, *rent, buffer[1024];
	int chdir_ret;

	p = getcwd(buffer, 1024);
	if (!p)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		rent = _getenv(info, "HOME=");
		if (!rent)
			chdir_ret = /* TODO: what should this be? */
				chdir((rent = _getenv(info, "PWD=")) ? rent : "/");
		else
			chdir_ret = chdir(rent);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(p);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((rent = _getenv(info, "OLDPWD=")) ? rent : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * buzz - it alters the current dir of the process
 * @info: it is structure containing potential argus
 *
 *  Return: 0
 */
int buzz(info_t *info)
{
	char **argum_arr;

	argum_arr = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*argum_arr);
	return (0);
}
