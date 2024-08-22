/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:51:03 by afocant           #+#    #+#             */
/*   Updated: 2024/08/22 23:28:08 by afocant          ###   ########.fr       */
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
		printf("target is %i\n", ptr->target);
		ptr = ptr->next;
	}
}

unsigned int	fn_find_position(int value, t_node *stack)
{
	unsigned int	pos;
	t_node			*ptr;

	pos = 0;
	ptr = stack;
	while (ptr->data != value)
	{
		pos++;
		ptr = ptr->next;
	}
	return (--pos);
}

unsigned int	fn_count_moves_to_top(int value, t_node *stack)
{
	unsigned int	moves;
	unsigned int	len;
	unsigned int	median;
	unsigned int	position;

	len = fn_stacklen(stack);
	if (len % 2 == 0)
		median = len / 2;
	else
		median = len / 2 + 1;
	moves = 0;
	position = fn_find_position(value, stack);
	if (position < median)
		moves = position;
	else
		moves = len - position + 1;
	return (moves);
}

int	fn_find_cost(t_node *node, t_node **stack_a, t_node **stack_b)
{
	unsigned int	cost;

	cost = 0;
	cost += fn_count_moves_to_top(node->data, *stack_a);
	cost += fn_count_moves_to_top(node->target, *stack_b);
	return (cost);
}

void	fn_set_cost(t_node **stack_a, t_node **stack_b)
{
	t_node	*ptr;

	ptr = *stack_a;
	while (ptr)
	{
		ptr->cost = fn_find_cost(ptr, stack_a, stack_b);
		ptr = ptr->next;
	}
	ptr = *stack_a;
	while (ptr)
	{
		printf("cost is %i\n", ptr->cost);
		ptr = ptr->next;
	}
}

void	fn_push_swap(t_node **stack_a, t_node **stack_b)
{
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	
	fn_set_targets(stack_a, stack_b);
	fn_set_cost(stack_a, stack_b);
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
