#include "../include/push_swap.h"

static char	*ft_commands(t_stack **a, t_stack **b);
static char	*ft_unitcommands(char *comm1, char *comm2);
static int	ft_findminind(t_stack *stack);
static int	ft_findmaxind(t_stack *stack);

char		*ft_rotationsfora(t_stack **stacka, t_stack **stackb)
{
	char	*comm;
	t_stack	*a;
	t_stack	*b;

	a = ft_stackcpy((*stacka));
	b = ft_stackcpy((*stackb));
	comm = ft_commands(&a, &b);
	ft_stackdel(&a);
	ft_stackdel(&b);
	return (comm);
}

static int	ft_findmaxind(t_stack *stack)
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

static int	ft_findminind(t_stack *stack)
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

static char	*ft_unitcommands(char *comm1, char *comm2)
{
	char	*res;

	res = ft_strjoin(comm1, comm2);
	ft_strdel(&comm1);
	return (res);
}

static char	*ft_commands(t_stack **a, t_stack **b)
{
	char	*commands;
	int		finish;
	int		tmp;

	finish = 0;
	commands = ft_strnew(0);
	while (!finish)
	{
		tmp = (*a)->index;
		if ((*a)->index == ft_findminind((*a)) && (*b)->index < (*a)->index)
			finish = 1;
		else if ((*a)->index == ft_findmaxind((*a)) && (*b)->index > (*a)->index)
		{
			rotate(a);
			commands = ft_unitcommands(commands, "ra\n");
			finish = 1;
		}
		else if (((*b)->index < ft_stacklen((*a)) / 4 && (*a)->index > ft_stacklen((*a)) / 4) || (*b)->index - (*a)->index > 0)
		{
			rotate(a);
			commands = ft_unitcommands(commands, "ra\n");
			if ((*a)->index > (*b)->index && (*b)->index > tmp)
				finish = 1;
		}
		else
		{
			reverse_rotate(a);
			if ((*a)->index < (*b)->index && (*b)->index < tmp)
				finish = 1;
			else
				commands = ft_unitcommands(commands, "rra\n");
		}
	}
	return (commands);
}
