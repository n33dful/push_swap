#include "../include/push_swap.h"

static char	*ft_create_an_instruction_to_insert_an_element(t_stack **a, t_stack **b);
static int	ft_find_a_place_to_insert_an_element(t_stack **a, t_stack **b, \
int tmp, char **commands);
static int	ft_find_minimum_index(t_stack *stack);
static int	ft_find_maximum_index(t_stack *stack);

char		*ft_stack_a_instructions(t_stack **stacka, t_stack **stackb)
{
	char	*comm;
	t_stack	*a;
	t_stack	*b;

	a = ft_stack_dup((*stacka));
	b = ft_stack_dup((*stackb));
	comm = ft_create_an_instruction_to_insert_an_element(&a, &b);
	ft_stack_del(&a);
	ft_stack_del(&b);
	return (comm);
}

static int	ft_find_maximum_index(t_stack *stack)
{
	int	ind;

	ind = stack->index;
	while (stack)
	{
		if (stack->index > ind)
			ind = stack->index;
		stack = stack->next;
	}
	return (ind);
}

static int	ft_find_minimum_index(t_stack *stack)
{
	int	ind;

	ind = stack->index;
	while (stack)
	{
		if (stack->index < ind)
			ind = stack->index;
		stack = stack->next;
	}
	return (ind);
}

static int	ft_find_a_place_to_insert_an_element(t_stack **a, t_stack **b, int tmp, char **commands)
{
	int	finish;

	finish = 0;
	if (((*b)->index < ft_stack_len((*a)) / 4 && (*a)->index > ft_stack_len((*a)) / 4) || \
(*b)->index - (*a)->index > 0)
	{
		ft_stack_rotate(a);
		(*commands) = ft_combine_instructions((*commands), "ra\n");
		if ((*a)->index > (*b)->index && (*b)->index > tmp)
			finish = 1;
	}
	else
	{
		ft_stack_reverse_rotate(a);
		if ((*a)->index < (*b)->index && (*b)->index < tmp)
			finish = 1;
		else
			(*commands) = ft_combine_instructions((*commands), "rra\n");
	}
	return (finish);
}

static char	*ft_create_an_instruction_to_insert_an_element(t_stack **a, t_stack **b)
{
	char	*commands;
	int		finish;
	int		tmp;

	finish = 0;
	commands = ft_strnew(0);
	while (!finish)
	{
		tmp = (*a)->index;
		if ((*a)->index == ft_find_minimum_index((*a)) && (*b)->index < (*a)->index)
			finish = 1;
		else if ((*a)->index == ft_find_maximum_index((*a)) && (*b)->index > (*a)->index)
		{
			ft_stack_rotate(a);
			commands = ft_combine_instructions(commands, "ra\n");
			finish = 1;
		}
		else
			finish = ft_find_a_place_to_insert_an_element(a, b, tmp, &commands);
	}
	return (commands);
}
