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

unsigned int fn_find_position(t_node *node, t_node *stack)
{
	unsigned int pos;
	t_node *ptr;

	pos = 0;
	ptr = stack;
	while (ptr && ptr != node)
	{
		pos++;
		ptr = ptr->next;
	}
	return (pos);
}

void ft_find_target(t_node *node, t_node **stack)
{
	t_node *ptr;
	long target;

	target = LONG_MAX;
	ptr = *stack;
	while (ptr)
	{
		if (ptr->data > node->data && ptr->data < target)
		{
			node->target = ptr;
			target = ptr->data;
		}
		ptr = ptr->next;
	}
	if (target == LONG_MAX)
		node->target = fn_find_min(*stack);
}

void ft_find_target_min(t_node *node, t_node **stack)
{
	t_node *ptr;
	long target;

	target = LONG_MIN;
	ptr = *stack;
	while (ptr)
	{
		if (ptr->data < node->data && ptr->data > target)
		{
			node->target = ptr;
			target = ptr->data;
		}
		ptr = ptr->next;
	}
	if (target == LONG_MIN)
		node->target = fn_find_max(*stack);
}

void ft_set_targets(t_node **stack_from, t_node **stack_to)
{
	t_node *ptr;

	ptr = *stack_from;
	while (ptr)
	{
		ft_find_target(ptr, stack_to);
		ptr = ptr->next;
	}
}

void ft_set_targets_min(t_node **stack_from, t_node **stack_to)
{
	t_node *ptr;

	ptr = *stack_from;
	while (ptr)
	{
		ft_find_target_min(ptr, stack_to);
		ptr = ptr->next;
	}
}

int ft_is_above_median(t_node *node, t_node *stack)
{
	unsigned int len;
	unsigned int median;
	unsigned int position;

	len = fn_stacklen(stack);
	median = len / 2;
	position = fn_find_position(node, stack);
	if (position <= median)
		return (TRUE);
	else
		return (FALSE);
}

unsigned int fn_count_moves_to_top(t_node *node, t_node *stack)
{
	unsigned int position;
	unsigned int len;
	unsigned int median;

	len = fn_stacklen(stack);
	median = len / 2;
	position = fn_find_position(node, stack);
	if (position <= median)
		return (position);
	else
		return (len - position);
}

int fn_find_cost(t_node *node, t_node **stack_a, t_node **stack_b)
{
	unsigned int cost;

	cost = 0;
	cost += fn_count_moves_to_top(node, *stack_a);
	cost += fn_count_moves_to_top(node->target, *stack_b);
	return (cost);
}

void ft_set_costs(t_node **stack_a, t_node **stack_b)
{
	t_node *ptr;

	ptr = *stack_a;
	while (ptr)
	{
		ptr->cost = fn_find_cost(ptr, stack_a, stack_b);
		ptr = ptr->next;
	}
}

t_node *ft_find_cheapest(t_node **stack)
{
	t_node *ptr;
	long cheapest;

	ptr = *stack;
	cheapest = LONG_MAX;
	while (ptr)
	{
		if (ptr->cost == 0)
			return (ptr);
		if ((long)ptr->cost < cheapest)
			cheapest = ptr->cost;
		ptr = ptr->next;
	}
	ptr = *stack;
	while (ptr)
	{
		if (ptr->cost == cheapest)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

void ft_rotate_both_stacks(t_node *node, t_node **stack_a, t_node **stack_b)
{
	if (ft_is_above_median(node, *stack_a))
		rr(stack_a, stack_b);
	else
		rrr(stack_a, stack_b);
}

void ft_rotate_stack(t_node **stack, t_node *node, int name)
{
	if (ft_is_above_median(node, *stack))
	{
		if (name == A)
			ra(stack);
		else
			rb(stack);
	}
	else
	{
		if (name == A)
			rra(stack);
		else
			rrb(stack);
	}
}

void ft_rotate_to_top(t_node **stack_from, t_node **stack_to, t_node **cheapest, int name_from, int name_to)
{
	while (*stack_from != *cheapest && *stack_to != (*cheapest)->target && ft_is_above_median(*cheapest, *stack_from) == ft_is_above_median(*cheapest, *stack_to))
		ft_rotate_both_stacks(*cheapest, stack_from, stack_to);
	while (*stack_from != *cheapest)
		ft_rotate_stack(stack_from, *cheapest, name_from);
	while (*stack_to != (*cheapest)->target)
		ft_rotate_stack(stack_to, (*cheapest)->target, name_to);
}

void ft_push_cheapest(t_node **stack_from, t_node **stack_to, int name_from, int name_to)
{
	t_node *cheapest;

	cheapest = ft_find_cheapest(stack_from);
	ft_rotate_to_top(stack_from, stack_to, &cheapest, name_from, name_to);
	if (name_from == A)
		pb(stack_from, stack_to);
	else if (name_from == B)
		pa(stack_from, stack_to);
}

void	ft_last_rotate(t_node **stack_a)
{
	t_node	*min;

	min = fn_find_min(*stack_a);
	while (*stack_a != min)
	{
		if (ft_is_above_median(min, *stack_a))
			ra(stack_a);
		else
			rra(stack_a);
	}
}


void ft_push_swap(t_node **stack_a, t_node **stack_b)
{
	int n;
	int len;

	n = 2;
	len = fn_stacklen(*stack_a);
	// ft_print_both_stacks(*stack_a, *stack_b);
	while (len > 3 && n--)
	{
		pb(stack_a, stack_b);
		len--;
	}
	// ft_print_both_stacks(*stack_a, *stack_b);
	while (len-- > 3)
	{
		ft_set_targets_min(stack_a, stack_b);
		ft_set_costs(stack_a, stack_b);
		ft_push_cheapest(stack_a, stack_b, A, B);
		// ft_print_both_stacks(*stack_a, *stack_b);
	}
	fn_sort_three(stack_a);
	// ft_print_both_stacks(*stack_a, *stack_b);
	len = fn_stacklen(*stack_b);
	while (len--)
	{
		ft_set_targets(stack_b, stack_a);
		ft_set_costs(stack_b, stack_a);
		ft_push_cheapest(stack_b, stack_a, B, A);
		// ft_print_both_stacks(*stack_a, *stack_b);
	}
	ft_last_rotate(stack_a);
}

int main(int argc, char **argv)
{
	t_node *stack_a;
	t_node *stack_b;

	ft_check_arg_errors(argc, argv);

	stack_a = NULL;
	stack_b = NULL;
	ft_init_stack(argv, &stack_a);

	// ft_check_if sorted or <= 3
	ft_push_swap(&stack_a, &stack_b);
	return (EXIT_SUCCESS);
}
