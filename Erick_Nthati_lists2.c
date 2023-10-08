#include "main.h"

/**
 * add_rvar_node_n - adds a var At the end
 * of a r_varariable list.
 * @head: This is rhe head of the linked list.
 * @lvar: length of the variable_our lenngth variable
 * @value_: value of the variablE.
 * @lval: length of the valuE.
 * Return: address of the head.
 */
r_variable *add_rvar_node_n(r_variable **head, int lvar,
				char *value_, int lval)
{
	r_variable *new, *tempo;

	new = malloc(sizeof(r_variable));
	if (new == NULL)
		return (NULL);

	new->len_var_e = lvar;
	new->value_ = value_;
	new->len_val_e = lval;

	new->next = NULL;
	tempo = *head;

	if (tempo == NULL)
	{
		*head = new;
	}
	else
	{
		while (tempo->next != NULL)
			tempo = tempo->next;
		tempo->next = new;
	}

	return (*head);
}

/**
 * free_rvar_list_n - frees a r_var lists.
 * @head: head of the linked list...
 * Return: void
 */

void free_rvar_list_n(r_variable **head)
{
	r_variable *tempo;
	r_variable *current_;

	if (head != NULL)
	{
		current_ = *head;
		while ((tempo = current_) != NULL)
		{
			current_ = current_->next;
			free(tempo);
		}
		*head = NULL;
	}
}
