#include "push_swap.h"

void	ft_print_list(t_node *stack)
{
	t_node	*ptr;

	ptr = stack;
	while (ptr)
	{
		ft_print_node_data(ptr);
		ptr = ptr->next;
	}
}

void	ft_print_stack(t_node *stack, char *name)
{
	ft_print_list(stack);
	ft_printf("%s\n----------\n", name);
}
