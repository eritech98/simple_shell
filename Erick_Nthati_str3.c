#include "main.h"

/**
 * rev_string_n - will reverses a string.
 * @string_n: The input string
 * Return: void.
 */

void rev_string_n(char *string_n)
{
	int count = 0, e, j;
	char *str, tempo;

	while (count >= 0)
	{
		if (string_n[count] == '\0')
			break;
		count++;
	}
	str = string_n;

	for (e = 0; e < (count - 1); e++)
	{
		for (j = e + 1; j > 0; j--)
		{
			tempo = *(str + j);
			*(str + j) = *(str + (j - 1));
			*(str + (j - 1)) = tempo;
		}
	}
}
