/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:12:53 by afocant           #+#    #+#             */
/*   Updated: 2024/09/04 13:54:55 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	ft_check_arg_errors(argc, argv);
	stack_a = NULL;
	stack_b = NULL;
	ft_init_stack(argv, &stack_a);
	if (fn_stacklen(stack_a) == 2)
		fn_sort_two(&stack_a);
	if (fn_stacklen(stack_a) == 3)
		fn_sort_three(&stack_a);
	ft_turk_algo(&stack_a, &stack_b);
	return (EXIT_SUCCESS);
}
