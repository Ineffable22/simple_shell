#include "header.h"

/**
 * _concat - Concatenates the buffer with n arguments
 * @buff: saves a single line of the input
 * @n: number of arguments to enter
 */

void _concat(char **buff, int n, ...)
{
	char *save = NULL;
	char **arr;
	int pos = 0, len = 0;
	va_list ptr;

	va_start(ptr, n);
	/* info - IMPORT!! allocate memory */
	arr = malloc(sizeof(char *) * n);
	while (pos < n)
	{
		*(arr + pos) = va_arg(ptr, char *);
		save = *(arr + pos);
		len += strlen(save);
		pos++;
	}

	/* info - IMPORT!! allocate memory */
	*buff = malloc(sizeof(char) * (len + 1));
	strcpy(*buff, "");
	for (pos = 0; pos < n; pos++)
		strcat(*buff, *(arr + pos));

	free(arr);
	va_end(ptr);
}
