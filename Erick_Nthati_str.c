#include "main.h"

/**
 * _strcat_n - Concatenate two strings
 * @destiny: char ptr the dest of the copied str
 * @origin: const char pointer the source of str
 * Return: the destination
 */
char *_strcat_n(char *destiny, const char *origin)
{
	int e;
	int j;

	for (e = 0; destiny[e] != '\0'; e++)
		;

	for (j = 0; origin[j] != '\0'; j++)
	{
		destiny[e] = origin[j];
		e++;
	}

	destiny[e] = '\0';
	return (destiny);
}
/**
 * *_strcpy_n - Cpies the string pointed to by src.
 * @destiny: typ char pointer the dest of the copied str
 * @origin: Typ char ptr the source of str
 * Return: the destination.
 */

char *_strcpy_n(char *destiny, char *origin)
{

	size_t a_;

	for (a_ = 0; origin[a_] != '\0'; a_++)
	{
		destiny[a_] = origin[a_];
	}
	destiny[a_] = '\0';

	return (destiny);
}
/**
 * _strcmp_n - unction that compares two strings.
 * @str1: type 1 str compared
 * @str2: type 2 str compared
 * Return: 0.
 */

int _strcmp_n(char *str1, char *str2)
{
	int e;

	for (e = 0; str1[e] == str2[e] && str1[e]; e++)
		;

	if (str1[e] > str2[e])
		return (1);
	if (str1[e] < str2[e])
		return (-1);
	return (0);
}
/**
 * _strchr_n - Locates a character in a string,
 * @string_n: string.
 * @c: char
 * Return: the pointer to the first occurrence of the char c.
 */

char *_strchr_n(char *string_n, char c)
{
	unsigned int e = 0;

	for (; *(string_n + e) != '\0'; e++)
		if (*(string_n + e) == c)
			return (string_n + e);
	if (*(string_n + e) == c)
		return (string_n + e);
	return ('\0');
}
/**
 * _strspn_n - will get the len of a prefix sub str.
 * @string_n: initial Segment.
 * @accept: accepted Bytes.
 * Return: the number_of accepted bytes.
 */

int _strspn_n(char *string_n, char *accept)
{
	int e, j, bool;

	for (e = 0; *(string_n + e) != '\0'; e++)
	{
		bool = 1;
		for (j = 0; *(accept + j) != '\0'; j++)
		{
			if (*(string_n + e) == *(accept + j))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}
	return (e);
}
