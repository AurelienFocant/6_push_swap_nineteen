#include "push_swap.h"

void	ft_error_and_exit(char *msg, int nb_error)
{
	printf("%s\n", msg);
	exit(nb_error);
}

void	ft_check_arg_errors(int argc, char **argv)
{
	if (argc < 2)
		ft_error_and_exit("Not enough arguments", 1);

	if (argc == 2)
		(void) argv;
		// if just one digit, it is sorted already
		// otherwise if a string
		// split the string
}

void	ft_free_linkedlist(t_node *lst)
{
	t_node	*ptr;

	while (lst)
	{
		ptr = lst;
		lst = lst->next;
		free(ptr);
	}
}

void	ft_free_lists(t_node *stack_a, t_node *stack_b)
{
	ft_free_linkedlist(stack_a);
	ft_free_linkedlist(stack_b);
}
