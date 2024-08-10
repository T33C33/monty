#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * read_line - reads an entire line from stream
 * @buf: pointer to the buffer where the read line will be stored
 * @size: pointer to the size of the buffer
 * @stream: input file stream to read from
 * Return: the number of characters read, or -1 on failure
 */
ssize_t read_line(char *buf, size_t size, FILE *stream)
{
	size_t i = 0;
	int c;
	char *new_buf;

	while ((c = fgetc(stream)) != EOF)
	{
		if (i >= size - 1)
		{
			size *= 2;
			new_buf = realloc(buf, size);

			if (new_buf == NULL)
			{
				free(buf);
				return (-1);
			}
			buf = new_buf;
		}
		buf[i++] = (char)c;
		if (c == '\n')
		{
			break;
		}
	}

	buf[i] = '\0';
	return (i);
}

/**
 * custom_getline - reads an entire line from stream
 * @lineptr: pointer to the buffer where the read line will be stored
 * @n: pointer to the size of the buffer
 * @stream: input file stream to read from
 * Return: the number of characters read, or -1 on failure
 */
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream)
{
	char *buf;
	size_t size;
	ssize_t result;

	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		return (-1);
	}

	buf = *lineptr;
	size = *n;

	if (buf == NULL)
	{
		size = 128;
		buf = malloc(size);
		if (buf == NULL)
		{
			return (-1);
		}
	}

	result = read_line(buf, size, stream);

	if (result == -1)
	{
		free(buf);
		return (-1);
	}

	*lineptr = buf;
	*n = size;
	return (result);
}
