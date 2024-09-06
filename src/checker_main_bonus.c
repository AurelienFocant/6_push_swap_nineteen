/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:33:08 by afocant           #+#    #+#             */
/*   Updated: 2024/09/06 00:24:38 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_checker_error(t_node **stack_a, t_node **stack_b)
{
	ft_free_lists(*stack_a, *stack_b);
	ft_error_exit("Error\n", 18);
}

void	ft_execute_cmd(char *line, t_node **stack_a, t_node **stack_b)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sa(stack_a, CHECKER);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(stack_b, CHECKER);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(stack_a, stack_b, CHECKER);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa(stack_b, stack_a, CHECKER);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(stack_a, stack_b, CHECKER);
	else if (ft_strcmp(line, "ra\n") == 0)
		ra(stack_a, CHECKER);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb(stack_b, CHECKER);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(stack_a, stack_b, CHECKER);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra(stack_a, CHECKER);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(stack_b, CHECKER);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(stack_a, stack_b, CHECKER);
	else
		ft_checker_error(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	char	*line;
	char	**av;
	t_node	*stack_a;
	t_node	*stack_b;

	av = ft_check_arg_errors(argc, argv);
	stack_a = NULL;
	stack_b = NULL;
	ft_init_stack(av, &stack_a);
	line = ft_get_next_line(STDIN_FILENO);
	while (line)
	{
		ft_execute_cmd(line, &stack_a, &stack_b);
		free(line);
		line = ft_get_next_line(STDIN_FILENO);
	}
	if (ft_is_sorted(stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_free_linkedlist(stack_a);
	return (0);
}
