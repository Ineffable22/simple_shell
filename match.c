#include "header.h"

/**
 * match - Matches the input with the stored string
 * @cmd: pointer to structure
 *
 * Return: the result of the functions called or -1 on failure
 */
int match(s_global *cmd)
{
	int (*fu)(s_global *);
	int pos = 0, result = 0, s_c;

	tags flag_store[] = {
		{"env", print_env},
		{"cd", change_directory},
		{"setenv", shell_setenv},
		{"unsetenv", shell_unsetenv},
		{"printenv", shell_printenv},
		{"clear", shell_clear},
		{"exit", exit_time},
		{NULL, NULL}
	};

	while (flag_store[pos].c)
	{
		s_c = strcmp(cmd->token[0], flag_store[pos].c);
		if (s_c == 0)
		{
			fu = flag_store[pos].f;
			result = fu(cmd);
			return (result);
		}
		pos++;
	}
	return (-1);
}

/**
 * function_fork - Divides the process before executes the system call execve()
 * @cmd: pointer of structure
 * @buff: the concatenated token
 * @j: selector flag between the buffer and the token
 */

void function_fork(s_global *cmd, char *buff, int j)
{
	pid_t child = 0;
	int status = 0;

	child = fork();
	if (child == 0)
	{
		if (j == 5)
			execve(buff, cmd->token, cmd->env);
		else
			execve(cmd->token[0], cmd->token, cmd->env);
		free(cmd->token);
		kill(getpid(), SIGKILL);
	}
	else if (child > 0)
	{
		free(cmd->token);
		wait(&status);
	}
}
