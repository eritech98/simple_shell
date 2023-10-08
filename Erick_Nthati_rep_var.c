#include "main.h"

/**
 * check_env_n - checks if the typed variable is env variable
 *
 * @h: head of linked list_
 * @in: input string_
 * @data_n: data structure
 * Return: void
 */
void check_env_n(r_variable **h, char *in, data_shell_n *data_n)
{
	int row, chr, j, lval;
	char **envr_;

	envr_ = data_n->environ_n;
	for (row = 0; envr_[row]; row++)
	{
		for (j = 1, chr = 0; envr_[row][chr]; chr++)
		{
			if (envr_[row][chr] == '=')
			{
				lval = _strlen_n(envr_[row] + chr + 1);
				add_rvar_node_n(h, j, envr_[row] + chr + 1, lval);
				return;
			}

			if (in[j] == envr_[row][chr])
				j++;
			else
				break;
		}
	}


	for (j = 0; in[j]; j++)
	{
		if (in[j] == ' ' || in[j] == '\t' || in[j] == ';' || in[j] == '\n')
			break;
	}

	add_rvar_node_n(h, j, NULL, 0);
}

/**
 * check_vars_n - checks if the typed variable is $$ or $?
 *
 * @h: head of the linkd list
 * @in: input string_
 * @st: last status of the Shell_
 * @data_n: data structure-
 * Return: no return
 */

int check_vars_n(r_variable **h, char *in, char *st, data_shell_n *data_n)
{
	int e, lst, lpd;

	lst = _strlen_n(st);
	lpd = _strlen_n(data_n->pid_n);

	for (e = 0; in[e]; e++)
	{
		if (in[e] == '$')
		{
			if (in[e + 1] == '?')
				add_rvar_node_n(h, 2, st, lst), e++;
			else if (in[e + 1] == '$')
				add_rvar_node_n(h, 2, data_n->pid_n, lpd), e++;
			else if (in[e + 1] == '\n')
				add_rvar_node_n(h, 0, NULL, 0);
			else if (in[e + 1] == '\0')
				add_rvar_node_n(h, 0, NULL, 0);
			else if (in[e + 1] == ' ')
				add_rvar_node_n(h, 0, NULL, 0);
			else if (in[e + 1] == '\t')
				add_rvar_node_n(h, 0, NULL, 0);
			else if (in[e + 1] == ';')
				add_rvar_node_n(h, 0, NULL, 0);
			else
				check_env_n(h, in + e, data_n);
		}
	}

	return (e);
}

/**
 * replaced_input_n - replaces string into variables
 *
 * @head: head of the linked list_
 * @input_n: input string
 * @new_input: new input string (replaced)
 * @nlen: new len
 * Return: replaced string
 */
char *replaced_input_n(r_variable **head, char *input_n,
				char *new_input, int nlen)
{
	r_variable *indx;
	int e, j, k;

	indx = *head;
	for (j = e = 0; e < nlen; e++)
	{
		if (input_n[j] == '$')
		{
			if (!(indx->len_var_e) && !(indx->len_val_e))
			{
				new_input[e] = input_n[j];
				j++;
			}
			else if (indx->len_var_e && !(indx->len_val_e))
			{
				for (k = 0; k < indx->len_var_e; k++)
					j++;
				e--;
			}
			else
			{
				for (k = 0; k < indx->len_val_e; k++)
				{
					new_input[e] = indx->value_[k];
					e++;
				}
				j += (indx->len_var_e);
				e--;
			}
			indx = indx->next;
		}
		else
		{
			new_input[e] = input_n[j];
			j++;
		}
	}

	return (new_input);
}

/**
 * rep_var_n - calls functions to replace string into vars
 *
 * @input_n: input string_
 * @datash_n: data structure_
 * Return: replaced string
 */

char *rep_var_n(char *input_n, data_shell_n *datash_n)
{
	r_variable *head, *indx;
	char *status_n, *new_input;
	int olen, nlen;

	status_n = _itoa_n(datash_n->status_n);
	head = NULL;

	olen = check_vars_n(&head, input_n, status_n, datash_n);

	if (head == NULL)
	{
		free(status_n);
		return (input_n);
	}

	indx = head;
	nlen = 0;

	while (indx != NULL)
	{
		nlen += (indx->len_val_e - indx->len_var_e);
		indx = indx->next;
	}

	nlen += olen;

	new_input = malloc(sizeof(char) * (nlen + 1));
	new_input[nlen] = '\0';

	new_input = replaced_input_n(&head, input_n, new_input, nlen);

	free(input_n);
	free(status_n);
	free_rvar_list_n(&head);

	return (new_input);
}
