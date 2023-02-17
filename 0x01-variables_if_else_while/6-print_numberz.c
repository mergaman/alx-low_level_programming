#include <stdio.h>

/**
 * main - main function
 *
 * Return: 0 on success
 */
int main(void)
{
	int s = 97, e = 122;

	while (e >= s)
	{
		putchar(e);
		e--;
	}

	putchar('\n');

	return (0);
}
