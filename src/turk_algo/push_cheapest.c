/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:51:24 by afocant           #+#    #+#             */
/*   Updated: 2024/09/03 20:40:48 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_stack(t_node **stack, t_node *node, int name)
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

void	ft_rotate_both_stacks(t_node *node, t_node **stack_a, t_node **stack_b)
{
	if (ft_is_above_median(node, *stack_a))
		rr(stack_a, stack_b);
	else
		rrr(stack_a, stack_b);
}

t_node	*ft_find_cheapest(t_node **stack)
{
	t_node	*ptr;
	long	cheapest;

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

int	ft_double_rotate_possible(t_node *cheapest,
		t_node *stack_from, t_node *stack_to)
{
	int	from;
	int	to;

	from = ft_is_above_median(*cheapest, *stack_from);
	to = ft_is_above_median((*cheapest)->target, *stack_to);
	if (from == to)
		return (TRUE);
	else
		return (FALSE);
}

void	ft_push_cheapest(t_node **stack_from, t_node **stack_to,
		int name_from, int name_to)
{
	t_node	*cheapest;

	cheapest = ft_find_cheapest(stack_from);
	while (*stack_from != *cheapest
		&& *stack_to != (*cheapest)->target
		&& ft_double_rotate_possible(cheapest, *stack_from, *stack_to))
		ft_rotate_both_stacks(*cheapest, stack_from, stack_to);
	while (*stack_from != *cheapest)
		ft_rotate_stack(stack_from, *cheapest, name_from);
	while (*stack_to != (*cheapest)->target)
		ft_rotate_stack(stack_to, (*cheapest)->target, name_to);
	if (name_from == A)
		pb(stack_from, stack_to);
	else if (name_from == B)
		pa(stack_from, stack_to);
}
