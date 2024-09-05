/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:19:13 by afocant           #+#    #+#             */
/*   Updated: 2024/09/05 21:07:13 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_find_max(t_node *stack)
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

t_node	*ft_find_min(t_node *stack)
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

int	ft_sort_three(t_node **stack)
{
	t_node	*max;

	if (ft_is_sorted(*stack))
		return (TRUE);
	max = ft_find_max(*stack);
	if (*stack == max)
		ra(stack);
	else if ((*stack)->next == max)
		rra(stack);
	if (!ft_is_sorted(*stack))
		sa(stack);
	return (TRUE);
}

int	ft_sort_two(t_node **stack)
{
	if ((*stack)->data > (*stack)->next->data)
		sa(stack);
	return (TRUE);
}

int	ft_is_sorted(t_node *stack)
{
	int		min;

	min = INT_MIN;
	while (stack)
	{
		if (stack->data < min)
			return (FALSE);
		min = stack->data;
		stack = stack->next;
	}
	return (TRUE);
}
