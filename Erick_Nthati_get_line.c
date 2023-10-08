#include "main.h"

/**
 * bring_line_n - Assigns the line var for get_line
 * @line_ptr: buffer that store the input str
 * @buffer: string that is been called to line
 * @n: line size
 * @j: size of buffer
 */

void bring_line_n(char **line_ptr, size_t *n, char *buffer, size_t j)
{

	if (*line_ptr == NULL)
	{
		if  (j > NTHATI)
			*n = j;

		else
			*n = NTHATI;
		*line_ptr = buffer;
	}
	else if (*n < j)
	{
		if (j > NTHATI)
			*n = j;
		else
			*n = NTHATI;
		*line_ptr = buffer;
	}
	else
	{
		_strcpy_n(*line_ptr, buffer);
		free(buffer);
	}
}
/**
 * get_line_n - Reads inpt_n from stream
 * @line_ptr: buffer that stores the input
 * @n: size of lineptr
 * @stream: Stream to read from
 * Return: number of bytes
 */

ssize_t get_line_n(char **line_ptr, size_t *n, FILE *stream)
{
	int e;
	static ssize_t input_n;
	ssize_t retval;
	char *buffer;
	char t = 'z';

	if (input_n == 0)
		fflush(stream);
	else
		return (-1);
	input_n = 0;

	buffer = malloc(sizeof(char) * NTHATI);
	if (buffer == 0)
		return (-1);
	while (t != '\n')
	{
		e = read(STDIN_FILENO, &t, 1);
		if (e == -1 || (e == 0 && input_n == 0))
		{
			free(buffer);
			return (-1);
		}
		if (e == 0 && input_n != 0)
		{
			input_n++;
			break;
		}
		if (input_n >= NTHATI)
			buffer = _realloc_n(buffer, input_n, input_n + 1);
		buffer[input_n] = t;
		input_n++;
	}
	buffer[input_n] = '\0';
	bring_line_n(line_ptr, n, buffer, input_n);
	retval = input_n;
	if (e != 0)
		input_n = 0;
	return (retval);
}
