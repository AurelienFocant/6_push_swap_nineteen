/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:03:17 by afocant           #+#    #+#             */
/*   Updated: 2024/09/05 22:45:55 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_node **stack)
{
	t_node	*ptr;
	t_node	*last_node;

	last_node = ft_get_last_node(stack);
	if (!last_node || last_node == *stack)
		return ;
	ptr = *stack;
	*stack = ptr->next;
	last_node->next = ptr;
	ptr->next = NULL;
}

void	ch_ra(t_node **stack)
{
	ft_rotate(stack);
}

void	ch_rb(t_node **stack)
{
	ft_rotate(stack);
}

void	ch_rr(t_node **stack_a, t_node **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
}
