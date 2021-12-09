#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>
#include <signal.h>
#include <sys/syscall.h>
#include <limits.h>
#include<stdarg.h>

/*--------------------------------*/

/**
 * struct Global - Stores the global variables
 * @token: double pointer to token
 * @env: double pointer to enviroment
 * @band: global flag
 *
 * Description: This structures helps us to store variables globally
 */

typedef struct Global
{
	char **token;
	char **env;
	int band;
} s_global;

/**
 * struct Tags - Stores pointer functions
 * @c: store the string to match
 * @f: stores the functions to use
 *
 * Description: Structure that stores strings to match and functions to use
 */

typedef struct Tags
{
	char *c;
	int (*f)(s_global *);
} tags;

/*---------------------main.c---------------------*/
int bypass(char *buff, char **argv, s_global *cmd);
int exit_time(s_global *cmd);
void signal_betty(int x);
/*-------------------built_in.c-------------------*/
void built_in(char **argv, s_global *cmd);
int my_getline(char **buff, int *len);
int flag_0(char *save, int *len);
int flag_1(char *tmp_buff, char *save, int count, int *len);
char *_strtok(char *buff);
/*--------------------match.c--------------------*/
int match(s_global *);
void function_fork(s_global *cmd, char *buff, int j);
/*--------------------function_match_1.c----------*/
int print_env(s_global *cmd);
int shell_printenv(s_global *cmd);
int shell_setenv(s_global *cmd);
int shell_unsetenv(s_global *cmd);
/*--------------------function_match_2.c----------*/
int shell_clear(s_global *cmd);
int change_directory(s_global *cmd);
void change_path(s_global *cmd, char pwd[PATH_MAX], char old[PATH_MAX]);
/*--------------------function_help_1.c----------*/
void _concat(char **buff, int n, ...);
/*--------------------function_help_1.c----------*/
char *my_getenv(char *key, char **env, int mood);
unsigned int _dstrlen(char **ptr);
void _free(char **ptr);
char **_drealloc(char **src, size_t size, size_t add, char **list, int mood);

#endif
