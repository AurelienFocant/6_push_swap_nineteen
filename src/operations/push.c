/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:03:09 by afocant           #+#    #+#             */
/*   Updated: 2024/08/23 18:27:15 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_node **stack_from, t_node **stack_to)
{
	t_node	*ptr;

	ptr = *stack_from;
	if (!ptr)
		return ;
	*stack_from = (*stack_from)->next;
	if (!*stack_to)
	{
		*stack_to = ptr;
		ptr->next = NULL;
	}
	else
	{
		ptr->next = *stack_to;
		*stack_to = ptr;
	}
	ptr = NULL;
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	ft_push(stack_a, stack_b);
	ft_printf("pb\n");
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	ft_push(stack_b, stack_a);
	ft_printf("pa\n");
}
