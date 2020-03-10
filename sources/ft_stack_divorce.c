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

#include "push_swap.h"

static int	ft_swap_required(t_markup *markup, t_list **stack)
{
	int		saved;

	saved = markup->saved;
	ft_stack_swap(stack);
	ft_stack_markup_head(markup, stack);
	if (saved < markup->saved)
		return (1);
	ft_stack_swap(stack);
	ft_stack_markup_head(markup, stack);
	return (0);
}

static int	ft_check_notdeivorsed(t_list *stack)
{
	t_selem	*elem;

	while (stack)
	{
		elem = stack->content;
		if (elem->keep == 0)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int			ft_stack_divorce(t_list **stack_a, t_list **stack_b)
{
	t_markup	*markup;
	t_selem		*stack_elem;

	if (!(markup = ft_stack_markup(stack_a)))
		return (0);
	while (ft_check_notdeivorsed((*stack_a)))
	{
		stack_elem = (*stack_a)->content;
		if (ft_swap_required(markup, stack_a))
			ft_putendl("sa");
		else if (!stack_elem->keep)
			ft_stack_command(print_mode, "pb", stack_a, stack_b);
		else
			ft_stack_command(print_mode, "ra", stack_a, stack_b);
	}
	ft_memdel((void *)(&markup));
	return (1);
}
