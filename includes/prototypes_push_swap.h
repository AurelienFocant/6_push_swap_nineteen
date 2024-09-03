#ifndef PROTOTYPES_PUSH_SWAP_H
# define PROTOTYPES_PUSH_SWAP_H

# include "push_swap.h"

/*----------------  errors_utils.c  ---------------*/
void	fn_error_exit(char *msg, int exitcode);
int	ft_is_str_nbr(char *str);
void	ft_check_non_integers(char **argv);
void	ft_check_duplicates(char **argv, size_t size);
void	ft_check_arg_errors(int argc, char **argv);

/*----------------  list_init.c  ---------------*/
void	ft_init_stack(char **argv, t_node **stack_a);
void	ft_create_node(int data, t_node **stack_a);
void	ft_free_linkedlist(t_node *lst);
void	ft_free_lists(t_node *stack_a, t_node *stack_b);

/*----------------  print_list.c  ---------------*/
void	ft_print_node_data(t_node *node);
void	ft_print_list(t_node *stack);
void	ft_print_stack(t_node *stack, char *name);
void	ft_print_both_stacks(t_node *stack_a, t_node *stack_b);

/*----------------  search_list.c  ---------------*/
t_node	*ft_get_last_node(t_node **stack);
t_node	*ft_get_penult_node(t_node **stack, t_node **last_node);
unsigned int	fn_stacklen(t_node *stack);

/*----------------  main.c  ---------------*/

/*----------------  push.c  ---------------*/
void	ft_push(t_node **stack_from, t_node **stack_to);
void	pb(t_node **stack_a, t_node **stack_b);
void	pa(t_node **stack_b, t_node **stack_a);

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

/*----------------  sort_three.c  ---------------*/
t_node	*fn_find_max(t_node *stack);
t_node	*fn_find_min(t_node *stack);
int	fn_sort_three(t_node **stack);
int	fn_sort_two(t_node **stack);

/*----------------  sorting_utils.c  ---------------*/
int	fn_is_sorted(t_node *stack);

/*----------------  push_cheapest.c  ---------------*/
void	ft_rotate_stack(t_node **stack, t_node *node, int name);
void	ft_rotate_both_stacks(t_node *node, t_node **stack_a, t_node **stack_b);
t_node	*ft_find_cheapest(t_node **stack);

/*----------------  set_costs.c  ---------------*/
unsigned int	fn_count_moves_to_top(t_node *node, t_node *stack);
int	fn_find_cost(t_node *node, t_node **stack_a, t_node **stack_b);
void	ft_set_costs(t_node **stack_a, t_node **stack_b);

/*----------------  set_targets.c  ---------------*/
void	ft_find_target_bigger(t_node *node, t_node **stack);
void	ft_find_target_smaller(t_node *node, t_node **stack);
void	ft_set_targets_bigger(t_node **stack_from, t_node **stack_to);
void	ft_set_targets_smaller(t_node **stack_from, t_node **stack_to);

/*----------------  turk_algo.c  ---------------*/
unsigned int	fn_find_position(t_node *node, t_node *stack);
int	ft_is_above_median(t_node *node, t_node *stack);
void	ft_last_rotate(t_node **stack_a);
void	ft_turk_algo(t_node **stack_a, t_node **stack_b);

#endif
