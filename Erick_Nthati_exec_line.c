#include "main.h"

/**
 * exec_line_n - will find builtins and commands
 * @datash_n: data relevant (args_n)
 * Return: 1 on success.
 */

int exec_line_n(data_shell_n *datash_n)
{
	int (*builtin)(data_shell_n *datash_n);

	if (datash_n->args_n[0] == NULL)
		return (1);

	builtin = get_builtin_n(datash_n->args_n[0]);

	if (builtin != NULL)
		return (builtin(datash_n));

	return (cmd_exec_n(datash_n));
}
