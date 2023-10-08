#include "main.h"

/**
 * swap_char_n - swaps | and & for non-printed chars
 *
 * @input_n: input string_
 * @bool: type of swap_
 * Return: swapped string_
 */
char *swap_char_n(char *input_n, int bool)
{
	int e;

	if (bool == 0)
	{
		for (e = 0; input_n[e]; e++)
		{
			if (input_n[e] == '|')
			{
				if (input_n[e + 1] != '|')
					input_n[e] = 16;
				else
					e++;
			}

			if (input_n[e] == '&')
			{
				if (input_n[e + 1] != '&')
					input_n[e] = 12;
				else
					e++;
			}
		}
	}
	else
	{
		for (e = 0; input_n[e]; e++)
		{
			input_n[e] = (input_n[e] == 16 ? '|' : input_n[e]);
			input_n[e] = (input_n[e] == 12 ? '&' : input_n[e]);
		}
	}
	return (input_n);
}

/**
 * add_nodes_n - separators and command lines in the lists
 *
 * @head_s: hdead of separator list
 * @head_l: ,head of command lines list
 * @input_n: input string
 * Return: novoid return
 */
void add_nodes_n(sep_list_n **head_s, line_list_n **head_l, char *input_n)
{
	int e;
	char *line_n;

	input_n = swap_char_n(input_n, 0);

	for (e = 0; input_n[e]; e++)
	{
		if (input_n[e] == ';')
			add_sep_node_end_n(head_s, input_n[e]);

		if (input_n[e] == '|' || input_n[e] == '&')
		{
			add_sep_node_end_n(head_s, input_n[e]);
			e++;
		}
	}

	line_n = _strtok_n(input_n, ";|&");
	do {
		line_n = swap_char_n(line_n, 1);
		add_line_node_end_n(head_l, line_n);
		line_n = _strtok_n(NULL, ";|&");
	} while (line_n != NULL);

}

/**
 * go_next_n - go to next command line stored
 *
 * @list_s: separator_n list
 * @list_l: command lie list
 * @datash_n: data structure
 * Return: void
 */

void go_next_n(sep_list_n **list_s, line_list_n **list_l,
				data_shell_n *datash_n)
{
	int loop_sep;
	sep_list_n *ls_s;
	line_list_n *ls_l;

	loop_sep = 1;
	ls_s = *list_s;
	ls_l = *list_l;

	while (ls_s != NULL && loop_sep)
	{
		if (datash_n->status_n == 0)
		{
			if (ls_s->separator_n == '&' || ls_s->separator_n == ';')
				loop_sep = 0;
			if (ls_s->separator_n == '|')
				ls_l = ls_l->next, ls_s = ls_s->next;
		}
		else
		{
			if (ls_s->separator_n == '|' || ls_s->separator_n == ';')
				loop_sep = 0;
			if (ls_s->separator_n == '&')
				ls_l = ls_l->next, ls_s = ls_s->next;
		}
		if (ls_s != NULL && !loop_sep)
			ls_s = ls_s->next;
	}

	*list_s = ls_s;
	*list_l = ls_l;
}

/**
 * split_commands_n - splits command lines according to
 * the se ;, | and &, and executes them
 *
 * @datash_n: data structuref
 * @input_n: input string
 * Return: 0 to exit, 1 to cont
 */
int split_commands_n(data_shell_n *datash_n, char *input_n)
{

	sep_list_n *head_s, *list_s;
	line_list_n *head_l, *list_l;
	int loop;

	head_s = NULL;
	head_l = NULL;

	add_nodes_n(&head_s, &head_l, input_n);

	list_s = head_s;
	list_l = head_l;

	while (list_l != NULL)
	{
		datash_n->input_n = list_l->line_n;
		datash_n->args_n = split_line_n(datash_n->input_n);
		loop = exec_line_n(datash_n);
		free(datash_n->args_n);

		if (loop == 0)
			break;

		go_next_n(&list_s, &list_l, datash_n);

		if (list_l != NULL)
			list_l = list_l->next;
	}

	free_sep_list_n(&head_s);
	free_line_list_n(&head_l);

	if (loop == 0)
		return (0);
	return (1);
}

/**
 * split_line_n - okenizes the input string
 *
 * @input_n: input string.
 * Return: splitted str
 */
char **split_line_n(char *input_n)
{
	size_t bsize;
	size_t e;
	char **tokens;
	char *token;

	bsize = ERICK_;
	tokens = malloc(sizeof(char *) * (bsize));
	if (tokens == NULL)
	{
		write(STDERR_FILENO, ": allocation error\n", 18);
		exit(EXIT_FAILURE);
	}

	token = _strtok_n(input_n, MOLOI);
	tokens[0] = token;

	for (e = 1; token != NULL; e++)
	{
		if (e == bsize)
		{
			bsize += ERICK_;
			tokens = _reallocdp_n(tokens, e, sizeof(char *) * bsize);
			if (tokens == NULL)
			{
				write(STDERR_FILENO, ": allocation error\n", 18);
				exit(EXIT_FAILURE);
			}
		}
		token = _strtok_n(NULL, MOLOI);
		tokens[e] = token;
	}

	return (tokens);
}
