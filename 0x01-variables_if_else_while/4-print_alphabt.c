#include<stdio.h>

/**
* main - main function
*
* Return: 0 on success
*/
intmain(void)
{
int s = 97, e = 122;
while (s  <=  e)
{
if (s != 'q' && s != 'e')
putchar(s);
s++;
}
putchar('\n');
return (0);
}
