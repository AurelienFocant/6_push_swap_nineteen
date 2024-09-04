/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:50:39 by afocant           #+#    #+#             */
/*   Updated: 2024/09/04 23:32:37 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fn_error_exit(char *msg, int exitcode)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	//system("leaks push_swap");
	exit(exitcode);
}

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

void	ft_check_non_integers(char **argv)
{
	size_t	i;

	i = 0;
	while (argv[i])
	{
		if (!ft_is_str_nbr(argv[i]))
			fn_error_exit("Error\n", 2);
		if (ft_atol(argv[i]) > (long) INT_MAX)
			fn_error_exit("Error\n", 3);
		if (ft_atol(argv[i]) < (long) INT_MIN)
			fn_error_exit("Error\n", 4);
		i++;
	}
}

void	ft_check_duplicates(char **argv, size_t size)
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
				fn_error_exit("Error\n", 5);
			j++;
		}
		i++;
	}
}

void	ft_free_strv(char **av)
{
	while (*av)
	{
		free(*av);
		*av = NULL;
		av++;
	}
}

char	**ft_check_arg_errors(int argc, char **argv)
{
	char	**av;

	if (argc == 2)
	{
		av = ft_split(argv[1], ' ');
		if (!av)
			fn_error_exit("error parsing argument string\n", 2);
		if (!*av)
			fn_error_exit("Error\n", 2);
	}
	else
		av = argv + 1;
	ft_check_non_integers(av);
	ft_check_duplicates(av, ((size_t) argc - 1));
	return (av);
}
