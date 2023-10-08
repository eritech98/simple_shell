#include "main.h"

/**
* read_line_n - reads input string.
*
* @e_eof: return value of getline funct
* Return: input string_
*/
char *read_line_n(int *e_eof)
{
char *input_n = NULL;
size_t buffsize = 0;

*e_eof = getline(&input_n, &buffsize, stdin);

return (input_n);
}
