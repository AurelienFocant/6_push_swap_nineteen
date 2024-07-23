#include "push_swap.h"

t_node	*ft_get_last_node(t_node **stack)
{
	t_node	*ptr;

	if (!*stack)
		return (NULL);
	ptr = *stack;
	while (ptr->next)
		ptr = ptr->next;
	return (ptr);
}

t_node	*ft_get_penult_node(t_node **stack, t_node **last_node)
{
	t_node	*ptr;

	ptr = *stack;
	while (ptr->next != *last_node)
		ptr = ptr->next;
	return (ptr);
}
