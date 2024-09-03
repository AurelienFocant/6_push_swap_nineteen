/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:19:13 by afocant           #+#    #+#             */
/*   Updated: 2024/09/03 20:24:00 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*fn_find_max(t_node *stack)
{
	t_node	*res;
	int		max;

	res = NULL;
	max = INT_MIN;
	while (stack)
	{
		if (stack->data > max)
		{
			max = stack->data;
			res = stack;
		}
		stack = stack->next;
	}
	return (res);
}

t_node	*fn_find_min(t_node *stack)
{
	t_node	*res;
	int		min;

	res = NULL;
	min = INT_MAX;
	while (stack)
	{
		if (stack->data < min)
		{
			min = stack->data;
			res = stack;
		}
		stack = stack->next;
	}
	return (res);
}

int	fn_sort_three(t_node **stack)
{
	t_node	*max;

	if (fn_is_sorted(*stack))
		return (TRUE);
	max = fn_find_max(*stack);
	if (*stack == max)
		ra(stack);
	else if ((*stack)->next == max)
		rra(stack);
	if (!fn_is_sorted(*stack))
		sa(stack);
	return (TRUE);
}

int	fn_sort_two(t_node **stack)
{
	if ((*stack)->data > (*stack)->next->data)
		sa(stack);
	return (TRUE);
}
