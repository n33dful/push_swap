/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:16:20 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/16 20:22:35 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

static void	ft_indexation(t_stack **stack, int *arr);
static void	ft_sortnums(int **arr, int size);
static void	ft_showerror();
static int	*ft_arrofnums(t_stack *stack);

static void	what_to_do(char *comm, t_stack **a, t_stack **b);
static char	*ft_findcomm(t_stack *stack);
static void	mirror(char *commands, t_stack **a, t_stack **b);
static void	ft_finalrotate(t_stack **a);

int			main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	if (argc < 2 || !(a = ft_stacknew(argc, argv)))
		ft_showerror();
	b = NULL;
	ft_indexation(&a, ft_arrofnums(a));
	ft_divorce(&a, &b);
	while (b)
	{
		ft_countturns(&a, &b);
		ft_putstr(ft_findcomm(b));
		mirror(ft_findcomm(b), &a, &b);
		push(&b, &a);
		ft_putstr("pa\n");
	}
	//ft_wedding(&a, &b);
	ft_finalrotate(&a);
	ft_stackdel(&a);
	ft_stackdel(&b);
	return (0);
}

static char	*ft_findcomm(t_stack *stack)
{
	char	*res;
	int		min;

	res = NULL;
	if (stack)
	{
		min = stack->turns;
		res = stack->str;
		while (stack)
		{
			if (stack->turns != 0 && ((stack->turns < 0 ? -1 * stack->turns : stack->turns) < min))
			{
				min = stack->turns;
				res = stack->str;
			}
			stack = stack->next;
		}
	}
	return(res);
}

static void	ft_showerror()
{
	ft_putstr("Error\n");
	exit(-1);
}

static void	ft_sortnums(int **arr, int size)
{
	int	tmp;
	int	i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (j + 1 != size && (*arr)[j] > (*arr)[j + 1])
			{
				tmp = (*arr)[j];
				(*arr)[j] = (*arr)[j + 1];
				(*arr)[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	*ft_arrofnums(t_stack *stack)
{
	int	*arr;
	int	len;
	int	i;

	i = 0;
	len = ft_stacklen(stack);	
	if (!(arr = (int *)malloc(sizeof(int) * len)))
		exit(-1);
	while (i < len)
	{
		arr[i] = stack->num;
		stack = stack->next;
		i++;
	}
	ft_sortnums(&arr, len);
	return (arr);
}

static void	ft_indexation(t_stack **stack, int *arr)
{
	t_stack *a;
	int		i;

	a = (*stack);
	while (a)
	{
		i = 0;
		while (arr[i] != a->num)
			i++;
		a->index = i;
		a = a->next;
	}
	a = NULL;
	free(arr);
}

static void	mirror(char *commands, t_stack **a, t_stack **b)
{
	char	**comm;
	int		i;

	i = 0;
	comm = ft_strsplit(commands, '\n');
	while (comm[i])
	{
		what_to_do(comm[i], a, b);
		i++;
	}
	i = 0;
	while (comm[i])
		free(comm[i++]);
	free(comm);
}

static void	what_to_do(char *comm, t_stack **a, t_stack **b)
{
	if (ft_strcmp(comm, "sa") == 0)
	{
		swap(a);
	}
	else if (ft_strcmp(comm, "sb") == 0)
	{
		swap(b);
	}
	else if (ft_strcmp(comm, "ss") == 0)
	{
		swap(a);
		swap(b);
	}
	else if (ft_strcmp(comm, "ra") == 0)
	{
		rotate(a);
	}
	else if (ft_strcmp(comm, "rb") == 0)
	{
		rotate(b);
	}
	else if (ft_strcmp(comm, "rr") == 0)
	{
		rotate(a);
		rotate(b);
	}
	else if (ft_strcmp(comm, "rra") == 0)
	{
		reverse_rotate(a);
	}
	else if (ft_strcmp(comm, "rrb") == 0)
	{
		reverse_rotate(b);
	}
	else if (ft_strcmp(comm, "rrr") == 0)
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
}

static void	ft_finalrotate(t_stack **a)
{
	if ((*a)->index > ft_stacklen((*a)) / 2)
	{
		while ((*a)->index != 0)
		{
			rotate(a);
			ft_putstr("ra\n");
		}
	}
	else
	{
		while ((*a)->index != 0)
		{
			reverse_rotate(a);
			ft_putstr("rra\n");
		}
	}
}
