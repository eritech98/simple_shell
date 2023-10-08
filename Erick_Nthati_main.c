#include "main.h"

/**
 * free_data_n - Does free data structure
 *
 * @datash_n: our data structure
 * Return: void
 */

void free_data_n(data_shell_n *datash_n)
{
	unsigned int e;

	for (e = 0; datash_n->environ_n[e]; e++)
	{
		free(datash_n->environ_n[e]);
	}

	free(datash_n->environ_n);
	free(datash_n->pid_n);
}

/**
 * set_data_n - Does Initialize data structure
 *
 * @datash_n: data structure
 * @av_n: argument vector
 * Return: void
 */

void set_data_n(data_shell_n *datash_n, char **av_n)
{
	unsigned int e;

	datash_n->av_n = av_n;
	datash_n->input_n = NULL;
	datash_n->args_n = NULL;
	datash_n->status_n = 0;
	datash_n->counter_n = 1;

	for (e = 0; environ[e]; e++)
		;

	datash_n->environ_n = malloc(sizeof(char *) * (e + 1));

	for (e = 0; environ[e]; e++)
	{
		datash_n->environ_n[e] = _strdup_n(environ[e]);
	}

	datash_n->environ_n[e] = NULL;
	datash_n->pid_n = _itoa_n(getpid());
}


/**
 * main - Entry point
 *
 * @ac: argument counts
 * @av_n: argument vector
 *
 * Return: 0 on succes.
 */

int main(int ac, char **av_n)
{
	data_shell_n datash_n;
	(void) ac;

	signal(SIGINT, get_sigint_n);
	set_data_n(&datash_n, av_n);
	shell_loop_n(&datash_n);
	free_data_n(&datash_n);
	if (datash_n.status_n < 0)
		return (255);
	return (datash_n.status_n);
}
