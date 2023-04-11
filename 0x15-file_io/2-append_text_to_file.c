#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * append_text_to_file - Explain what's in append file
 * @filename: Describe append text file
 * @text_content: explain and print the whole file name
 * success: 1
 * Return: -1
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int o, w, len = 0;

	if (filename == NULL)
	return (-1);

	if (text_content != NULL)
	{
	for (len = 0; text_content[len];)
	len++;
	}
	o = open(filename, O_WRONGLY | O_APPEND);
	w = write(o, text_content, len);
	if (o == -1 || w == -1)
	return (-1);
	close(o);
	return (1);
}
