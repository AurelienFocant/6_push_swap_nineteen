/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:50:15 by afocant           #+#    #+#             */
/*   Updated: 2024/08/30 15:32:01 by afocant          ###   ########.fr       */
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
	struct s_node	*target;
	int				cost;
}					t_node;

typedef struct s_stacklen
{
	int	a;
	int	b;
}		t_stacklen;

# include "prototypes_push_swap.h"

#endif
