/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:31:56 by cdarci            #+#    #+#             */
/*   Updated: 2019/09/12 15:29:42 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;
	void	*cont;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content != NULL)
	{
		cont = ft_memalloc(content_size);
		ft_memcpy(cont, content, content_size);
		list->content = cont;
		list->content_size = content_size;
	}
	else
	{
		list->content = NULL;
		list->content_size = 0;
	}
	list->next = NULL;
	return (list);
}
