/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:03:13 by afocant           #+#    #+#             */
/*   Updated: 2024/09/05 22:45:09 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_node **stack)
{
	t_node	*last_node;
	t_node	*penult_node;

	last_node = ft_get_last_node(stack);
	if (!last_node || last_node == *stack)
		return ;
	penult_node = ft_get_penult_node(stack, &last_node);
	if (!penult_node)
		return ;
	last_node->next = *stack;
	*stack = last_node;
	penult_node->next = NULL;
}

void	ch_rra(t_node **stack)
{
	ft_reverse_rotate(stack);
}

void	ch_rrb(t_node **stack)
{
	ft_reverse_rotate(stack);
}

void	ch_rrr(t_node **stack_a, t_node **stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
}
