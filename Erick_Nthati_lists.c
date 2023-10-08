#include "main.h"

/**
 * add_sep_node_end_n - adds a separator_n found at THE end
 * of a sep_list_n
 * @head: head of the linked list.
 * @sep: separator_n found (; | &).
 * Return: address of the head.
 */
sep_list_n *add_sep_node_end_n(sep_list_n **head, char sep)
{
	sep_list_n *new, *tempo;

	new = malloc(sizeof(sep_list_n));
	if (new == NULL)
		return (NULL);

	new->separator_n = sep;
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
 * free_sep_list_n - frees a sep_list
 * @head: head of the linked list.
 * Return: no return.
 */
void free_sep_list_n(sep_list_n **head)
{
	sep_list_n *tempo;
	sep_list_n *current;

	if (head != NULL)
	{
		current = *head;
		while ((tempo = current) != NULL)
		{
			current = current->next;
			free(tempo);
		}
		*head = NULL;
	}
}

/**
 * add_line_node_end_n - adds a command line at the end
 * of a line_list_n.
 * @head: head of the linked listo
 * @line_n: command line.
 * Return: address of the head.
 */
line_list_n *add_line_node_end_n(line_list_n **head, char *line_n)
{
	line_list_n *new, *tempo;

	new = malloc(sizeof(line_list_n));
	if (new == NULL)
		return (NULL);

	new->line_n = line_n;
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
 * free_line_list_n - frees a line_list
 * @head: head of the linked list.
 * Return: no return.
 */
void free_line_list_n(line_list_n **head)
{
	line_list_n *tempo;
	line_list_n *current;

	if (head != NULL)
	{
		current = *head;
		while ((tempo = current) != NULL)
		{
			current = current->next;
			free(tempo);
		}
		*head = NULL;
	}
}
