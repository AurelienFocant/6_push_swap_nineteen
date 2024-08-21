/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:33:08 by afocant           #+#    #+#             */
/*   Updated: 2024/08/21 17:50:38 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "prototypes_push_swap.h"
#include "checker.h"

int	main(int argc, char **argv)
{
	char	*line;

	t_node	*stack_a;
	t_node	*stack_b;

	ft_check_arg_errors(argc, argv);

	stack_a = NULL;
	stack_b = NULL;
	ft_init_stack(argv, &stack_a);

	line = ft_get_next_line(STDIN_FILENO);
	while (line)
	{
		if (ft_strcmp(line, "ra\n"))
			printf("ra\n");
		line = ft_get_next_line(STDIN_FILENO);
	}
	return (0);
}
