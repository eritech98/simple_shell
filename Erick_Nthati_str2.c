#include "main.h"

/**
 * _strdup_n - dplicates a str in the heap memory.
 * @string_n: type char pointer str
 * Return: Duplicated str
 */

char *_strdup_n(const char *string_n)
{
	char *new;
	size_t len;

	len = _strlen_n(string_n);
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	_memcpy_n(new, string_n, len + 1);
	return (new);
}

/**
 * _strlen_n - return the leng of a string.
 * @string_n: Type chatracter pointer
 * Return: 0.
 */

int _strlen_n(const char *string_n)
{
	int len;

	for (len = 0; string_n[len] != 0; len++)
	{
	}
	return (len);
}

/**
 * cmp_chars_n - will compare chars of strings
 * @str: input str.
 * @delimeter: delimiter.
 *
 * Return: 1 if are equals, 0 if not.
 */
int cmp_chars_n(char str[], const char *delimeter)
{
	unsigned int e, j, k;

	for (e = 0, k = 0; str[e]; e++)
	{
		for (j = 0; delimeter[j]; j++)
		{
			if (str[e] == delimeter[j])
			{
				k++;
				break;
			}
		}
	}
	if (e == k)
		return (1);
	return (0);
}

/**
 * _strtok_n - splits a str by some delimiter.
 * @str: input str.
 * @delimeter: delimiter.
 *
 * Return: string splited.
 */

char *_strtok_n(char str[], const char *delimeter)
{
	static char *splitted_n, *str_end_n;
	char *str_start_n;
	unsigned int e, bool;

	if (str != NULL)
	{
		if (cmp_chars_n(str, delimeter))
			return (NULL);
		splitted_n = str; /*Stores first address*/
		e = _strlen_n(str);
		str_end_n = &str[e]; /*Stores last address*/
	}
	str_start_n = splitted_n;
	if (str_start_n == str_end_n) /*Reaching The end*/
		return (NULL);


	for (bool = 0; *splitted_n; splitted_n++)/*Here*/
	{
		/*Breaking loop finding the token*/
		if (splitted_n != str_start_n)
			if (*splitted_n && *(splitted_n - 1) == '\0')
				break;
		/*Replacing delimit char*/
		for (e = 0; delimeter[e]; e++)
		{
			if (*splitted_n == delimeter[e])
			{
				*splitted_n = '\0';
				if (splitted_n == str_start_n)
					str_start_n++;
				break;
			}
		}
		if (bool == 0 && *splitted_n) /*Str != Delim*/
			bool = 1;
	}
	if (bool == 0) /*Str == Delim**/
		return (NULL);
	return (str_start_n);
}

/**
 * _isdigit_n - defines if s.tring passed is a number
 *
 * @string_n: input string..
 * Return: 1 if string is a number. 0 in other case.
 */

int _isdigit_n(const char *string_n)
{
	unsigned int e;

	for (e = 0; string_n[e]; e++)
	{
		if (string_n[e] < 48 || string_n[e] > 57)
			return (0);
	}
	return (1);
}
