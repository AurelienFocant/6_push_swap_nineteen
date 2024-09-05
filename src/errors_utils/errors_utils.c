/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:50:39 by afocant           #+#    #+#             */
/*   Updated: 2024/09/05 21:03:42 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_exit(char *msg, int exitcode)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	exit(exitcode);
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

void	ft_free_error_exit(char **av, char *msg, int exitcode)
{
	(void) av;
	ft_free_strv(av);
	ft_error_exit(msg, exitcode);
}
