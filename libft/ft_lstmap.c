/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:29:49 by cdarci            #+#    #+#             */
/*   Updated: 2019/09/12 15:29:29 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	new = NULL;
	if (lst && f)
	{
		if (!(new = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
		new = f(lst);
		new->next = ft_lstmap(lst->next, f);
	}
	return (new);
}
