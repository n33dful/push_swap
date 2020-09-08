/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_markup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 23:32:57 by cdarci            #+#    #+#             */
/*   Updated: 2020/09/04 22:31:57 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_update(t_markup *chosen, t_list *stack)
{
	int		saved;
	t_elem	*markup_head;
	t_elem	*elem;

	saved = ft_stack_markup_amount(stack);
	if (saved >= chosen->saved)
	{
		elem = stack->content;
		if (chosen->markup_head && saved == chosen->saved)
		{
			markup_head = chosen->markup_head->content;
			if (markup_head->index > elem->index)
				chosen->markup_head = stack;
		}
		else
		{
			chosen->markup_head = stack;
			chosen->saved = saved;
		}
	}
}

static t_markup	*ft_markup_init()
{
	t_markup	*markup;

	if (!(markup = (t_markup *)ft_memalloc(sizeof(t_markup))))
		return (NULL);
	markup->markup_head = NULL;
	markup->mode = 0;
	markup->saved = 0;
	return (markup);
}

static t_markup	*ft_find_markup_head(int mode, t_data *data)
{
	t_markup	*chosen;
	size_t		stack_len;
	size_t		i;

	if (!(chosen = ft_markup_init()))
		return (NULL);
	i = 0;
	chosen->mode = mode;
	stack_len = data->stack_a_len;
	while (i++ < stack_len)
	{
		ft_stack_markup_elem(chosen->mode, data->stack_a);
		ft_update(chosen, data->stack_a);
		ft_stack_rotate(SILENT, "ra", data);
	}
	return (chosen);
}

int				ft_stack_markup(t_data *data)
{
	int		best_head[2];
	t_elem	*by_index;
	t_elem	*by_number;

	if (!(data->by_index = ft_find_markup_head(BY_INDEX, data)))
		return (0);
	if (!(data->by_number = ft_find_markup_head(BY_NUMBER, data)))
		return (0);
	by_index = data->by_index->markup_head->content;
	by_number = data->by_number->markup_head->content;
	best_head[BY_INDEX] = by_index->index;
	best_head[BY_NUMBER] = by_number->index;
	if (data->by_index->saved < data->by_number->saved)
		data->chosen = data->by_number;
	else if (data->by_index->saved > data->by_number->saved)
		data->chosen = data->by_index;
	else if (best_head[BY_INDEX] <= best_head[BY_NUMBER])
		data->chosen = data->by_index;
	else
		data->chosen = data->by_number;
	ft_stack_markup_head(data);
	return (1);
}
