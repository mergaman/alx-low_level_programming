#include "main.h"
#include <stdlib.h>
#include <stdio.h>


/**
 * read_textfile - print text file to STDOUT.
 * @filename: folder created for file
 * @letters: make sure to read A to Z
 * success: 1
 * Return: 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t o;
	ssize_t r;
	ssize_t w;

	if (filename == NULL)
	return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	return (0);

	o = open(filename, O_RDONLY);
	r = read(o, buffer, letters);
	w = write(STDOUT_FILENO, buffer, r);

	if (o == -1 || r == -1 || w != r)
	{
		free(buffer);
		return (0);
	}

	free(buffer);
	close(o);

	return (w);
}
