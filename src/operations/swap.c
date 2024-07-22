#include "push_swap.h"

void	ft_swap(t_node **stack)
{
	t_node	*ptr;

	if (!stack || !(*stack)->next)
		return ;
	ptr = (*stack)->next;
	(*stack)->next = ptr->next;
	ptr->next = *stack;
	*stack = ptr;
}

void	sa(t_node **stack_a)
{
	ft_swap(stack_a);
	ft_printf("sa\n");
}

void	sb(t_node **stack_b)
{
	ft_swap(stack_b);
	ft_printf("sb\n");
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_printf("ss\n");
}
