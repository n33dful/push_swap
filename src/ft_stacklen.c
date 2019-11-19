#include "../include/push_swap.h"

int	ft_stacklen(t_stack *stack)
{
	t_stack	*tmp;
	int		len;

	len = 0;
	tmp = stack;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	tmp = NULL;
	return (len);
}
