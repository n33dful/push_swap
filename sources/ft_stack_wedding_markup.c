
#include "push_swap.h"

static void		ft_calculate_turns(t_selem *stack_elem, int (*compare)[4])
{
	int	r_current;
	int	rr_current;
	int	r_next;
	int	rr_next;

	r_current = stack_elem->rotates_to_top;
	rr_current = stack_elem->reverse_rotates_to_top;
	r_next = stack_elem->elem_after->rotates_to_top;
	rr_next = stack_elem->elem_after->reverse_rotates_to_top;
	if (r_current > r_next)
		(*compare)[up_and_up_mode] = r_current;
	else
		(*compare)[up_and_up_mode] = r_next;
	if (rr_current > rr_next)
		(*compare)[down_and_down_mode] = rr_current;
	else
		(*compare)[down_and_down_mode] = rr_next;
	(*compare)[up_and_down_mode] = rr_current + r_next;
	(*compare)[down_and_up_mode] = r_current + rr_next;
}

static t_selem	*ft_set_next(t_list *stack_sorted)
{
	while (!((t_selem *)stack_sorted->content)->in_stack_a)
		stack_sorted = stack_sorted->next;
	return (stack_sorted->content);
}

static int		ft_compare(int mode, int compare[4])
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (compare[mode] > compare[i])
			return (0);
		i++;
	}
	return (1);
}

static int		ft_find_best_mode(int compare[4])
{
	if (ft_compare(up_and_up_mode, compare))
		return (up_and_up_mode);
	else if (ft_compare(down_and_down_mode, compare))
		return (down_and_down_mode);
	else if (ft_compare(up_and_down_mode, compare))
		return (up_and_down_mode);
	else if (ft_compare(down_and_up_mode, compare))
		return (down_and_up_mode);
	else
		return (-1);
}

void			ft_stack_wedding_markup(t_data *data)
{
	int		best_mode;
	int		turns_compare[4];
	t_selem	*stack_elem;
	t_list	*stack;

	stack = data->stack_b;
	while (stack)
	{
		while (stack->content != data->sorted->content)
			data->sorted = data->sorted->next;
		stack_elem = stack->content;
		stack_elem->elem_after = ft_set_next(data->sorted);
		ft_calculate_turns(stack_elem, &turns_compare);
		best_mode = ft_find_best_mode(turns_compare);
		ft_stack_wedding_markup_elem(best_mode, turns_compare, stack_elem);
		stack = stack->next;
	}
}
