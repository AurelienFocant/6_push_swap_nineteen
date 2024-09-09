/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:31:12 by afocant           #+#    #+#             */
/*   Updated: 2024/09/09 13:31:13 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_parse_str(char *str, size_t size)
{
	char	**av;

	av = ft_split(str, ' ');
	if (!av)
		ft_error_exit("error parsing argument string\n", 2);
	if (!*av)
		ft_free_error_exit(av, "Error\n", 3);
	if (!ft_check_non_integers(av) || !ft_check_duplicates(av, size))
		ft_free_error_exit(av, "Error\n", 4);
	return (av);
}

char	**ft_parse_args(char **argv, size_t size)
{
	if (!ft_check_non_integers(argv) || !ft_check_duplicates(argv, size))
		ft_error_exit("Error\n", 5);
	return (argv);
}
