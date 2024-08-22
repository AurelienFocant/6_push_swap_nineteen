/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:00:18 by afocant           #+#    #+#             */
/*   Updated: 2024/08/22 20:01:46 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fn_is_sorted(t_node *stack_a)
{
	int		min;
	t_node *ptr;

	min = INT_MIN;
	ptr = stack_a;
	while (ptr)
	{
		if (ptr->data < min)
			return (FALSE);
		min = ptr->data;
		ptr = ptr->next;
	}
	return (TRUE);
}
