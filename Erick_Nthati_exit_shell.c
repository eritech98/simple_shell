#include "main.h"

/**
 * exit_shell_n - This exits the shell
 *
 * @datash_n: data relevant (status and args)
 * Return: 0 means success.
 */

int exit_shell_n(data_shell_n *datash_n)
{
	unsigned int ustatus_;
	int is_digit_;
	int str_len_;
	int big_number_;

	if (datash_n->args_n[1] != NULL)
	{
		ustatus_ = _atoi_n(datash_n->args_n[1]);
		is_digit_ = _isdigit_n(datash_n->args_n[1]);
		str_len_ = _strlen_n(datash_n->args_n[1]);
		big_number_ = ustatus_ > (unsigned int)INT_MAX;
		if (!is_digit_ || str_len_ > 10 || big_number_)
		{
			get_error_n(datash_n, 2);
			datash_n->status_n = 2;
			return (1);
		}
		datash_n->status_n = (ustatus_ % 256);
	}
	return (0);
}
