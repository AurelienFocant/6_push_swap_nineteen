/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:51:03 by afocant           #+#    #+#             */
/*   Updated: 2024/08/22 21:15:25 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fn_find_target(int data, t_node **stack_b)
{
	int	tmp;
	int	target;
	t_node	*ptr;

	tmp = INT_MIN;
	target = INT_MIN;
	ptr = *stack_b;
	while (ptr)
	{
		if (ptr->data < data)
			tmp = ptr->data;
		if (tmp > target)
			target = tmp;
		ptr = ptr->next;
	}
	return (target);
}

void	fn_set_targets(t_node **stack_a, t_node **stack_b)
{
	t_node	*ptr;

	ptr = *stack_a;
	while (ptr)
	{
		ptr->target = fn_find_target(ptr->data, stack_b);
		ptr = ptr->next;
	}
	ptr = *stack_a;
	while (ptr)
	{
		printf("%i\n", ptr->target);
		ptr = ptr->next;
	}
	return;
}

void	fn_push_swap(t_node **stack_a, t_node **stack_b)
{
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	
	fn_set_targets(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	ft_check_arg_errors(argc, argv);

	stack_a = NULL;
	stack_b = NULL;
	ft_init_stack(argv, &stack_a);

	fn_push_swap(&stack_a, &stack_b);

	exit(EXIT_SUCCESS);
}
