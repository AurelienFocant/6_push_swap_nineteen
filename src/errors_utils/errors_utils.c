/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:50:39 by afocant           #+#    #+#             */
/*   Updated: 2024/08/22 20:06:16 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fn_error_exit(char *msg, int exitcode)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	exit(exitcode);
}

int	ft_is_str_nbr(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_check_non_integers(char **argv)
{
	size_t	i;

	i = 1;
	while (argv[i])
	{
		if (!ft_is_str_nbr(argv[i]))
			fn_error_exit("Arg is not a number", 2);
		if (ft_atol(argv[i]) > (long) INT_MAX)
			fn_error_exit("Arg is too big to be an int", 3);
		if (ft_atol(argv[i]) < (long) INT_MIN)
			fn_error_exit("Arg is too small to be an int", 4);
		i++;
	}
}

void	ft_check_duplicates(char **argv, size_t size)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				fn_error_exit("Duplicates args", 5);
			j++;
		}
		i++;
	}
}

void	ft_check_arg_errors(int argc, char **argv)
{
	if (argc < 2)
		fn_error_exit("Not enough arguments", 1);
	// if just one digit, it is sorted already
	// otherwise if a string
	// split the string
	ft_check_non_integers(argv);
	ft_check_duplicates(argv, ((size_t) argc));
}
