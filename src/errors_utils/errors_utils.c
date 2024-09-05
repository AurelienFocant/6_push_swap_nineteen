/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:50:39 by afocant           #+#    #+#             */
/*   Updated: 2024/09/05 00:10:47 by afocant          ###   ########.fr       */
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

void	ft_free_null(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

void	ft_free_strv(char **av)
{
	char	**ptr;

	ptr = av;
	while (*ptr)
	{
		ft_free_null(*ptr);
		ptr++;
	}
	ft_free_null(*ptr);
	free(av);
}

void	fn_free_error_exit(char **av, char *msg, int exitcode)
{
	(void) av;
	ft_free_strv(av);
	fn_error_exit(msg, exitcode);
}

char	**ft_parse_str(char *str, size_t size)
{
	char **av;

	av = ft_split(str, ' ');
	if (!av)
		fn_error_exit("error parsing argument string\n", 2);
	if (!*av)
		fn_free_error_exit(av, "Error\n", 3);
	if (!ft_check_non_integers(av) || !ft_check_duplicates(av, size))
		fn_free_error_exit(av, "Error\n", 4);
	return (av);
}

char	**ft_parse_args(char **argv, size_t size)
{
	if (!ft_check_non_integers(argv) || !ft_check_duplicates(argv, size))
		fn_error_exit("Error\n", 5);
	return (argv);
}

char	**ft_check_arg_errors(int argc, char **argv)
{
	char	**av;

	if (argc == 2)
		av = ft_parse_str(argv[1], (size_t) argc - 1);
	else
		av = ft_parse_args(argv + 1, (size_t) argc - 1);
	return (av);
}
