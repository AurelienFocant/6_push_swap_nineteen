/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:50:15 by afocant           #+#    #+#             */
/*   Updated: 2024/08/22 21:35:28 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include "libft.h"

# define FALSE 0
# define TRUE 1

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	int				target;
	int				cost;
}				t_node;

# include "prototypes_push_swap.h"

#endif
