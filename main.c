#include "monty.h"

MontyInterpreter interpreter = {NULL, NULL, NULL, 0};
bus_t bus = {NULL, NULL, NULL, 0, 0};

int main(int argc, char *argv[])
{
	char *line;
	FILE *file;
	size_t size = 0;
	ssize_t read_result = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	interpreter.file = file;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (read_result > 0)
	{
		line = NULL;
		read_result = custom_getline(&line, &size, file);
		interpreter.content = line;
		counter++;

		if (read_result > 0)
		{
			execute(line, &stack, counter, file);
		}

		free(line);
	}

	free_stack(stack);
	fclose(file);
	return 0;
}
