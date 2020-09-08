/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 19:51:28 by cdarci            #+#    #+#             */
/*   Updated: 2020/09/04 22:05:49 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	ft_push_to(char const mode, t_data *data)
{
	t_list	**from;
	t_list	**to;
	t_list	*tmp;

	from = (mode == A ? &(data->stack_b) : &(data->stack_a));
	to = (mode == B ? &(data->stack_b) : &(data->stack_a));
	if ((*from))
	{
		tmp = (*from);
		(*from) = (*from)->next;
		tmp->next = (*to);
		(*to) = tmp;
		data->stack_a_len += (mode == A ? 1 : -1);
		data->stack_b_len += (mode == B ? 1 : -1);
	}
	return (1);
}

static char	ft_swap(char const mode, t_data *data)
{
	t_list	**stack;
	t_list	*tmp;

	stack = (mode == A ? &(data->stack_a) : &(data->stack_b));
	if ((*stack) && (*stack)->next)
	{
		tmp = (*stack)->next;
		(*stack)->next = (*stack)->next->next;
		tmp->next = (*stack);
		(*stack) = tmp;
	}
	return (1);
}

static char	ft_rotate(char const mode, t_data *data)
{
	t_list	**stack;
	t_list	*tmp;
	size_t	ptr;

	tmp = NULL;
	stack = (mode == A ? &(data->stack_a) : &(data->stack_b));
	ptr = (size_t)(*stack);
	if ((*stack))
	{
		while ((*stack)->next)
			(*stack) = (*stack)->next;
		(*stack)->next = (t_list *)ptr;
		(*stack) = (*stack)->next;
		tmp = (*stack)->next;
		(*stack)->next = NULL;
		(*stack) = tmp;
	}
	return (1);
}

static char	ft_reverse_rotate(char const mode, t_data *data)
{
	t_list	**stack;
	t_list	*tmp;
	size_t	ptr;

	stack = (mode == A ? &(data->stack_a) : &(data->stack_b));
	ptr = (size_t)(*stack);
	if ((*stack))
	{
		while ((*stack)->next)
			(*stack) = (*stack)->next;
		(*stack)->next = (t_list *)ptr;
		ptr = (size_t)(*stack);
		while ((*stack)->next != (t_list *)(ptr))
			(*stack) = (*stack)->next;
		tmp = (*stack)->next;
		(*stack)->next = NULL;
		(*stack) = tmp;
	}
	return (1);
}

char		ft_stack_rotate(char const mode, char const *cmd, t_data *data)
{
	char	status;

	status = 0;
	if (ft_strequ(cmd, "ss") || ft_strequ(cmd, "sa"))
		status = ft_swap(A, data);
	if (ft_strequ(cmd, "ss") || ft_strequ(cmd, "sb"))
		status = ft_swap(B, data);
	if (ft_strequ(cmd, "pa"))
		status = ft_push_to(A, data);
	if (ft_strequ(cmd, "pb"))
		status = ft_push_to(B, data);
	if (ft_strequ(cmd, "rr") || ft_strequ(cmd, "ra"))
		status = ft_rotate(A, data);
	if (ft_strequ(cmd, "rr") || ft_strequ(cmd, "rb"))
		status = ft_rotate(B, data);
	if (ft_strequ(cmd, "rrr") || ft_strequ(cmd, "rra"))
		status = ft_reverse_rotate(A, data);
	if (ft_strequ(cmd, "rrr") || ft_strequ(cmd, "rrb"))
		status = ft_reverse_rotate(B, data);
	if (status && cmd && mode == LOUD)
		ft_putendl(cmd);
	return (status);
}
