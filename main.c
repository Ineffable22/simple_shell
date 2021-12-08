#include "header.h"
/**
 * main - Creates a simple shell
 * @argc: Number of arguments entered
 * @argv: Array of arguments entered includes its name
 * @env: dynamic value set with names
 *
 * Return: 0 always if success
 */

int main(int argc, char **argv, char **env)
{
	char *buffer = NULL;
	char a = 0;
	int len = 0;
	s_global cmd;

	cmd.env = env;
	cmd.band = 0;
	signal(SIGINT, signal_betty);
	if (argc < 1)
		return (0);
	while (a != EOF)
	{
		if (isatty(STDIN_FILENO))
			write(1, "#Cisfun$ ", 9);
		a = my_getline(&buffer, &len);
		if (a == 1)
		{
			continue;
		}
		if (a == EOF)
		{
			if (cmd.band == 1)
			{
				_free(cmd.env);
			}
			break;
		}
		if (exit_time(buffer) == 0)
		{
			if (cmd.band == 1)
				_free(cmd.env);
			free(buffer);
			break;
		}
		bypass(buffer, argv, &cmd);
		if (a == 0)
			free(buffer);
	}
	return (0);
}

/**
 * exit_time - compares buffer with "exit" ignoring spaces
 * @buffer: saves a single line of the input
 *
 * Return: 0 on succeed and 1 on failure
 */

int exit_time(char *buffer)
{
	int count = 0, flag = 0;
	char *exit = "exit";

	while (buffer[count])
	{
		if (buffer[count] != exit[count])
		{
			flag = 1;
			if (buffer[count] == 32)
			{
				while (buffer[count] == 32)
				{
					count++;
					if (buffer[count] == '\n' || buffer[count] == '\0')
					{
						return (0);
					}
				}
			}
			break;
		}
		count++;
	}
	if (flag == 0)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}

/**
 * bypass - controls the routes of the structure of cmd
 * @buff: saves a single line of the input
 * @argv: Array of arguments entered includes its name
 * @cmd: pointer of structure
 *
 * Return: 0 on succeed
 */

int bypass(char *buff, char **argv, s_global *cmd)
{
	int i = 0, count = 0;

	cmd->token = malloc(sizeof(char *) * 1024);
	if (cmd->token == NULL)
		return (0);

	while ((cmd->token[count] = _strtok(buff)) != NULL)
	{
		buff = NULL;
		count++;
		cmd->token[count] = NULL;
	}
	i = match(cmd);
	if (i == 0)
		free(cmd->token);
	if (i == -1)
	{
		built_in(argv, cmd);
	}
	return (0);
}

/**
 * signal_betty - prints \nCisfun$ after signal with betty style
 * @x: void argument
 */

void signal_betty(int x)
{
	(void) x;
	write(1, "\n#Cisfun$ ", 10);
}
