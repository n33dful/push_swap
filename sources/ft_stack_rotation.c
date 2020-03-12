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

static int	ft_stack_push(int mode, t_data *data)
{
	t_list	**from;
	t_list	**to;
	t_list	*tmp;

	if (mode == push_to_stack_a)
		from = &(data->stack_b);
	else
		from = &(data->stack_a);
	to = (*from) == data->stack_a ? &(data->stack_b) : &(data->stack_a);
	if ((*from))
	{
		tmp = (*from);
		(*from) = (*from)->next;
		tmp->next = (*to);
		(*to) = tmp;
		if (mode == push_to_stack_a)
			data->stack_a_len++;
		else if (mode == push_to_stack_b)
			data->stack_b_len++;
		if (mode == push_to_stack_a && data->stack_a_len)
			data->stack_a_len--;
		else if (mode == push_to_stack_b && data->stack_b_len)
			data->stack_b_len--;
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

int			ft_stack_rotation(int mode, const char *cmd, t_data *data)
{
	int	status;

	status = 0;
	if (ft_strequ(cmd, "ss") || ft_strequ(cmd, "sa"))
		status = ft_stack_swap(&(data->stack_a));
	if (ft_strequ(cmd, "ss") || ft_strequ(cmd, "sb"))
		status = ft_stack_swap(&(data->stack_b));
	if (ft_strequ(cmd, "pa"))
		status = ft_stack_push(push_to_stack_a, data);
	if (ft_strequ(cmd, "pb"))
		status = ft_stack_push(push_to_stack_b, data);
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
