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
int outit(info_t *info);
int bet(info_t *info);
int buzz(info_t *info);
int record(info_t *info);
int name(info_t *info, char *str);
int named(info_t *info, char *str);
int nameedd(list_t *node);
int damed(info_t *info);

void promptedd(char **av, char **env);
char *_strtok(char *line, char *delim);
int communal(info_t *info);
int trotter(char a, char *delim);
int betta(int q);
int dot(char *y);


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





#endif

