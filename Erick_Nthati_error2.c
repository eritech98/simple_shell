#include "main.h"

/**
 * error_env_n -An error message for env in get_env.
 * @datash_n: data that's relevant (counter, arguments)
 * Return: our error message,,,
 */
char *error_env_n(data_shell_n *datash_n)
{
	int length_;
	char *error;
	char *ver_str;
	char *msg;

	ver_str = _itoa_n(datash_n->counter_n);
	msg = ": Unable to add/remove from Environment\n";
	length_ = _strlen_n(datash_n->av_n[0]) + _strlen_n(ver_str);
	length_ += _strlen_n(datash_n->args_n[0]) + _strlen_n(msg) + 4;
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
	_strcat_n(error, msg);
	_strcat_n(error, "\0");
	free(ver_str);

	return (error);
}
/**
 * error_path_126_n - error message for path and not denied perm
 * @datash_n:The data relevant (counter, arguments).
 * Return: The error string.
 */

char *error_path_126_n(data_shell_n *datash_n)
{
	int length_;
	char *ver_str;
	char *error;

	ver_str = _itoa_n(datash_n->counter_n);
	length_ = _strlen_n(datash_n->av_n[0]) + _strlen_n(ver_str);
	length_ += _strlen_n(datash_n->args_n[0]) + 24;
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
	_strcat_n(error, ": Permission was denied\n");
	_strcat_n(error, "\0");
	free(ver_str);
	return (error);
}
