/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 21:02:17 by afocant           #+#    #+#             */
/*   Updated: 2024/09/05 21:10:15 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_str_nbr(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (FALSE);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	ft_check_non_integers(char **argv)
{
	size_t	i;

	i = 0;
	while (argv[i])
	{
		if (!ft_is_str_nbr(argv[i]))
			return (FALSE);
		if (ft_atol(argv[i]) > (long) INT_MAX)
			return (FALSE);
		if (ft_atol(argv[i]) < (long) INT_MIN)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	ft_check_duplicates(char **argv, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

char	**ft_parse_str(char *str, size_t size)
{
	char **av;

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
