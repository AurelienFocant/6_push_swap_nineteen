/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:12:53 by afocant           #+#    #+#             */
/*   Updated: 2024/08/30 15:44:36 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap(t_node **stack_a, t_node **stack_b)
{
	(void) stack_a;
	(void) stack_b;
	return ;
}

void	ft_test_lists(t_node **stack_a, t_node **stack_b, t_stacklen *stacklen)
{
	printf("len_a: %i\n", stacklen->a);
	printf("len_b: %i\n", stacklen->b);
	ft_print_both_stacks(*stack_a, *stack_b);
	pb(stack_a, stack_b, stacklen);
	pb(stack_a, stack_b, stacklen);
	pb(stack_a, stack_b, stacklen);
	printf("len_a: %i\n", stacklen->a);
	printf("len_b: %i\n", stacklen->b);
	ft_print_both_stacks(*stack_a, *stack_b);
	pa(stack_a, stack_b, stacklen);
	printf("len_a: %i\n", stacklen->a);
	printf("len_b: %i\n", stacklen->b);
	ft_print_both_stacks(*stack_a, *stack_b);
}

int main(int argc, char **argv)
{
	t_node		*stack_a;
	t_node		*stack_b;
	t_stacklen	stacklen;

	ft_check_arg_errors(argc, argv);

	stack_a = NULL;
	stack_b = NULL;
	ft_init_stack(argv, &stack_a, &stacklen);

	ft_test_lists(&stack_a, &stack_b, &stacklen);

	// ft_check_if sorted or <= 3
	ft_push_swap(&stack_a, &stack_b);
	return (EXIT_SUCCESS);
}
