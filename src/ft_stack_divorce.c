/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_divorce.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:14:17 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/21 20:16:35 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_markup(t_stack **stack)
{
	size_t	index;
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

static int	ft_markup_count(t_stack *stack)
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

static int	ft_check_for_false(t_stack *stack)
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

static int	ft_is_swap_required(t_stack **stack)
{
	t_stack	*a;
	t_stack	*cpy;
	int		keep;

	a = (*stack);
	keep = ft_markup_count(a);
	cpy = ft_stack_dup(a);
	ft_stack_swap(&cpy);
	ft_markup(&cpy);
	if (ft_markup_count(cpy) > keep)
	{
		ft_stack_del(&cpy);
		return (1);
	}
	ft_stack_del(&cpy);
	return (0);
}

void		ft_stack_divorce(t_stack **a, t_stack **b)
{
	ft_markup(a);
	while (ft_check_for_false((*a)))
	{
		if (ft_is_swap_required(a))
		{
			ft_stack_swap(a);
			ft_markup(a);
			ft_putendl("sa");
		}
		else if ((*a)->markup == 0)
		{
			ft_stack_push(a, b);
			ft_putendl("pb");
		}
		else
		{
			ft_stack_rotate(a);
			ft_putendl("ra");
		}
	}
}
