#include "main.h"

/**
 * get_error_n - calls error according the builtin, syntax or permission
 * @datash_n: data structure that contains args
 * @eval: error
 * Return: error
 */

int get_error_n(data_shell_n *datash_n, int eval)
{
	char *error;

	switch (eval)
	{
	case -1:
		error = error_env_n(datash_n);
		break;
	case 126:
		error = error_path_126_n(datash_n);
		break;
	case 127:
		error = error_not_found_n(datash_n);
		break;
	case 2:
		if (_strcmp_n("exit", datash_n->args_n[0]) == 0)
			error = error_exit_shell_n(datash_n);
		else if (_strcmp_n("cd", datash_n->args_n[0]) == 0)
			error = error_get_cd_n(datash_n);
		break;
	}

	if (error)
	{
		write(STDERR_FILENO, error, _strlen_n(error));
		free(error);
	}

	datash_n->status_n = eval;
	return (eval);
}
