#include "main.h"

/**
 * cd_shell_n - will change current directory
 *
 * @datash_n:relevant
 * Return: 1 on success
 */

int cd_shell_n(data_shell_n *datash_n)
{
	char *dir;
	int ishome_, ishome2_, isddash_;

	dir = datash_n->args_n[1];

	if (dir != NULL)
	{
		ishome_ = _strcmp_n("$HOME", dir);
		ishome2_ = _strcmp_n("~", dir);
		isddash_ = _strcmp_n("--", dir);
	}

	if (dir == NULL || !ishome_ || !ishome2_ || !isddash_)
	{
		cd_to_home_n(datash_n);
		return (1);
	}

	if (_strcmp_n("-", dir) == 0)
	{
		cd_previous_n(datash_n);
		return (1);
	}

	if (_strcmp_n(".", dir) == 0 || _strcmp_n("..", dir) == 0)
	{
		cd_dot_n(datash_n);
		return (1);
	}

	cd_to_n(datash_n);

	return (1);
}
