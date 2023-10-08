#include "main.h"

/**
 * cmp_env_name_n - cpompares env variables names
 * with  name passed.
 * @nenv: name of the environment variable
 * @name_n: name passed
 *
 * Return: 0 if are not equal. Anot value if they are.
 */
int cmp_env_name_n(const char *nenv, const char *name_n)
{
	int e;

	for (e = 0; nenv[e] != '='; e++)
	{
		if (nenv[e] != name_n[e])
		{
			return (0);
		}
	}

	return (e + 1);
}

/**
 * _getenv_n - gets an environment variable
 * @name_n: name of the environment variable
 * @environ_n: environment variable
 *
 * Return: val of the environment variable if is found.
 * In other case, returns NULL..
 */
char *_getenv_n(const char *name_n, char **environ_n)
{
	char *ptr_env;
	int e, mov;

	/* Initialize ptr_env val */
	ptr_env = NULL;
	mov = 0;
	/* Compare all environment vas */
	/* environ is declared in the heade of f*/
	for (e = 0; environ_n[e]; e++)
	{
		/* If name and env are equal */
		mov = cmp_env_name_n(environ_n[e], name_n);
		if (mov)
		{
			ptr_env = environ_n[e];
			break;
		}
	}

	return (ptr_env + mov);
}

/**
 * _env_n - prints the evironment variable
 *
 * @datash_n: data relevant.
 * Return: 1 on success.
 */
int _env_n(data_shell_n *datash_n)
{
	int e, j;

	for (e = 0; datash_n->environ_n[e]; e++)
	{

		for (j = 0; datash_n->environ_n[e][j]; j++)
			;

		write(STDOUT_FILENO, datash_n->environ_n[e], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	datash_n->status_n = 0;

	return (1);
}
