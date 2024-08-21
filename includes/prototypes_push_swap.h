#include "push_swap.h"

/*----------------  errors_utils.c  ---------------*/
void	ft_print_error(char *str);
void	ft_error_and_exit(char *msg, int nb_error);
int	ft_is_str_nbr(char *str);
void	ft_check_non_integers(char **argv);
void	ft_check_duplicates(char **argv, size_t size);
void	ft_check_arg_errors(int argc, char **argv);

/*----------------  list_init.c  ---------------*/
void	ft_print_node_data(t_node *node);
void	ft_init_stack(char **argv, t_node **stack_a);
void	ft_create_node(int data, t_node **stack_a);
void	ft_free_linkedlist(t_node *lst);
void	ft_free_lists(t_node *stack_a, t_node *stack_b);

/*----------------  print_list.c  ---------------*/
void	ft_print_list(t_node *stack);
void	ft_print_stack(t_node *stack, char *name);

/*----------------  search_list.c  ---------------*/
t_node	*ft_get_last_node(t_node **stack);
t_node	*ft_get_penult_node(t_node **stack, t_node **last_node);

/*----------------  main.c  ---------------*/
void	ft_test_ops(t_node *stack_a, t_node *stack_b);

/*----------------  push.c  ---------------*/
void	ft_push(t_node **stack_from, t_node **stack_to);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);

/*----------------  reverse_rotate.c  ---------------*/
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
