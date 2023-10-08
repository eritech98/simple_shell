#include "main.h"

/**
 * get_help_n - This function that gets help msg ccording builtin
 * @datash_n: data structure (args and input_n)
 * Return: Return 0
*/

int get_help_n(data_shell_n *datash_n)
{

	if (datash_n->args_n[1] == 0)
		_help_general_n();
	else if (_strcmp_n(datash_n->args_n[1], "setenv") == 0)
		_help_setenv_n();
	else if (_strcmp_n(datash_n->args_n[1], "env") == 0)
		_help_env_n();
	else if (_strcmp_n(datash_n->args_n[1], "unsetenv") == 0)
		_help_unsetenv_n();
	else if (_strcmp_n(datash_n->args_n[1], "help") == 0)
		_help_n();
	else if (_strcmp_n(datash_n->args_n[1], "exit") == 0)
		_help_exit_n();
	else if (_strcmp_n(datash_n->args_n[1], "cd") == 0)
		_help_cd_n();
	else if (_strcmp_n(datash_n->args_n[1], "alias") == 0)
		_help_alias_n();
	else
		write(STDERR_FILENO, datash_n->args_n[0],
		      _strlen_n(datash_n->args_n[0]));

	datash_n->status_n = 0;
	return (1);
}
