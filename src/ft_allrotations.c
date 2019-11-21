#include "../include/push_swap.h"

static char	*ft_rotationsforb(int count);
static char	*ft_commoptimize(char *comma, char *commb);
static int	ft_commcount(char *comm);

void		ft_countturns(t_stack **stacka, t_stack **stackb)
{
	int		len;
	int		i;
	t_stack *a;
	t_stack *b;

	i = 0;
	a = ft_stack_dup((*stacka));
	b = ft_stack_dup((*stackb));
	len = ft_stack_len(b);
	ft_stack_del(&a);
	ft_stack_del(&b);
	while (i < (len == 1 ? len : len / 2))
	{
		a = ft_stack_dup((*stacka));
		b = ft_stack_dup((*stackb));
		if ((*stackb)->str)
			ft_strdel(&((*stackb)->str));
		(*stackb)->str = ft_commoptimize(ft_stack_a_instructions(&a, &b), ft_rotationsforb(i));
		(*stackb)->turns = ft_commcount((*stackb)->str);
		ft_stack_rotate(stackb);
		ft_stack_del(&a);
		ft_stack_del(&b);
		i++;
	}
	if (len % 2 && len != 1)
	{
		if ((*stackb)->str)
			ft_strdel(&((*stackb)->str));
		(*stackb)->turns = 0;
	}
	while (i > 0)
	{
		ft_stack_reverse_rotate(stackb);
		i--;
	}
	i = -1;
	while (i >= -1 * (len / 2))
	{
		ft_stack_reverse_rotate(stackb);
		a = ft_stack_dup((*stacka));
		b = ft_stack_dup((*stackb));
		if ((*stackb)->str)
			ft_strdel(&((*stackb)->str));
		(*stackb)->str = ft_commoptimize(ft_stack_a_instructions(&a, &b), ft_rotationsforb(i));
		(*stackb)->turns = -1 * ft_commcount((*stackb)->str);
		ft_stack_del(&a);
		ft_stack_del(&b);
		i--;
	}
	while (i < -1)
	{
		ft_stack_rotate(stackb);
		i++;
	}
	ft_stack_del(&a);
	ft_stack_del(&b);
}

static char	*ft_rotationsforb(int count)
{
	char	*comm;
	int		i;

	i = 0;
	comm = ft_strnew(0);
	while (i < (count < 0 ? -1 * count : count))
	{
		comm = (count < 0 ? ft_combine_instructions(comm, "rrb\n") : \
ft_combine_instructions(comm, "rb\n"));
		i++;
	}
	return (comm);
}

static char	*ft_commoptimize(char *comma, char *commb)
{
	char	**arr_of_a;
	char	**arr_of_b;
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	arr_of_a = ft_strsplit(comma, '\n');
	arr_of_b = ft_strsplit(commb, '\n');
	res = ft_strnew(0);
	while (arr_of_a[i] || arr_of_b[j])
	{
		if (arr_of_a[i] && arr_of_b[j] && ft_strcmp(arr_of_a[i], "ra") == 0 && ft_strcmp(arr_of_b[j], "rb") == 0)
		{
			res = ft_combine_instructions(res, "rr\n");
			i++;
			j++;
		}
		else if (arr_of_a[i] && arr_of_b[j] && ft_strcmp(arr_of_a[i], "rra") == 0 && ft_strcmp(arr_of_b[j], "rrb") == 0)
		{
			res = ft_combine_instructions(res, "rrr\n");
			i++;
			j++;
		}
		else if (arr_of_a[i] || arr_of_b[j])
		{
			if (arr_of_a[i])
			{
				res = ft_combine_instructions(res, arr_of_a[i]);
				res = ft_combine_instructions(res, "\n");
				i++;
			}
			if (arr_of_b[j])
			{
				res = ft_combine_instructions(res, arr_of_b[j]);
				res = ft_combine_instructions(res, "\n");
				j++;
			}
		}
	}
	res = ft_combine_instructions(res, "pa\n");
	ft_delete_array(arr_of_a);
	ft_delete_array(arr_of_b);
	ft_strdel(&comma);
	ft_strdel(&commb);
	return (res);
}

static int	ft_commcount(char *comm)
{
	int	count;

	count = 0;
	while (*comm)
	{
		if (*comm == '\n')
			count++;
		comm++;
	}
	return (count);
}
