#include "push_swap.h"

void	ft_error_and_exit(char *msg, int nb_error)
{
	printf("%s\n", msg);
	exit(nb_error);
}

void	ft_check_arg_errors(int argc, char **argv)
{
	if (argc < 2)
		ft_error_and_exit("Error", 1);

	if (argc == 2)
		(void) argv;
		// if just one digit, it is sorted already
		// otherwise if a string
		// split the string
}

