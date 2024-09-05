/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:50:15 by afocant           #+#    #+#             */
/*   Updated: 2024/09/05 23:21:30 by afocant          ###   ########.fr       */
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

# define A 0
# define B 1

# define CHECKER 0
# define PRINT 1

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*target;
	int				cost;
}					t_node;

# include "prototypes_push_swap.h"

#endif
