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
	char *buf;
	ssize_t fd;
	ssize_t w;
	ssize_t t;
	int fd;
	ssize_t nrd, nwr;

	if (!filename)
		return (0);
	fd = open(filename, 0_RDONLY);
	if (fd == -1)

	return (0);
}
