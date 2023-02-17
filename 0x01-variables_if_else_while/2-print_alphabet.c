#include <stdio.h>

/**
 * main - main function
 *
 * Return: 0 on success
 */
int main(void)
{
	int s = 97, e = 122;

	while (s <= e)
	{
		putchar(s);
		s++;
	}

	putchar('\n');

	return (0);
}
