#ifndef  ERICK_NTHATI
#define  ERICK_NTHATI

#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>


#define NTHATI 1024
#define ERICK_ 128
#define MOLOI " \t\r\n\a"

/* This Points to an array of pointers to strings called "environment" */

extern char **environ;


/**
 * struct data_n - struct which contains all relevant data on runtime
 * @av_n: argument Vector
 * @input_n:This command line written by user
 * @args_n:The tokens of the command line
 * @status_n:The last status of the shell
 * @counter_n: The lines counter
 * @environ_n:The environment variable
 * @pid_n:The process ID of the shell
 */
typedef struct data_n
{
	char **av_n;
	char *input_n;
	char **args_n;
	int status_n;
	int counter_n;
	char **environ_n;
	char *pid_n;
} data_shell_n;



/**
 * struct sep_list_Erick - single linked list
 * @separator_n:include  ; | &
 * @next: our next node
 */


typedef struct sep_list_Erick
{
	char separator_n;
	struct sep_list_Erick *next;
} sep_list_n;



/**
 * struct line_list_Erick - Our single linked list
 * @line_n: command line
 * @next: next node
 */

typedef struct line_list_Erick
{
	char *line_n;
	struct line_list_Erick *next;
} line_list_n;


/**
 * struct r_var_list_e - single linked list
 * @len_var_e: length of the variables
 * @value_: value of the variables
 * @len_val_e: length of the values
 * @next: next node...
 * Description:This single linked list will store variables
 */
typedef struct r_var_list_e
{
	int len_var_e;
	char *value_;
	int len_val_e;
	struct r_var_list_e *next;
} r_variable;

/**
 * struct builtin_Erick - Builtin struct for command args.
 * @name: The name of the command builtin i.e cd, exit, env
 * @f: data type pointer function.
 */
typedef struct builtin_Erick
{
	char *name_n;
	int (*f)(data_shell_n *datash_n);
} builtin_n;


/* aux_lists.c */
sep_list_n *add_sep_node_end_n(sep_list_n **head, char sep);
void free_sep_list_n(sep_list_n **head);
line_list_n *add_line_node_end_n(line_list_n **head, char *line_n);
void free_line_list_n(line_list_n **head);



/* aux_lists2.c */
r_variable *add_rvar_node_n(r_variable **head, int lvar, char *var, int lval);
void free_rvar_list_n(r_variable **head);

/* aux_str functions */
char *_strcat_n(char *destiny, const char *origin);
char *_strcpy_n(char *destiny, char *origin);
int _strcmp_n(char *str1, char *str2);
char *_strchr_n(char *string_n, char c);
int _strspn_n(char *string_n, char *accept);

/* aux_mem.c */
void _memcpy_n(void *new_ptr, const void *pointer, unsigned int size_n);
void *_realloc_n(void *pointer, unsigned int old_size_n, unsigned int new_size_n);
char **_reallocdp_n(char **pointer, unsigned int old_size_n, unsigned int new_size_n);

/* aux_str2.c */
char *_strdup_n(const char *string_n);
int _strlen_n(const char *string_n);
int cmp_chars_n(char str[], const char *delimeter);
char *_strtok_n(char str[], const char *delimeter);
int _isdigit_n(const char *string_n);

/* aux_str3.c */
void rev_string_n(char *string_n);


/* check_syntax_error.c */
int repeated_char_n(char *input_n, int e);
int error_sep_op_n(char *input_n, int e, char last);
int first_char_n(char *input_n, int *e);
void print_syntax_error_n(data_shell_n *datash_n, char *input_n, int e, int bool);
int check_syntax_error_n(data_shell_n *datash_n, char *input_n);


/* shell_loop.c */
char *without_comment_n(char *in);
void shell_loop_n(data_shell_n *datash_n);


/* read_line.c */
char *read_line_n(int *e_eof);



/* split.c */
char *swap_char_n(char *input_n, int bool);
void add_nodes_n(sep_list_n **head_Erick, line_list_n **head_l, char *input_n);
void go_next_n(sep_list_n **list_Erick, line_list_n **list_l, data_shell_n *datash_n);
int split_commands_n(data_shell_n *datash_n, char *input_n);
char **split_line_n(char *input_n);


/* rep_var.c */
void check_env_n(r_variable **h, char *in, data_shell_n *data_n);
int check_vars_n(r_variable **h, char *in, char *st, data_shell_n *data_n);
char *replaced_input_n(r_variable **head, char *input_n, char *new_input, int nlen);
char *rep_var_n(char *input_n, data_shell_n *datash_n);


/* get_line.c */
void bring_line_n(char **line_ptr, size_t *n, char *buffer, size_t j);
ssize_t get_line_n(char **line_ptr, size_t *n, FILE *stream);

/* exec_line */
int exec_line_n(data_shell_n *datash_n);



/* cmd_exec.c */
int is_cdir_n(char *path_n, int *e);
char *which_n(char *cmd_n, char **environ_n);
int is_executable_n(data_shell_n *datash_n);
int check_error_cmd_n(char *dir, data_shell_n *datash_n);
int cmd_exec_n(data_shell_n *datash_n);


/* env1.c */
char *_getenv_n(const char *name_n, char **environ_n);
int _env_n(data_shell_n *datash_n);



/* env2.c */
char *copy_info_n(char *name_n, char *value);
void set_erick(char *name_n, char *value, data_shell_n *datash_n);
int _setenv_n(data_shell_n *datash_n);
int _unsetenv_n(data_shell_n *datash_n);



/* cd.c */
void cd_dot_n(data_shell_n *datash_n);
void cd_to_n(data_shell_n *datash_n);
void cd_previous_n(data_shell_n *datash_n);
void cd_to_home_n(data_shell_n *datash_n);


/* cd_shell.c */
int cd_shell_n(data_shell_n *datash_n);


/* get_builtin */
int (*get_builtin_n(char *cmd_n))(data_shell_n *datash_n);


/* _exit.c */
int exit_shell_n(data_shell_n *datash_n);



/* aux_stdlib.c */
int get_len_n(int n);
char *_itoa_n(int n);
int _atoi_n(char *string_n);



/* aux_error1.c */
char *strcat_cd_n(data_shell_n *, char *, char *, char *);
char *error_get_cd_n(data_shell_n *datash_n);
char *error_not_found_n(data_shell_n *datash_n);
char *error_exit_shell_n(data_shell_n *datash_n);


/* aux_error2.c */
char *error_get_alias_n(char **args_n);
char *error_env_n(data_shell_n *datash_n);
char *error_syntax_n(char **args_n);
char *error_permission_n(char **args_n);
char *error_path_126_n(data_shell_n *datash_n);


/* get_error.c */
int get_error_n(data_shell_n *datash_n, int eval);



/* get_sigint.c */
void get_sigint_n(int sig_n);



/* aux_help.c */
void _help_env_n(void);
void _help_setenv_n(void);
void _help_unsetenv_n(void);
void _help_general_n(void);
void _help_exit_n(void);



/* aux_help2.c */
void _help_n(void);
void _help_alias_n(void);
void _help_cd_n(void);



/* get_help.c */
int get_help_n(data_shell_n *datash_n);

#endif
