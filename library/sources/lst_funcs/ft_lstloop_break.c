/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstloop_break.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 23:30:06 by cdarci            #+#    #+#             */
/*   Updated: 2020/05/09 16:43:55 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstloop_break(t_list *lst)
{
	t_list	*pointer;

	if (lst)
	{
		pointer = lst;
		while (lst->next != pointer)
		{
			if (!lst->next)
				return ;
			lst = lst->next;
		}
		lst->next = NULL;
	}
}
