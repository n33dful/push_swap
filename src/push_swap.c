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

void	sortnums(int **arr, int size)
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

int *nums(t_stack *stack)
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
	sortnums(&arr, len);
	return (arr);
}

void		indexation(t_stack **stack, int *arr)
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

void		markup_head(t_stack **stack)
{
	int		index;
	t_stack	*a;

	a = (*stack);
	index = a->index;
	a->markup = 1;
	a = a->next;
	while (a)
	{
		if (a->index == index + 1)
		{
			index = a->index;
			a->markup = 1;
		}
		else
			a->markup = 0;
		a = a->next;
	}
}

int			check_false(t_stack *stack)
{
	t_stack *a;

	a = stack;
	while (a)
	{
		if (a->markup == 0)
			return (1);
		a = a->next;
	}
	return (0);
}

int			howmanykeep(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		if (stack->markup == 1)
			count++;
		stack = stack->next;
	}
	return (count);
}

int			swap_need(t_stack **stack)
{
	t_stack	*a;
	t_stack	*cpy;
	int		keep;

	a = (*stack);
	keep = howmanykeep(a);
	cpy = ft_stackcpy(a);
	swap(&cpy);
	markup_head(&cpy);
	if (howmanykeep(cpy) > keep)
	{
		delete_stack(&cpy);
		return (1);
	}
	delete_stack(&cpy);
	return (0);
}

int			find_min_turn(t_stack *stack)
{
	t_stack	*tmp;
	int		min;

	min = stack->turns;
	tmp = stack;
	if (tmp)
	{
		if (tmp->turns < min)
			min = tmp->turns;
		tmp = tmp->next;
	}
	return (min);
}

void		wedding(t_stack **a, t_stack **b)
{
	int	tmp;
	int len;
	int	i;

	i = 0;
	len = ft_stacklen((*a));
	while (*b)
	{
		if ((*b)->index < (*a)->index)
		{
			reverse_rotate(a);
			tmp = (*a)->index;
			rotate(a);
			if ((*b)->index > tmp)
			{
				push(b, a);
				ft_putstr("pa\n");
				len = ft_stacklen((*a));
			}
			else if (i == 0)
			{
				push(b, a);
				ft_putstr("pa\n");
				len = ft_stacklen((*a));
			}
			else
			{
				reverse_rotate(a);
				ft_putstr("rra\n");
				i--;
			}
		}
		else if (i + 1 == len)
		{
			rotate(a);
			push(b, a);
			ft_putstr("ra\npa\n");
			len = ft_stacklen((*a));
			i++;
		}
		else
		{
			reverse_rotate(a);
			tmp = (*a)->index;
			rotate(a);
			if ((*b)->index > (*a)->index)
			{
				rotate(a);
				ft_putstr("ra\n");
				i++;
			}
			else if (i - 1 != 0 && (*b)->index > tmp)
			{
				push(b, a);
				ft_putstr("pa\n");
				len = ft_stacklen((*a));
				i = len - 1;
			}
		}
		if (i == len)
			i = 0;
	}
	if (i > len / 2)
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

int			minind(t_stack *stack)
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

void		fix(t_stack **stack)
{
	int		ind;
	
	ind = minind((*stack));
	while ((*stack)->index != ind)
	{
		reverse_rotate(stack);
		ft_putstr("rra\n");	
	}
}

int			main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	if (argc < 2 || !(a = create_stack(argc, argv)))
	{
		ft_putstr("Error\n");
		exit(-1);
	}
	b = NULL;
	indexation(&a, nums(a));
	markup_head(&a);
	while (check_false(a))
	{
		if (swap_need(&a))
		{
			swap(&a);
			markup_head(&a);
			ft_putstr("sa\n");
		}
		else if (a->markup == 0)
		{
			push(&a, &b);
			ft_putstr("pb\n");
		}
		else
		{
			rotate(&a);
			ft_putstr("ra\n");
		}
	}
	fix(&a);
	wedding(&a, &b);
	delete_stack(&a);
	delete_stack(&b);
	return (0);
}
