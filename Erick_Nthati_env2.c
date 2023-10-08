#include "main.h"

/**
 * copy_info_n - That copies info to create
 * a new env or Alias
 * @name_n: name (env or alias)
 * @value: value (env or alias)
 *
 * Return: new env or alias.
 */

char *copy_info_n(char *name_n, char *value)
{
	char *new;
	int len_name, len_value, len;

	len_name = _strlen_n(name_n);
	len_value = _strlen_n(value);
	len = len_name + len_value + 2;
	new = malloc(sizeof(char) * (len));
	_strcpy_n(new, name_n);
	_strcat_n(new, "=");
	_strcat_n(new, value);
	_strcat_n(new, "\0");

	return (new);
}

/**
 * set_erick - will sets an environment variable
 *
 * @name_n: name of the environment variable
 * @value:The value of the environment variable
 * @datash_n: data structure (environ)
 * Return: void
 */

void set_erick(char *name_n, char *value, data_shell_n *datash_n)
{
	int e;
	char *var_env, *name_env;

	for (e = 0; datash_n->environ_n[e]; e++)
	{
		var_env = _strdup_n(datash_n->environ_n[e]);
		name_env = _strtok_n(var_env, "=");
		if (_strcmp_n(name_env, name_n) == 0)
		{
			free(datash_n->environ_n[e]);
			datash_n->environ_n[e] = copy_info_n(name_env, value);
			free(var_env);
			return;
		}
		free(var_env);
	}

	datash_n->environ_n = _reallocdp_n(datash_n->environ_n,
				e, sizeof(char *) * (e + 2));
	datash_n->environ_n[e] = copy_info_n(name_n, value);
	datash_n->environ_n[e + 1] = NULL;
}

/**
 * _setenv_n - This compares env var names
 * with name passed
 * @datash_n: data relevant
 *
 * Return:A 1 on success.
 */

int _setenv_n(data_shell_n *datash_n)
{

	if (datash_n->args_n[1] == NULL || datash_n->args_n[2] == NULL)
	{
		get_error_n(datash_n, -1);
		return (1);
	}

	set_erick(datash_n->args_n[1], datash_n->args_n[2], datash_n);

	return (1);
}

/**
 * _unsetenv_n - This deletes a environment variable
 *
 * @datash_n: data relevant (env name)
 *
 * Return: a 1 on success.
 */

int _unsetenv_n(data_shell_n *datash_n)
{
	char *var_env, *name_env;
	int e, j, k;
	char **realloc_environ;

	if (datash_n->args_n[1] == NULL)
	{
		get_error_n(datash_n, -1);
		return (1);
	}
	k = -1;
	for (e = 0; datash_n->environ_n[e]; e++)
	{
		var_env = _strdup_n(datash_n->environ_n[e]);
		name_env = _strtok_n(var_env, "=");
		if (_strcmp_n(name_env, datash_n->args_n[1]) == 0)
		{
			k = e;
		}
		free(var_env);
	}
	if (k == -1)
	{
		get_error_n(datash_n, -1);
		return (1);
	}
	realloc_environ = malloc(sizeof(char *) * (e));
	for (e = j = 0; datash_n->environ_n[e]; e++)
	{
		if (e != k)
		{
			realloc_environ[j] = datash_n->environ_n[e];
			j++;
		}
	}
	realloc_environ[j] = NULL;
	free(datash_n->environ_n[k]);
	free(datash_n->environ_n);
	datash_n->environ_n = realloc_environ;
	return (1);
}
