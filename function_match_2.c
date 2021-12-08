#include "header.h"

/**
 * shell_clear - Clears the console
 * @cmd: pointer of structure
 *
 * Return: 0 always if succeed
 */

int shell_clear(s_global * cmd __attribute__((unused)))
{
	system("clear");
	return (0);
}

/**
 * change_directory - Changes the directory
 * @cmd: pointer of structure
 *
 * Return: 0 always if succeed
 */

int change_directory(s_global *cmd)
{
	char path_dest[PATH_MAX] = "", path_old[PATH_MAX] = "", *save;

	getcwd(path_old, sizeof(path_old));
	/* info - search path home in environment */
	if (cmd->token[1] == NULL || *(cmd->token[1]) == '~')
	{
		save = my_getenv("HOME", cmd->env, 0);
		strcpy(path_dest, save);
		if (save != NULL)
			change_path(cmd, path_dest, path_old);
	}
	else if (*(cmd->token[1]) == '-')
	{
		save = my_getenv("OLDPWD", cmd->env, 0);
		strcpy(path_dest, save);
		if (save != NULL)
			change_path(cmd, path_dest, path_old);
	}
	else
	{
		if (*(cmd->token[1]) != '/')
			getcwd(path_dest, sizeof(path_dest));
		strcat(path_dest, "/");
		strcat(path_dest, cmd->token[1]);
		if (path_dest[0] != '\0')
			change_path(cmd, path_dest, path_old);
	}
	return (0);
}

/**
 * change_path - Changes the PATH
 * @cmd: pointer of structure
 * @pwd: path destiny
 * @old: previous path
 */

void change_path(s_global *cmd, char pwd[PATH_MAX], char old[PATH_MAX])
{
	if (chdir(pwd) == -1)
		printf("cd: %s: No such file or directory\n", pwd);
	else
	{
		cmd->token[1] = "PWD";
		cmd->token[2] = pwd;
		shell_setenv(cmd);
		cmd->token[1] = "OLDPWD";
		cmd->token[2] = old;
		shell_setenv(cmd);
	}
}
