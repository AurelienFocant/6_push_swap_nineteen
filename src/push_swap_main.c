/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:51:03 by afocant           #+#    #+#             */
/*   Updated: 2024/08/23 16:38:40 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*fn_find_target(int data, t_node **stack_b)
{
	t_node	*target;
	t_node	*ptr;
	long	min;

	min = LONG_MIN;
	ptr = *stack_b;
	while (ptr)
	{
		if (ptr->data < data && ptr->data > min)
		{
			min = ptr->data;
			target = ptr;
		}
		ptr = ptr->next;
	}
	if (min == LONG_MIN)
		target = fn_find_max(*stack_b);

	return (target);
}

void	fn_set_targets(t_node **stack_a, t_node **stack_b)
{
	t_node	*ptr;

	ptr = *stack_a;
	while (ptr)
	{
		ptr->target = fn_find_target(ptr->data, stack_b);
		ptr = ptr->next;
	}
}

unsigned int	fn_find_position(int value, t_node *stack)
{
	unsigned int	pos;
	t_node			*ptr;

	pos = 0;
	ptr = stack;
	while (ptr && ptr->data != value)
	{
		pos++;
		ptr = ptr->next;
	}
	return (pos);
}

unsigned int	fn_count_moves_to_top(t_node *node, t_node *stack)
{
	unsigned int	moves;
	unsigned int	len;
	unsigned int	median;
	unsigned int	position;

	len = fn_stacklen(stack);
	median = len / 2;
	moves = 0;
	position = fn_find_position(node->data, stack);
	if (position <= median)
	{
		node->is_above_median = 1;
		moves = position;
	}
	else
	{
		node->is_above_median = 0;
		moves = len - position;
	}
	return (moves);
}

int	fn_find_cost(t_node *node, t_node **stack_a, t_node **stack_b)
{
	unsigned int	cost;

	cost = 0;
	cost += fn_count_moves_to_top(node, *stack_a);
	cost += fn_count_moves_to_top(node->target, *stack_b);
	if (node->is_above_median == node->target->is_above_median)
	{
		if (cost % 2 == 0)
			cost /= 2;
		else
			cost = cost / 2 - 1;
	}
	return (cost);
}

void	fn_set_cost(t_node **stack_a, t_node **stack_b)
{
	t_node	*node;

	node = *stack_a;
	while (node)
	{
		node->cost = fn_find_cost(node, stack_a, stack_b);
		node = node->next;
	}
}

void	fn_push_swap(t_node **stack_a, t_node **stack_b)
{
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	
	fn_set_targets(stack_a, stack_b);
	fn_set_cost(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	ft_check_arg_errors(argc, argv);

	stack_a = NULL;
	stack_b = NULL;
	ft_init_stack(argv, &stack_a);

	fn_push_swap(&stack_a, &stack_b);

	exit(EXIT_SUCCESS);
}
