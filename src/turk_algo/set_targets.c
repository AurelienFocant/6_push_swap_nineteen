/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_targets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:37:36 by afocant           #+#    #+#             */
/*   Updated: 2024/09/04 14:05:05 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_target_bigger(t_node *node, t_node **stack)
{
	t_node	*ptr;
	long	target;

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

void	ft_set_targets_bigger(t_node **stack_from, t_node **stack_to)
{
	t_node	*ptr;

	ptr = *stack_from;
	while (ptr)
	{
		ft_find_target_bigger(ptr, stack_to);
		ptr = ptr->next;
	}
}

void	ft_find_target_smaller(t_node *node, t_node **stack)
{
	t_node	*ptr;
	long	target;

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

void	ft_set_targets_smaller(t_node **stack_from, t_node **stack_to)
{
	t_node	*ptr;

	ptr = *stack_from;
	while (ptr)
	{
		ft_find_target_smaller(ptr, stack_to);
		ptr = ptr->next;
	}
}
