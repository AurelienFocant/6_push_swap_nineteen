/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:33:08 by afocant           #+#    #+#             */
/*   Updated: 2024/08/21 17:03:48 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(void)
{
	char	*line;

	line = ft_get_next_line(STDIN_FILENO);
	while (line)
	{
		printf("yo\n");
		line = ft_get_next_line(STDIN_FILENO);
	}
	return (0);
}
