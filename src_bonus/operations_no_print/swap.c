/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:03:23 by afocant           #+#    #+#             */
/*   Updated: 2024/09/05 22:46:35 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_node **stack)
{
	t_node	*ptr;

	if (!*stack || !(*stack)->next)
		return ;
	ptr = (*stack)->next;
	(*stack)->next = ptr->next;
	ptr->next = *stack;
	*stack = ptr;
}

void	ch_sa(t_node **stack_a)
{
	ft_swap(stack_a);
}

void	ch_sb(t_node **stack_b)
{
	ft_swap(stack_b);
}

void	ch_ss(t_node **stack_a, t_node **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
}
