/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:19:13 by afocant           #+#    #+#             */
/*   Updated: 2024/08/22 20:06:39 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fn_find_max(t_node *stack)
{
	int	max;
	t_node	*ptr;

	max = INT_MIN;
	ptr = stack;
	while (ptr)
	{
		if (ptr->data > max)
			max = ptr->data;
		ptr = ptr->next;
	}
	return (max);
}

int	fn_find_min(t_node *stack)
{
	int	min;
	t_node	*ptr;

	min = INT_MAX;
	ptr = stack;
	while (ptr)
	{
		if (ptr->data < min)
			min = ptr->data;
		ptr = ptr->next;
	}
	return (min);
}

int	fn_sort_three(t_node **stack)
{
	int	max;

	if (fn_is_sorted(*stack))
			return (TRUE);
	max = fn_find_max(*stack);
	if ((*stack)->data == max)
		ra(stack);
	else if ((*stack)->next->data == max)
		rra(stack);
	if (!fn_is_sorted(*stack))
		sa(stack);
	return (TRUE);
}
