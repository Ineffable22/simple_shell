#include "header.h"

/**
 * my_getenv - searches a key string into the enviroment
 * @key: value to search into the enviroment as string
 * @env: dynamic value set with names
 * @mood: bool value for print the enviroment
 *
 * Return: the value on succeed or NULL on failure
 */

char *my_getenv(char *key, char **env, int mood)
{
	char **tmp_env, *value;
	unsigned int i = 0;

	tmp_env = env;
	while (*tmp_env != NULL)
	{
		value = *tmp_env;
		i = 0;
		while (*(key + i) == *(value + i))
			i++;
		if (i == strlen(key))
		{
			value = (mood == 0) ? (value + i + 1) : value;
			return (value);
		}
		tmp_env++;
	}
	return (NULL);
}

/**
 * _dstrlen - Calculates the size of the string of a double pointer
 * @ptr: double pointer
 *
 * Return: the size of the string of the double pointer
 */

unsigned int _dstrlen(char **ptr)
{
	unsigned int len = 0;

	while (*(ptr + len) != NULL)
		len++;

	return (len);
}

/**
 * _free - Frees the double pointer
 * @ptr: double pointer
 */

void _free(char **ptr)
{
	int pos = 0;

	while (*(ptr + pos))
	{
		free(*(ptr + pos));
		pos++;
	}
	free(ptr);
}

/**
 * _drealloc - Reallocates memory depending on flags
 * @src: source of the enviroment
 * @size: size of the enviroment
 * @add: number of mallocs to make
 * @list: adress of the aditional values
 * @mood: type of malloc to make
 *
 * Return: The new enviroment with the given additional values
 */

char **_drealloc(char **src, size_t size, size_t add, char **list, int mood)
{
	char **_new;
	size_t len = 0;
	int i = 0, n_str;

	n_str = (mood == 2) ? (size + add) : (size + add + 1);
	_new = malloc(sizeof(char *) * n_str);
	/* copy and paste */
	if (mood < 3)
	{
		while (*src)
		{
			len = 0;
			if (mood == 2 && *src == *list)
			{
				src++;
				continue;
			}
			len = strlen(*src) + 1;
			_new[i] = malloc(sizeof(char) * len);
			strcpy(_new[i], *src);
			i++;
			src++;
		}
	}
	/* additional elements */
	if (mood == 1)
	{
		while (add)
		{
			len = strlen(*list) + 1;
			_new[i] = malloc(sizeof(char) * len);
			strcpy(_new[i], *list);
			i++;
			list++;
			add--;
		}
	}
	_new[i] = NULL;
	return (_new);
}
