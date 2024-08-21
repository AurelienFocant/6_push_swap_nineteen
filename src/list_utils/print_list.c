/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:50:54 by afocant           #+#    #+#             */
/*   Updated: 2024/08/21 16:50:55 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_list(t_node *stack)
{
	t_node	*ptr;

	ptr = stack;
	while (ptr)
	{
		ft_print_node_data(ptr);
		ptr = ptr->next;
	}
}

void	ft_print_stack(t_node *stack, char *name)
{
	ft_print_list(stack);
	ft_printf("%s\n----------\n", name);
}
