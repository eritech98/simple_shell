#include "main.h"



/**
 * strcat_cd_n - This concatenates the message for cd error
 *
 * @datash_n: data relevant (directory)
 * @msg: message to be printed
 * @error:will output message
 * @ver_str: The counter lines
 * Return: error message
 */
char *strcat_cd_n(data_shell_n *datash_n,
	char *msg, char *error, char *ver_str)
{
	char *illegal_flag_n;

	_strcpy_n(error, datash_n->av_n[0]);
	_strcat_n(error, ": ");
	_strcat_n(error, ver_str);
	_strcat_n(error, ": ");
	_strcat_n(error, datash_n->args_n[0]);
	_strcat_n(error, msg);
	if (datash_n->args_n[1][0] == '-')
	{
		illegal_flag_n = malloc(3);
		illegal_flag_n[0] = '-';
		illegal_flag_n[1] = datash_n->args_n[1][1];
		illegal_flag_n[2] = '\0';
		_strcat_n(error, illegal_flag_n);
		free(illegal_flag_n);
	}
	else
	{
		_strcat_n(error, datash_n->args_n[1]);
	}

	_strcat_n(error, "\n");
	_strcat_n(error, "\0");
	return (error);
}

/**
 * error_get_cd_n - our error message for cd command in get_cd
 * @datash_n: data relevanyy
 * Return: Error message
 */

char *error_get_cd_n(data_shell_n *datash_n)
{
	int length_, len_id_;
	char *error, *ver_str, *msg;

	ver_str = _itoa_n(datash_n->counter_n);
	if (datash_n->args_n[1][0] == '-')
	{
		msg = ": An Illegal option ";
		len_id_ = 2;
	}
	else
	{
		msg = ": cannot cd to ";
		len_id_ = _strlen_n(datash_n->args_n[1]);
	}

	length_ = _strlen_n(datash_n->av_n[0]) + _strlen_n(datash_n->args_n[0]);
	length_ += _strlen_n(ver_str) + _strlen_n(msg) + len_id_ + 5;
	error = malloc(sizeof(char) * (length_ + 1));

	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}

	error = strcat_cd_n(datash_n, msg, error, ver_str);

	free(ver_str);

	return (error);
}


/**
 * error_not_found_n - A generic error message for cmd not found
 * @datash_n: The data relevant (counter, arguments)
 * Return: Error message
 */

char *error_not_found_n(data_shell_n *datash_n)
{
	int length_;
	char *error;
	char *ver_str;

	ver_str = _itoa_n(datash_n->counter_n);
	length_ = _strlen_n(datash_n->av_n[0]) + _strlen_n(ver_str);
	length_ += _strlen_n(datash_n->args_n[0]) + 16;
	error = malloc(sizeof(char) * (length_ + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}
	_strcpy_n(error, datash_n->av_n[0]);
	_strcat_n(error, ": ");
	_strcat_n(error, ver_str);
	_strcat_n(error, ": ");
	_strcat_n(error, datash_n->args_n[0]);
	_strcat_n(error, ": Not found\n");
	_strcat_n(error, "\0");
	free(ver_str);
	return (error);
}


/**
 * error_exit_shell_n - A gen error message for exit in get_exit
 * @datash_n: data (counter, arguments)
 * Return: Error message
 */

char *error_exit_shell_n(data_shell_n *datash_n)
{
	int length_;
	char *error;
	char *ver_str;

	ver_str = _itoa_n(datash_n->counter_n);
	length_ = _strlen_n(datash_n->av_n[0]) + _strlen_n(ver_str);
	length_ += _strlen_n(datash_n->args_n[0]) +
		_strlen_n(datash_n->args_n[1]) +
		23;
	error = malloc(sizeof(char) * (length_ + 1));
	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}
	_strcpy_n(error, datash_n->av_n[0]);
	_strcat_n(error, ": ");
	_strcat_n(error, ver_str);
	_strcat_n(error, ": ");
	_strcat_n(error, datash_n->args_n[0]);
	_strcat_n(error, ": An Illegal number: ");
	_strcat_n(error, datash_n->args_n[1]);
	_strcat_n(error, "\n\0");
	free(ver_str);

	return (error);
}
