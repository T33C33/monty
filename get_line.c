#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream)
{
	char *buf;
	char *new_buf;
	size_t size, i = 0;
	int c;

	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		return -1;
	}

	buf = *lineptr;
	size = *n;

	if (buf == NULL)
	{
		size = 128;
		buf = malloc(size);
		if (buf == NULL)
		{
			return -1;
		}
	}

	while ((c = fgetc(stream)) != EOF)
	{
		if (i >= size - 1)
		{
			size *= 2;
			new_buf = realloc(buf, size);
			if (new_buf == NULL)
			{
				free(buf);
				return -1;
			}
			buf = new_buf;
		}

		buf[i++] = (char)c;

		if (c == '\n')
		{
			break;
		}
	}

	if (i == 0)
	{
		free(buf);
		return -1;
	}

	buf[i] = '\0';
	*lineptr = buf;
	*n = size;

	return i;
}
