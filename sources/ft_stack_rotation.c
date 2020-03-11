/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 19:51:28 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/10 19:12:08 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_stack_push(t_list **stack_from, t_list **stack_to)
{
	t_list	*tmp;

	if ((*stack_from))
	{
		tmp = (*stack_from);
		(*stack_from) = (*stack_from)->next;
		tmp->next = (*stack_to);
		(*stack_to) = tmp;
	}
	return (1);
}

static int	ft_stack_swap(t_list **stack)
{
	t_list *tmp;

	if ((*stack) && (*stack)->next)
	{
		tmp = (*stack)->next;
		(*stack)->next = (*stack)->next->next;
		tmp->next = (*stack);
		(*stack) = tmp;
	}
	return (1);
}

static int	ft_stack_rotate(t_list **stack)
{
	t_list	*tmp;
	size_t	adr;

	tmp = NULL;
	adr = (size_t)(*stack);
	if ((*stack))
	{
		while ((*stack)->next)
			(*stack) = (*stack)->next;
		(*stack)->next = (t_list *)adr;
		(*stack) = (*stack)->next;
		tmp = (*stack)->next;
		(*stack)->next = NULL;
		(*stack) = tmp;
	}
	return (1);
}

static int	ft_stack_reverse_rotate(t_list **stack)
{
	t_list	*tmp;
	size_t	adr;

	adr = (size_t)(*stack);
	if ((*stack))
	{
		while ((*stack)->next)
			(*stack) = (*stack)->next;
		(*stack)->next = (t_list *)adr;
		adr = (size_t)(*stack);
		while ((*stack)->next != (t_list *)(adr))
			(*stack) = (*stack)->next;
		tmp = (*stack)->next;
		(*stack)->next = NULL;
		(*stack) = tmp;
	}
	return (1);
}

int			ft_stack_command(int mode, const char *cmd, t_data *data)
{
	int	status;

	status = 0;
	if (ft_strequ(cmd, "ss") || ft_strequ(cmd, "sa"))
		status = ft_stack_swap(&(data->stack_a));
	if (ft_strequ(cmd, "ss") || ft_strequ(cmd, "sb"))
		status = ft_stack_swap(&(data->stack_b));
	if (ft_strequ(cmd, "pa"))
		status = ft_stack_push(&(data->stack_b), &(data->stack_a));
	if (ft_strequ(cmd, "pb"))
		status = ft_stack_push(&(data->stack_a), &(data->stack_b));
	if (ft_strequ(cmd, "rr") || ft_strequ(cmd, "ra"))
		status = ft_stack_rotate(&(data->stack_a));
	if (ft_strequ(cmd, "rr") || ft_strequ(cmd, "rb"))
		status = ft_stack_rotate(&(data->stack_b));
	if (ft_strequ(cmd, "rrr") || ft_strequ(cmd, "rra"))
		status = ft_stack_reverse_rotate(&(data->stack_a));
	if (ft_strequ(cmd, "rrr") || ft_strequ(cmd, "rrb"))
		status = ft_stack_reverse_rotate(&(data->stack_b));
	if (status && mode == with_print)
		ft_putendl(cmd);
	return (status);
}
