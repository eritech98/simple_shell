#include "main.h"

/**
 * repeated_char_n - A fncounts the repetitions of a char
 *
 * @input_n: input string_
 * @e: index_
 * Return: repetitions_
 */


int repeated_char_n(char *input_n, int e)
{
	if (*(input_n - 1) == *input_n)
		return (repeated_char_n(input_n - 1, e + 1));

	return (e);
}

/**
 * error_sep_op_n - finds syntax errors_
 *
 * @input_n: input string
 * @e: index
 * @last: last charto be read
 * Return: will r index of error. 0 when there are no
 * errors
 */

int error_sep_op_n(char *input_n, int e, char last)
{
	int count;

	count = 0;
	if (*input_n == '\0')
		return (0);

	if (*input_n == ' ' || *input_n == '\t')
		return (error_sep_op_n(input_n + 1, e + 1, last));

	if (*input_n == ';')
		if (last == '|' || last == '&' || last == ';')
			return (e);

	if (*input_n == '|')
	{
		if (last == ';' || last == '&')
			return (e);

		if (last == '|')
		{
			count = repeated_char_n(input_n, 0);
			if (count == 0 || count > 1)
				return (e);
		}
	}

	if (*input_n == '&')
	{
		if (last == ';' || last == '|')
			return (e);

		if (last == '&')
		{
			count = repeated_char_n(input_n, 0);
			if (count == 0 || count > 1)
				return (e);
		}
	}

	return (error_sep_op_n(input_n + 1, e + 1, *input_n));
}

/**
 * first_char_n - finds index of the first chars
 *
 * @input_n: input string_9
 * @e: index_our
 * Return: r 1 if there is an error. 0 in other case.
 */

int first_char_n(char *input_n, int *e)
{

	for (*e = 0; input_n[*e]; *e += 1)
	{
		if (input_n[*e] == ' ' || input_n[*e] == '\t')
			continue;

		if (input_n[*e] == ';' || input_n[*e] == '|' || input_n[*e] == '&')
			return (-1);

		break;
	}

	return (0);
}

/**
 * print_syntax_error_n - prints when a syntax error is foundl
 *
 * @datash_n: our data structure
 * @input_n: our input string
 * @e: index of the error
 * @bool: to control msg error...
 * Return: no return
 */
void print_syntax_error_n(data_shell_n *datash_n,
		char *input_n, int e, int bool)
{
	char *msg, *msg2, *msg3, *error, *counter_n;
	int length_;

	if (input_n[e] == ';')
	{
		if (bool == 0)
			msg = (input_n[e + 1] == ';' ? ";;" : ";");
		else
			msg = (input_n[e - 1] == ';' ? ";;" : ";");
	}

	if (input_n[e] == '|')
		msg = (input_n[e + 1] == '|' ? "||" : "|");

	if (input_n[e] == '&')
		msg = (input_n[e + 1] == '&' ? "&&" : "&");

	msg2 = ": Syntax error: \"";
	msg3 = "\" unexpected\n";
	counter_n = _itoa_n(datash_n->counter_n);
	length_ = _strlen_n(datash_n->av_n[0]) + _strlen_n(counter_n);
	length_ += _strlen_n(msg) + _strlen_n(msg2) + _strlen_n(msg3) + 2;

	error = malloc(sizeof(char) * (length_ + 1));
	if (error == 0)
	{
		free(counter_n);
		return;
	}
	_strcpy_n(error, datash_n->av_n[0]);
	_strcat_n(error, ": ");
	_strcat_n(error, counter_n);
	_strcat_n(error, msg2);
	_strcat_n(error, msg);
	_strcat_n(error, msg3);
	_strcat_n(error, "\0");

	write(STDERR_FILENO, error, length_);
	free(error);
	free(counter_n);
}

/**
 * check_syntax_error_n - intermediate flunction to
 * find and print a syntax err
 *
 * @datash_n:Our data structure
 * @input_n: input string...
 * Return: 1 if there is an error. 0 in other case
 */

int check_syntax_error_n(data_shell_n *datash_n, char *input_n)
{
	int begin = 0;
	int f_char = 0;
	int e = 0;

	f_char = first_char_n(input_n, &begin);
	if (f_char == -1)
	{
		print_syntax_error_n(datash_n, input_n, begin, 0);
		return (1);
	}

	e = error_sep_op_n(input_n + begin, 0, *(input_n + begin));
	if (e != 0)
	{
		print_syntax_error_n(datash_n, input_n, begin + e, 1);
		return (1);
	}

	return (0);
}
