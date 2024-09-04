/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:12:53 by afocant           #+#    #+#             */
/*   Updated: 2024/09/04 22:42:11 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**av;
	t_node	*stack_a;
	t_node	*stack_b;

	av = ft_check_arg_errors(argc, argv);
	stack_a = NULL;
	stack_b = NULL;
	ft_init_stack(av, &stack_a);
	if (fn_stacklen(stack_a) == 2)
		fn_sort_two(&stack_a);
	else if (fn_stacklen(stack_a) == 3)
		fn_sort_three(&stack_a);
	else
		ft_turk_algo(&stack_a, &stack_b);
	ft_free_linkedlist(stack_a);
	if (argc == 2)
		ft_free_strv(av);
	return (EXIT_SUCCESS);
}
