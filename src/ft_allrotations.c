#include "../include/push_swap.h"

static char	*ft_rotationsforb(/*t_stack **b, */int count);
static char	*ft_unitcommands(char *comm1, char *comm2);
static void	ft_arrdel(char **arr);
static char	*ft_commoptimize(char *comma, char *commb);
static int	ft_commcount(char *comm);

void		ft_countturns(t_stack **stacka, t_stack **stackb)
{
	int		len;
	int		i;
	t_stack *a;
	t_stack *b;

	i = 0;
	a = ft_stackcpy((*stacka));
	b = ft_stackcpy((*stackb));
	len = ft_stacklen(b);
	ft_stackdel(&a);
	ft_stackdel(&b);
	while (i < (len == 1 ? len : len / 2))
	{
		a = ft_stackcpy((*stacka));
		b = ft_stackcpy((*stackb));
		if ((*stackb)->str)
			ft_strdel(&((*stackb)->str));
		(*stackb)->str = ft_commoptimize(ft_rotationsfora(&a, &b), ft_rotationsforb(/*&b, */i));
		(*stackb)->turns = ft_commcount((*stackb)->str);
		rotate(stackb);
		ft_stackdel(&a);
		ft_stackdel(&b);
		i++;
	}
	while (i > 0)
	{
		reverse_rotate(stackb);
		i--;
	}
	i = -1;
	while (i >= -1 * (len / 2))
	{
		reverse_rotate(stackb);
		a = ft_stackcpy((*stacka));
		b = ft_stackcpy((*stackb));
		if ((*stackb)->str)
			ft_strdel(&((*stackb)->str));
		(*stackb)->str = ft_commoptimize(ft_rotationsfora(&a, &b), ft_rotationsforb(/*&b, */i));
		(*stackb)->turns = -1 * ft_commcount((*stackb)->str);
		ft_stackdel(&a);
		ft_stackdel(&b);
		i--;
	}
	while (i < -1)
	{
		rotate(stackb);
		i++;
	}
	ft_stackdel(&a);
	ft_stackdel(&b);
}

static char	*ft_rotationsforb(/*t_stack **b, */int count)
{
	char	*comm;
	int		i;

	i = 0;
	comm = ft_strnew(0);
	while (i < (count < 0 ? -1 * count : count))
	{
		//(count < 0 ? reverse_rotate(b) : rotate(b));
		comm = (count < 0 ? ft_unitcommands(comm, "rrb\n") : \
ft_unitcommands(comm, "rb\n"));
		i++;
	}
	return (comm);
}

static char	*ft_unitcommands(char *comm1, char *comm2)
{
	char	*res;

	res = ft_strjoin(comm1, comm2);
	ft_strdel(&comm1);
	return (res);
}

static void	ft_arrdel(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		ft_strdel(&arr[i++]);
	free(arr);
	arr = NULL;
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
			res = ft_unitcommands(res, "rr\n");
			i++;
			j++;
		}
		else if (arr_of_a[i] && arr_of_b[j] && ft_strcmp(arr_of_a[i], "rra") == 0 && ft_strcmp(arr_of_b[j], "rrb") == 0)
		{
			res = ft_unitcommands(res, "rrr\n");
			i++;
			j++;
		}
		else if (arr_of_a[i] || arr_of_b[j])
		{
			if (arr_of_a[i])
			{
				res = ft_unitcommands(res, arr_of_a[i]);
				res = ft_unitcommands(res, "\n");
				i++;
			}
			if (arr_of_b[j])
			{
				res = ft_unitcommands(res, arr_of_b[j]);
				res = ft_unitcommands(res, "\n");
				j++;
			}
		}
	}
	ft_arrdel(arr_of_a);
	ft_arrdel(arr_of_b);
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
