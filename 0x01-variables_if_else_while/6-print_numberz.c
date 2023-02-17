#include <stdio.h>
/**
 * main - main function
 * Description: single digit
 * Return: 0 on success
 */
int main(void)
{
	int c = 0;

	while (c < 10)
	{
		putchar(48 + c);
		c++;
	}

	putchar('\n');
	return (0);
}
