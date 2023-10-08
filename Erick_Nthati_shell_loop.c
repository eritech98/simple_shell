#include "main.h"

/**
 * without_comment_n - Deletes comments from the input
 *
 * @in: input string_
 * Return: input without comments
 */
char *without_comment_n(char *in)
{
	int e, up_to;

	up_to = 0;
	for (e = 0; in[e]; e++)
	{
		if (in[e] == '#')
		{
			if (e == 0)
			{
				free(in);
				return (NULL);
			}

			if (in[e - 1] == ' ' || in[e - 1] == '\t' || in[e - 1] == ';')
				up_to = e;
		}
	}

	if (up_to != 0)
	{
		in = _realloc_n(in, e, up_to + 1);
		in[up_to] = '\0';
	}

	return (in);
}


/**
 * shell_loop_n - Loop of shell
 * @datash_n: data relevant (av, input, args)
 *
 * Return:void
 */
void shell_loop_n(data_shell_n *datash_n)
{
	int loop, e_eof;
	char *input_n;

	loop = 1;
	while (loop == 1)
	{
		write(STDIN_FILENO, "Erick&_Nthati_simple_shell", 28);
		input_n = read_line_n(&e_eof);
		if (e_eof != -1)
		{
			input_n = without_comment_n(input_n);
			if (input_n == NULL)
				continue;

			if (check_syntax_error_n(datash_n, input_n) == 1)
			{
				datash_n->status_n = 2;
				free(input_n);
				continue;
			}
			input_n = rep_var_n(input_n, datash_n);
			loop = split_commands_n(datash_n, input_n);
			datash_n->counter_n += 1;
			free(input_n);
		}
		else
		{
			loop = 0;
			free(input_n);
		}
	}
}
