#include "push_swap.h"

void	ft_test_ops(t_node *stack_a, t_node *stack_b)
{
	ft_print_stack(stack_a, "A===");
	ft_swap(&stack_a);
	ft_print_stack(stack_a, "A===");
	ft_push(&stack_a, &stack_b);
	ft_print_stack(stack_a, "A===");
	ft_print_stack(stack_b, "B===");
	ft_reverse_rotate(&stack_a);
	ft_print_stack(stack_a, "A===");
	ft_rotate(&stack_b);
	ft_print_stack(stack_b, "B===");
}

int main(int argc, char **argv)
{
	t_node	*stack_a;

	ft_check_arg_errors(argc, argv);

	stack_a = NULL;
	ft_init_stack(argv, &stack_a);

	exit(0);
}
