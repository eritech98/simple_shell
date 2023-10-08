#include "main.h"

/**
 * get_len_n - Get the lenht of a number.
 * @n: type int num
 * Return: Len of a number.
 */

int get_len_n(int n)
{
	unsigned int n1;
	int lenght_ = 1;

	if (n < 0)
	{
		lenght_++;
		n1 = n * -1;
	}
	else
	{
		n1 = n;
	}
	while (n1 > 9)
	{
		lenght_++;
		n1 = n1 / 10;
	}

	return (lenght_);
}
/**
 * _itoa_n - a function converts int to string.
 * @n: type int num
 * Return: a String.
 */
char *_itoa_n(int n)
{
	unsigned int n1;
	int lenght_ = get_len_n(n);
	char *buffer;

	buffer = malloc(sizeof(char) * (lenght_ + 1));
	if (buffer == 0)
		return (NULL);

	*(buffer + lenght_) = '\0';

	if (n < 0)
	{
		n1 = n * -1;
		buffer[0] = '-';
	}
	else
	{
		n1 = n;
	}

	lenght_--;
	do {
		*(buffer + lenght_) = (n1 % 10) + '0';
		n1 = n1 / 10;
		lenght_--;
	}
	while (n1 > 0)
		;
	return (buffer);
}

/**
 * _atoi_n - onverts a string to an integer.
 * @string_n: input str
 * Return: int
 */

int _atoi_n(char *string_n)
{
	unsigned int count = 0, size_n = 0, oi = 0, pn = 1, m = 1, e;

	while (*(string_n + count) != '\0')
	{
		if (size_n > 0 && (*(string_n + count) < '0' || *(string_n + count) > '9'))
			break;

		if (*(string_n + count) == '-')
			pn *= -1;

		if ((*(string_n + count) >= '0') && (*(string_n + count) <= '9'))
		{
			if (size_n > 0)
				m *= 10;
			size_n++;
		}
		count++;
	}

	for (e = count - size_n; e < count; e++)
	{
		oi = oi + ((*(string_n + e) - 48) * m);
		m /= 10;
	}
	return (oi * pn);
}
