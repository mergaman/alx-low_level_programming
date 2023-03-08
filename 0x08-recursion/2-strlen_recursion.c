#include "main.h"
/**
 * _strlen_recursion - gets the length of the string
 * @s: string whose length is to be calculated
 * Return: The length of the string
 */
int _strlen_recursion(char *s)
{
	return (*s ? (1 + _strlen_recursion(++s)) : 0);
}
