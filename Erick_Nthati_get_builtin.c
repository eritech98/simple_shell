#include "main.h"

/**
 * get_builtin_n - bThis uiltin that pais the command in the arg
 * @cmd_n: command
 * Return: A function pointer of the builtin command
 */
int (*get_builtin_n(char *cmd_n))(data_shell_n *)
{
	builtin_n builtin[] = {
		{ "env", _env_n },
		{ "exit", exit_shell_n },
		{ "setenv", _setenv_n },
		{ "unsetenv", _unsetenv_n },
		{ "cd", cd_shell_n },
		{ "help", get_help_n },
		{ NULL, NULL }
	};
	int e;

	for (e = 0; builtin[e].name_n; e++)
	{
		if (_strcmp_n(builtin[e].name_n, cmd_n) == 0)
			break;
	}

	return (builtin[e].f);
}
