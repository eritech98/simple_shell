#include"main.h"

/**
*get_sigint_n-Handlethecrtl+ccallinproMT
*@sig_n:Signalhandler
*/

void get_sigint_n(int sig_n)
{
	(void)sig_n;
	write(STDOUT_FILENO, "\nErick&_Nthati_simple_shell", 30);
}
