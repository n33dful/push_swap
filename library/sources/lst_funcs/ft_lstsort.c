/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:07:47 by cdarci            #+#    #+#             */
/*   Updated: 2020/09/02 21:28:05 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstswap(t_list *list)
{
	t_list	*pointer;

	pointer = list->next;
	list->next = pointer->next;
	pointer->next = list;
	return (pointer);
}

static t_list	*ft_sort(t_list *list, char (*f)(void *, void *))
{
	if (!list->next)
		return (list);
	if (f(list->content, list->next->content) > 0)
		list = ft_lstswap(list);
	list->next = ft_sort(list->next, f);
	return (list);
}

void			ft_lstsort(t_list **list, char (*f)(void *, void *))
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_lstsize((*list));
	while (i < len)
	{
		(*list) = ft_sort((*list), f);
		i++;
	}
}
