#include "main.h"

/**
 * cd_dot_n - changes to the parent dir
 *
 * @datash_n: data relevant (environ)
 *
 * Return: no return
 */
void cd_dot_n(data_shell_n *datash_n)
{
	char pwd[PATH_MAX];
	char *dir, *cp_pwd, *cp_strtok_pwd;

	getcwd(pwd, sizeof(pwd));
	cp_pwd = _strdup_n(pwd);
	set_erick("OLDPWD", cp_pwd, datash_n);
	dir = datash_n->args_n[1];
	if (_strcmp_n(".", dir) == 0)
	{
		set_erick("PWD", cp_pwd, datash_n);
		free(cp_pwd);
		return;
	}
	if (_strcmp_n("/", cp_pwd) == 0)
	{
		free(cp_pwd);
		return;
	}
	cp_strtok_pwd = cp_pwd;
	rev_string_n(cp_strtok_pwd);
	cp_strtok_pwd = _strtok_n(cp_strtok_pwd, "/");
	if (cp_strtok_pwd != NULL)
	{
		cp_strtok_pwd = _strtok_n(NULL, "\0");

		if (cp_strtok_pwd != NULL)
			rev_string_n(cp_strtok_pwd);
	}
	if (cp_strtok_pwd != NULL)
	{
		chdir(cp_strtok_pwd);
		set_erick("PWD", cp_strtok_pwd, datash_n);
	}
	else
	{
		chdir("/");
		set_erick("PWD", "/", datash_n);
	}
	datash_n->status_n = 0;
	free(cp_pwd);
}

/**
 * cd_to_n - Will change to a directory given
 * by user
 *
 * @datash_n: data relevant (directories)
 * Return: void
 */
void cd_to_n(data_shell_n *datash_n)
{
	char pwd[PATH_MAX];
	char *dir, *cp_pwd, *cp_dir;

	getcwd(pwd, sizeof(pwd));

	dir = datash_n->args_n[1];
	if (chdir(dir) == -1)
	{
		get_error_n(datash_n, 2);
		return;
	}

	cp_pwd = _strdup_n(pwd);
	set_erick("OLDPWD", cp_pwd, datash_n);

	cp_dir = _strdup_n(dir);
	set_erick("PWD", cp_dir, datash_n);

	free(cp_pwd);
	free(cp_dir);

	datash_n->status_n = 0;

	chdir(dir);
}

/**
 * cd_previous_n - anges to the previous directory
 *
 * @datash_n: delevant (environ)
 * Return: void
 */

void cd_previous_n(data_shell_n *datash_n)
{
	char pwd[PATH_MAX];

	char *p_pwd, *p_oldpwd, *cp_pwd, *cp_oldpwd;

	getcwd(pwd, sizeof(pwd));
	cp_pwd = _strdup_n(pwd);

	p_oldpwd = _getenv_n("OLDPWD", datash_n->environ_n);

	if (p_oldpwd == NULL)
		cp_oldpwd = cp_pwd;
	else
		cp_oldpwd = _strdup_n(p_oldpwd);

	set_erick("OLDPWD", cp_pwd, datash_n);

	if (chdir(cp_oldpwd) == -1)
		set_erick("PWD", cp_pwd, datash_n);
	else
		set_erick("PWD", cp_oldpwd, datash_n);

	p_pwd = _getenv_n("PWD", datash_n->environ_n);

	write(STDOUT_FILENO, p_pwd, _strlen_n(p_pwd));
	write(STDOUT_FILENO, "\n", 1);

	free(cp_pwd);

	if (p_oldpwd)

		free(cp_oldpwd);

	datash_n->status_n = 0;

	chdir(p_pwd);
}


/**
 * cd_to_home_n - Will change to home directory
 *
 * @datash_n: data relevant
 * Return:void
 */

void cd_to_home_n(data_shell_n *datash_n)
{
	char *p_pwd, *home;

	char pwd[PATH_MAX];

	getcwd(pwd, sizeof(pwd));
	p_pwd = _strdup_n(pwd);

	home = _getenv_n("HOME", datash_n->environ_n);

	if (home == NULL)
	{
		set_erick("OLDPWD", p_pwd, datash_n);
		free(p_pwd);
		return;
	}


	if (chdir(home) == -1)
	{
		get_error_n(datash_n, 2);
		free(p_pwd);
		return;
	}

	set_erick("OLDPWD", p_pwd, datash_n);
	set_erick("PWD", home, datash_n);
	free(p_pwd);
	datash_n->status_n = 0;
}
