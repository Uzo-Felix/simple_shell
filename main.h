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
int record(info_t *info);
int name(info_t *info, char *str);
int named(info_t *info, char *str);
int nameedd(list_t *node);
int damed(info_t *info);

void promptedd(char **av, char **env);
char *_strtok(char *line, char *delim);
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

    /* toem_errors.c */
void _eputs(char *);
int _eputchar(char);
int _putfd(char a, int file_desc);
int _putsfd(char *str, int file_desc);

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

/* toem_pop3.c */
int isChainn(info_t *, char *, size_t *);
void checkChainn(info_t *, char *, size_t *, size_t, size_t);
int replaceAliass(info_t *);
int replaceVariables(info_t *);
int replaceStr(char **, char *);

/* toem_info.c */
void clearInfo(info_t *);
void setInfo(info_t *, char **);
void freeInfo(info_t *, int);

/*toem_line.c */
ssize_t get_inputt(info_t *);
int getlinee(info_t *, char **, size_t *);
void sigintHa(int);

#endif

