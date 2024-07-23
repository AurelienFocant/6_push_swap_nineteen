#include "push_swap.h"

void	ft_print_node_data(t_node *node)
{
	if (!node)
		return ;
	ft_printf("%i\n", node->data);
}

void	ft_init_stack(char **argv, t_node **stack_a)
{
	size_t	i;

	i = 1;
	while (argv[i])
	{
		ft_create_node(ft_atoi(argv[i]), stack_a);
		i++;
	}
}

void	ft_create_node(int data, t_node **stack_a)
{
	t_node	*new_node;
	t_node	*ptr;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
	{
		ft_free_lists(*stack_a, NULL);
		ft_error_and_exit("Error creating a node", 3);
	}
	new_node->data = data;
	new_node->next = NULL;


	if (!*stack_a)
		*stack_a = new_node;
	else
	{
		ptr = *stack_a;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new_node;
	}
}
