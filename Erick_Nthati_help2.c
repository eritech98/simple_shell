#include "main.h"

/**
 * _help_n - Help information
 * Return: void
 */

void _help_n(void)
{
	char *help_n = "help: help [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, help_n, _strlen_n(help_n));
	help_n = "\tDisplay all information about builtin commands.\n ";
	write(STDOUT_FILENO, help_n, _strlen_n(help_n));
	help_n = "Displays brief summaries of builtin commands.\n";
	write(STDOUT_FILENO, help_n, _strlen_n(help_n));
}
/**
 *_help_alias_n - this Help info for the builtin alias.
 * Return: nothing
 */

void _help_alias_n(void)
{
	char *help_n = "alias: alias [-p] [name[=value]...]\n";

	write(STDOUT_FILENO, help_n, _strlen_n(help_n));
	help_n = "\tDefine or display aliases.\n ";
	write(STDOUT_FILENO, help_n, _strlen_n(help_n));
}
/**
 * _help_cd_n - Help info for the builtin alias.
 * Return: no return
 */

void _help_cd_n(void)
{
	char *help_n = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, help_n, _strlen_n(help_n));
	help_n = "\tChange the shell working directory.\n ";
	write(STDOUT_FILENO, help_n, _strlen_n(help_n));
}
