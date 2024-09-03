/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_costs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:48:37 by afocant           #+#    #+#             */
/*   Updated: 2024/09/03 20:42:23 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	fn_count_moves_to_top(t_node *node, t_node *stack)
{
	unsigned int	position;
	unsigned int	len;
	unsigned int	median;

	len = fn_stacklen(stack);
	median = len / 2;
	position = fn_find_position(node, stack);
	if (position <= median)
		return (position);
	else
		return (len - position);
}

int	fn_find_cost(t_node *node, t_node **stack_a, t_node **stack_b)
{
	unsigned int	cost;

	cost = 0;
	cost += fn_count_moves_to_top(node, *stack_a);
	cost += fn_count_moves_to_top(node->target, *stack_b);
	return (cost);
}

void	ft_set_costs(t_node **stack_a, t_node **stack_b)
{
	t_node	*ptr;

	ptr = *stack_a;
	while (ptr)
	{
		ptr->cost = fn_find_cost(ptr, stack_a, stack_b);
		ptr = ptr->next;
	}
}
