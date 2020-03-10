
#include "push_swap.h"

void	ft_stack_markup_head(t_markup *markup, t_list **stack)
{
	t_list	*first_elem;

	first_elem = (*stack);
	while ((*stack) != markup->markup_head)
		ft_stack_rotate(stack);
	ft_stack_markup_elem(markup->mode, (*stack));
	while ((*stack) != first_elem)
		ft_stack_rotate(stack);
	markup->saved = ft_stack_markup_amount((*stack));
}
