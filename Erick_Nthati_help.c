#include "main.h"

/**
 * _help_env_n - Help inf for the builtin env
 * Return: Nothing
 */
void _help_env_n(void)
{
	char *help_n = "env: env [option] [name_n=value] [command [args_n]]\n\t";

	write(STDOUT_FILENO, help_n, _strlen_n(help_n));
	help_n = "Print enviroment of the shell.\n";
	write(STDOUT_FILENO, help_n, _strlen_n(help_n));

}

/**
 * _help_setenv_n - Help info for the builtin seten
 * Return: nothing
 */
void _help_setenv_n(void)
{

	char *help_n = "setenv: setenv (const char *name_n, const char *value,";

	write(STDOUT_FILENO, help_n, _strlen_n(help_n));
	help_n = "int replacement)\n\t";
	write(STDOUT_FILENO, help_n, _strlen_n(help_n));
	help_n = "Add a new definition to environment\n";
	write(STDOUT_FILENO, help_n, _strlen_n(help_n));
}

/**
 * _help_unsetenv_n - Help info for the builtin unsetenv
 * Return: void
 */

void _help_unsetenv_n(void)
{
	char *help_n = "unsetenv: unsetenv (const char *name)\n\t";

	write(STDOUT_FILENO, help_n, _strlen_n(help_n));
	help_n = "Removes an entry completely from environment\n";
	write(STDOUT_FILENO, help_n, _strlen_n(help_n));
}


/**
 * _help_general_n - for help info for the help builtin
 * Return: Nothing
 */

void _help_general_n(void)
{
	char *help_n = "Erick_Nthati bash, version 1.0(1)-release\n";

	write(STDOUT_FILENO, help_n, _strlen_n(help_n));
	help_n = "These commands are defined internally.Type 'help_n'";
	write(STDOUT_FILENO, help_n, _strlen_n(help_n));
	help_n = "Type 'help name' to find more about the function 'name_n'.\n\n ";
	write(STDOUT_FILENO, help_n, _strlen_n(help_n));
	help_n = " alias: alias [name_n=['string']]\n cd: cd [-L|[-P [-e]] [-@]] ";
	write(STDOUT_FILENO, help_n, _strlen_n(help_n));
	help_n = "[dir]\nexit: exit [n]\n  env: env [option] [name_n=value] [command";
	write(STDOUT_FILENO, help_n, _strlen_n(help_n));
	help_n = "[args_n]]\n  setenv: setenv [variable] [value]\n  unsetenv: ";
	write(STDOUT_FILENO, help_n, _strlen_n(help_n));
	help_n = "unsetenv [variable]\n";
	write(STDOUT_FILENO, help_n, _strlen_n(help_n));
}
/**
 * _help_exit_n - Help infor fot the builint exit
 * Return: void
 */

void _help_exit_n(void)
{
	char *help_n = "exit: exit [n]\n Exit shell.\n";

	write(STDOUT_FILENO, help_n, _strlen_n(help_n));
	help_n = "Exits the shell with a status of N. If N is ommited,exit";
	write(STDOUT_FILENO, help_n, _strlen_n(help_n));
	help_n = "status is that of the last command executed\n";
	write(STDOUT_FILENO, help_n, _strlen_n(help_n));
}
