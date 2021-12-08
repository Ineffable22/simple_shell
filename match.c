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
