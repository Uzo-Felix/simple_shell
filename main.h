#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

void prompt(char **av, char **env);
int subtract(int p, int q);
void prompted(char **av, char **env);
char *_strtok(char *line, char *delim);
void string_long(long number, char *string, int base);
int vert(char *p);
int charac(char *string, char *character);







#endif

