#include "push_swap.h"

void	ft_rotate(t_node **stack)
{
	t_node	*ptr;
	t_node	*last_node;

	last_node = ft_get_last_node(stack);
	if (!last_node)
		return ;
	ptr = *stack;
	*stack = ptr->next;
	last_node->next = ptr;
	ptr->next = NULL;
}

void	ra(t_node **stack)
{
	ft_rotate(stack);
	ft_printf("ra\n");
}

void	rb(t_node **stack)
{
	ft_rotate(stack);
	ft_printf("rb\n");
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_printf("rr\n");
}
