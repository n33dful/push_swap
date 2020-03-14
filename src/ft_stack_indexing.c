/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_indexing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:17:16 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/21 20:17:39 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*ft_lstpointercpy(t_list *elem)
{
	t_list	*pointer;

	if (!(pointer = ft_lstnew(NULL, 0)))
		return (NULL);
	pointer->content = elem->content;
	return (pointer);
}

static int		ft_numssort(t_list *first, t_list *second)
{
	t_selem	*first_elem;
	t_selem	*second_elem;

	first_elem = first->content;
	second_elem = second->content;
	if (first_elem->number > second_elem->number)
		return (1);
	return (0);
}

static void		ft_setindex(t_list *list)
{
	t_selem			*elem;
	static size_t	i;

	if (list)
	{
		elem = list->content;
		elem->index = i++;
	}
}

int				ft_stack_indexing(t_data *data)
{
	data->sorted = ft_lstmap(data->stack_a, ft_lstpointercpy);
	if (data->stack_a_len != ft_lstlen(data->sorted))
	{
		ft_lstdel(&data->sorted, ft_stack_elem_del);
		return (0);
	}
	ft_lstsort(&data->sorted, ft_numssort);
	ft_lstiter(data->sorted, ft_setindex);
	return (1);
}
