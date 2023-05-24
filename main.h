#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <limits.h>
#include <fcntl.h>
#include <sys/stat.h>

int subtract(int p, int q);
int _mycd(info_t *);
int _myhelp(info_t *);
int _myexit(info_t *);
int _myalias(info_t *);
int _myhistory(info_t *);
int print_alias(list_t *node);
int set_alias(info_t *info, char *str);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);
ssize_t get_input(info_t *);
int bfree(void **);


void promptedd(char **av, char **env);
int _isalpha(int);
int _atoi(char *);
int interactive(info_t *);
int is_delim(char, char *);


/**
 *struct pop - it contains a inbuilt str
 *@type: it is the inbuilt flag
 *@func: func
 */
typedef struct pop
{
	char *type;
	int (*func)(info_t *);
} builtin_table;

#define READ_BUF_SIZE 1024
#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}
#define WRITE_BUF_SIZE 1024

/**
 *struct known - pseudo-args
 *@arg: str
 *@argv: arr of str
 *@path: str path
 *@argc: argu count
 *@line_count: err count
 *@err_num: error
 *@linecount_flag: linecount
 *@fname: filename
 *@env: environ
 *@environ: env gets LL env
 *@history: hist
 *@alias: name
 *@env_changed: envir
 *@status: last exec commandd
 *@cmd_buf: cmd_buf
 *@cmd_buf_type: the CMD_type
 *@readfd: read input line
 *@histcount: hist line
 */
typedef struct known
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t;


#define CMD_AND		2
#define CMD_CHAIN	3
#define CMD_NORM	0
#define CMD_OR		1
#define CONVERT_UNSIGNED	2
#define CONVERT_LOWERCASE	1
#define USE_STRTOK 0
#define USE_GETLINE 0


#endif

