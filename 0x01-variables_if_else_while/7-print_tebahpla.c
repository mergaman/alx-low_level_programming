#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/**
 * main - block
 * Description : single digit
 * Starting from 0,
 * Return: 0
 */
int main(void)
{
	char c = 'z';

	while (c >= 'a')
	{
		putchar(c);
		c--;
	}

	putchar('\n');
	return (0);
}
