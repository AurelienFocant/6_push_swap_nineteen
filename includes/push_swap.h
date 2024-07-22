#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>

#include "libft.h"

typedef struct	s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

/*----------------  errors_utils.c  ---------------*/
void    ft_error_and_exit(char *msg, int nb_error);
void    ft_check_arg_errors(int argc, char **argv);
void    ft_free_lists(t_node *stack_a, t_node *stack_b);

/*----------------  main.c  ---------------*/
void    ft_init_stacks(char **argv, t_node **stack_a);
void    ft_create_node(int data, t_node **stack_a);
int main(int argc, char **argv);

void	ft_swap(t_node **stack);

#endif
