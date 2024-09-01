/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:12:53 by afocant           #+#    #+#             */
/*   Updated: 2024/08/30 15:44:36 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_target(t_node *node, t_node **stack)
{
	t_node	*ptr;
	long	target;

	target = LONG_MIN;
	ptr = *stack
	while (ptr)
	{
		if (ptr->value < node->value && ptr->value > target)
		{
			node->target = ptr;
			target = ptr->value;
		}
		ptr = ptr->next;
	}
	if (target == LONG_MIN)
		node->target = fn_find_max(stack);
}

void	ft_set_targets(t_node **stack_from, t_node **stack_to, t_stacklen *stacklen)
{
	t_node	*ptr;

	ptr = *stack_from;
	while (*ptr)
	{
		ft_find_target(ptr, stack_to);
		ptr = ptr->next;
	}
}

void	ft_push_swap(t_node **stack_a, t_node **stack_b, t_stacklen *stacklen)
{
	int	n;

	n = 2;
	while (stacklen->a > 3 && n--)
		pb(stack_a, stack_b, stacklen);
	while (stacklen->a > 3)
	{
		ft_set_targets(stack_a, stack_b, stacklen);
		ft_calc_costs(stack_a, stack_b, stacklen);
		ft_push_cheapest(stack_a, stack_b, stacklen);
	}
	ft_sort_three(stack_a, stack_b, stacklen);
	while (stacklen->b)
	{
		ft_set_targets(stack_b, stack_a, stacklen);
		ft_calc_costs(stack_b, stack_a, stacklen);
		ft_push_cheapest(stack_b, stack_a, stacklen);
	}
	return ;
}

void	ft_test_lists(t_node **stack_a, t_node **stack_b, t_stacklen *stacklen)
{
	printf("len_a: %i\n", stacklen->a);
	printf("len_b: %i\n", stacklen->b);
	ft_print_both_stacks(*stack_a, *stack_b);
	pb(stack_a, stack_b, stacklen);
	pb(stack_a, stack_b, stacklen);
	pb(stack_a, stack_b, stacklen);
	printf("len_a: %i\n", stacklen->a);
	printf("len_b: %i\n", stacklen->b);
	ft_print_both_stacks(*stack_a, *stack_b);
	pa(stack_a, stack_b, stacklen);
	printf("len_a: %i\n", stacklen->a);
	printf("len_b: %i\n", stacklen->b);
	ft_print_both_stacks(*stack_a, *stack_b);
}

int main(int argc, char **argv)
{
	t_node		*stack_a;
	t_node		*stack_b;
	t_stacklen	stacklen;

	ft_check_arg_errors(argc, argv);

	stack_a = NULL;
	stack_b = NULL;
	ft_init_stack(argv, &stack_a, &stacklen);

	ft_test_lists(&stack_a, &stack_b, &stacklen);

	// ft_check_if sorted or <= 3
	ft_push_swap(&stack_a, &stack_b, &stacklen);
	return (EXIT_SUCCESS);
}
