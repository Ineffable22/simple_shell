#include "header.h"

/**
 * print_env - Prints the enviroment
 * @cmd: pointer of structure
 *
 * Return: 0 always if succeed
 */

int print_env(s_global *cmd)
{
	int i = 0;

	while (cmd->env[i])
	{
		printf("%s\n", cmd->env[i]);
		i++;
	}
	return (0);
}

/**
 * shell_printenv - Prints a single line of the enviroment
 * @cmd: pointer of structure
 *
 * Return: 0 always if succeed
 */

int shell_printenv(s_global *cmd)
{
	char *key = cmd->token[1];
	char *var = my_getenv(key, cmd->env, 1);

	write(1, var, strlen(var));
	write(1, "\n", 1);
	return (0);
}

/**
 * shell_setenv - Creates a value at the enviroment
 * @cmd: pointer of structure
 *
 * Return: 0 always if succeed
 */

int shell_setenv(s_global *cmd)
{
	char **new_env;
	char *new_variable;
	char *key = cmd->token[1];
	char *value = cmd->token[2];
	char *current = NULL;
	unsigned int len_env = 0;

	len_env = _dstrlen(cmd->env);
	/*----------------- if exists variable --------------*/
	current = my_getenv(key, cmd->env, 1);
	if (current != NULL)
	{
		new_env = _drealloc(cmd->env, len_env, 0, &current, 2);
		/* info - Free memory for old env assigned */
		if (cmd->band == 1)
			_free(cmd->env);
		/* info - New env assigned */
		cmd->env = new_env;
		cmd->band = 1;
	}
	/*---------- Start - New variable ---------*/
	/* info - IMPORT!! allocate memory */
	_concat(&new_variable, 3, key, "=", value);
	/*----------- Start - Modify environment ---------*/
	len_env = _dstrlen(cmd->env);
	new_env = _drealloc(cmd->env, len_env, 1, &new_variable, 1);
	free(new_variable);
	/* info - Free memory for old env assigned */
	if (cmd->band == 1)
		_free(cmd->env);
	/* info - New env assigned */
	cmd->env = new_env;
	cmd->band = 1;
	return (0);
}

/**
 * shell_unsetenv - Deletes a value at the enviroment
 * @cmd: pointer of structure
 *
 * Return: 0 always if succeed
 */

int shell_unsetenv(s_global *cmd)
{
	char **new_env;
	char **tmp_env = cmd->env;
	char *key = cmd->token[1];
	char *address = my_getenv(key, tmp_env, 1);
	size_t len_env = 0;
	char *message = "ERROR: Not exist the environment variable\n";

	if (!address)
		write(STDERR_FILENO, message, strlen(message));
	else
	{
		len_env = _dstrlen(tmp_env);
		new_env = _drealloc(cmd->env, len_env, 0, &address, 2);

		/* free memory for old env assigned */
		if (cmd->band == 1)
			_free(tmp_env);
		/* New env assigned */
		cmd->env = new_env;
		cmd->band = 1;
	}
	return (0);
}
