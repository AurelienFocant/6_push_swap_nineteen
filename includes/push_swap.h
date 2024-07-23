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
void	ft_error_and_exit(char *msg, int nb_error);
void	ft_check_arg_errors(int argc, char **argv);
void	ft_free_linkedlist(t_node *lst);
void	ft_free_lists(t_node *stack_a, t_node *stack_b);

/*----------------  list_init.c  ---------------*/
void	ft_print_node_data(t_node *node);
void	ft_init_stack(char **argv, t_node **stack_a);
void	ft_create_node(int data, t_node **stack_a);

/*----------------  print_list.c  ---------------*/
void	ft_print_list(t_node *stack);
void	ft_print_stack(t_node *stack, char *name);

/*----------------  search_list.c  ---------------*/
t_node	*ft_get_last_node(t_node **stack);
t_node	*ft_get_penult_node(t_node **stack, t_node **last_node);

/*----------------  main.c  ---------------*/
int main(int argc, char **argv);

/*----------------  push.c  ---------------*/
void	ft_push(t_node **stack_from, t_node **stack_to);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);

/*----------------  reverse_rotate.c  ---------------*/
t_node	*ft_get_penult_node(t_node **stack, t_node **last_node);
void	ft_reverse_rotate(t_node **stack);
void	rra(t_node **stack);
void	rrb(t_node **stack);
void	rrr(t_node **stack_a, t_node **stack_b);

/*----------------  rotate.c  ---------------*/
void	ft_rotate(t_node **stack);
void	ra(t_node **stack);
void	rb(t_node **stack);
void	rr(t_node **stack_a, t_node **stack_b);

/*----------------  swap.c  ---------------*/
void	ft_swap(t_node **stack);
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
#endif
