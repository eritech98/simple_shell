#include "main.h"

/**
 * is_cdir_n - ":" if is in the current directory.
 * @path: type char pointer char.
 * @e: type int pointer of index.
 * Return: 1 if the path is searchable in the cd, 0 otherwise.
 */
int is_cdir_n(char *path, int *e)
{
	if (path[*e] == ':')
		return (1);

	while (path[*e] != ':' && path[*e])
	{
		*e += 1;
	}

	if (path[*e])
		*e += 1;

	return (0);
}

/**
 * _which_n - locates a command
 *
 * @cmd_n: command names
 * @environ_n: environment var
 * Return: location of the command.
 */
char *_which_n(char *cmd_n, char **environ_n)
{
	char *path, *ptr_path, *token_path, *dir;
	int len_dir, len_cmd, e;
	struct stat st;

	path = _getenv_n("PATH", environ_n);
	if (path)
	{
		ptr_path = _strdup_n(path);
		len_cmd = _strlen_n(cmd_n);
		token_path = _strtok_n(ptr_path, ":");
		e = 0;
		while (token_path != NULL)
		{
			if (is_cdir_n(path, &e))
				if (stat(cmd_n, &st) == 0)
					return (cmd_n);
			len_dir = _strlen_n(token_path);
			dir = malloc(len_dir + len_cmd + 2);
			_strcpy_n(dir, token_path);
			_strcat_n(dir, "/");
			_strcat_n(dir, cmd_n);
			_strcat_n(dir, "\0");
			if (stat(dir, &st) == 0)
			{
				free(ptr_path);
				return (dir);
			}
			free(dir);
			token_path = _strtok_n(NULL, ":");
		}
		free(ptr_path);
		if (stat(cmd_n, &st) == 0)
			return (cmd_n);
		return (NULL);
	}
	if (cmd_n[0] == '/')
		if (stat(cmd_n, &st) == 0)
			return (cmd_n);
return (NULL);
}
/**
 * is_executable_n - determines if is an executable_
 *
 * @datash_n: data structure_
 * Return: 0 if is not an executable,
 */

int is_executable_n(data_shell_n *datash_n)
{
	struct stat st;
	int e;
	char *input_n;

	input_n = datash_n->args_n[0];
	for (e = 0; input_n[e]; e++)
	{
		if (input_n[e] == '.')
		{
			if (input_n[e + 1] == '.')
				return (0);
			if (input_n[e + 1] == '/')
				continue;
			else
				break;
		}
		else if (input_n[e] == '/' && e != 0)
		{
			if (input_n[e + 1] == '.')
				continue;
			e++;
			break;
		}
		else
			break;
	}
	if (e == 0)
		return (0);

	if (stat(input_n + e, &st) == 0)
	{
		return (e);
	}
	get_error_n(datash_n, 127);
	return (-1);
}

/**
 * check_error_cmd_n - This verifies if user has permissions to access
 *
 * @dir: destination dir
 * @datash_n: data structure
 * Return: 1 if there is an error, 0 if not
 */

int check_error_cmd_n(char *dir, data_shell_n *datash_n)
{
	if (dir == NULL)
	{
		get_error_n(datash_n, 127);
		return (1);
	}

	if (_strcmp_n(datash_n->args_n[0], dir) != 0)
	{
		if (access(dir, X_OK) == -1)
		{
			get_error_n(datash_n, 126);
			free(dir);
			return (1);
		}
		free(dir);
	}
	else
	{
		if (access(datash_n->args_n[0], X_OK) == -1)
		{
			get_error_n(datash_n, 126);
			return (1);
		}
	}

	return (0);
}

/**
 * cmd_exec_n - executes command lin
 *
 * @datash_n: data relevant (input)
 * Return: 1 on success.
 */

int cmd_exec_n(data_shell_n *datash_n)
{
	pid_t wpd;
	 pid_t pd;
	int exec;
	int state;
	char *dir;
	(void) wpd;

	exec = is_executable_n(datash_n);
	if (exec == -1)
		return (1);
	if (exec == 0)
	{
		dir = _which_n(datash_n->args_n[0], datash_n->environ_n);
		if (check_error_cmd_n(dir, datash_n) == 1)
			return (1);
	}

	pd = fork();
	if (pd == 0)
	{
		if (exec == 0)
			dir = _which_n(datash_n->args_n[0], datash_n->environ_n);
		else
			dir = datash_n->args_n[0];
		execve(dir + exec, datash_n->args_n, datash_n->environ_n);
	}
	else if (pd < 0)
	{
		perror(datash_n->av_n[0]);
		return (1);
	}
	else
	{
		do {
			wpd = waitpid(pd, &state, WUNTRACED);
		} while (!WIFEXITED(state) && !WIFSIGNALED(state));
	}

	datash_n->status_n = state / 256;
	return (1);
}
