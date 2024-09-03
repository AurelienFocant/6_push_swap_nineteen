/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:00:18 by afocant           #+#    #+#             */
/*   Updated: 2024/09/03 20:25:36 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fn_is_sorted(t_node *stack)
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
