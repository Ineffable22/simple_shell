#include "header.h"

/**
 * built_in - check cmd structure and prints their system calls
 * @argv: Array of arguments entered includes its name
 * @cmd: pointer of structure
 */

void built_in(char **argv, s_global *cmd)
{
	char buff[1024] = "/bin/";
	int i = 0, j = 0;
	int var_env = 0;
	pid_t child = 0;
	int status = 0;

	while (*(cmd->token[0] + i))
	{
		if (*(cmd->token[0] + i) == buff[i])
			j++;
		if (j == 5)
			break;
		i++;
	}
	child = fork();
	if (child == 0)
	{
		if (j != 5)
		{
			strcat(buff, cmd->token[0]);
			var_env = execve(buff, cmd->token, cmd->env);
		}
		else
		{
			var_env = execve(cmd->token[0], cmd->token, cmd->env);
		}
		if (var_env == -1)
		{
			printf("%s: No such file or directory\n", argv[0]);
		}
		free(cmd->token);
		kill(getpid(), SIGKILL);
	}
	else if (child > 0)
	{
		free(cmd->token);
		wait(&status);
	}
}

/**
 * my_getline - Reads and store the input console
 * @buff: saves a single line of the input
 * @len: size of the total input
 *
 * Return: count:size of buffer, var_flag_0:if EOF or 1, EOF:CRTL+D
 */

int my_getline(char **buff, int *len)
{
	char *tmp_buff = NULL;
	static char *save = NULL, flag = '0';
	static int count;
	int var_flag_0 = 0, var_flag_1 = 0;

	if (flag == '0')
	{
		save = malloc(sizeof(char) * 1021);
		if (save == NULL)
			return (EOF);
		*len = read(STDIN_FILENO, save, 1021);
		var_flag_0 = flag_0(save, len);
		if (var_flag_0 == EOF || var_flag_0 == 1)
		{
			flag =  '0';
			count = 0;
			return (var_flag_0);
		}
		count = var_flag_0;
		*buff = malloc(sizeof(char) * 1020);
		if (*buff == NULL)
		{
			free(save);
			return (EOF);
		}
	}
	if (flag == '1')
	{
		if (save[count] == 32)
		{
			while (save[count] == 32)
				count++;
		}
	}
	flag = '1', tmp_buff = *buff;
	var_flag_1 = flag_1(tmp_buff, save, count, len);
	if (var_flag_1 == 0)
		flag = '0';
	count = var_flag_1;
	return (count);
}

/**
 * flag_1 - checks if there is more than 1 buffer
 * @tmp_buff: pointer of the buffer
 * @save: saves the entire input
 * @count: static variable counter
 * @len: size of the total input
 *
 * Return: count:size of buffer
 */

int flag_1(char *tmp_buff, char *save, int count, int *len)
{
	while (save[count] != '\0')
	{
		*tmp_buff = save[count];
		if (save[count] == '\n')
		{
			save[count] = '\0';
			*tmp_buff = save[count];
			tmp_buff++;
			count++;
			break;
		}
		tmp_buff++;
		count++;
	}
	*tmp_buff = '\0';
	if (count >= *len)
	{
		free(save);
		count = 0;
	}
	return (count);
}

/**
 * flag_0 - checks if there are errors on the first buffer
 * @save: saves the entire input
 * @len: size of the total input
 *
 * Return: count:size of buffer, 1:if len=1 or if there are spaces, EOF:CRTL+D
 */

int flag_0(char *save, int *len)
{
		int count = 0;

		if (*len <= 0)
		{
			free(save);
			count = 0;
			return (EOF);
		}
		if (*len == 1)
		{
			free(save);
			count = 0;
			return (1);
		}
		if (save[count] == 32)
		{
			while (save[count] == 32)
			{
				count++;
				if (count + 1 == *len)
				{
					free(save);
					count = 0;
					*len = 1;
					return (1);
				}
			}
		}
		return (count);
}

/**
 * _strtok - Divides the buffer in tokens when it finds spaces
 * @buff: saves a single line of the input
 *
 * Return: the token as string or NULL if the string is empty
 */

char *_strtok(char *buff)
{
	int i = 0;
	char *set = NULL, *string = NULL;
	static char *save;

	buff = (buff) ? buff : save;
	set = buff;
	string = set;
	while (*string == ' ')
	{
		string++;
		set++;
	}
	while (*set != ' ' && *set != '\0' && *set != '\n')
	{
		set++;
		i++;
	}
	*set = '\0';
	set++;
	save = set;
	if (*string == '\0')
		return (NULL);
	return (string);
}
