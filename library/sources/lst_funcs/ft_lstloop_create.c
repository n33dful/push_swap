/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstloop_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 23:30:10 by cdarci            #+#    #+#             */
/*   Updated: 2020/05/09 16:44:02 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstloop_create(t_list *lst)
{
	t_list	*pointer;

	if (lst)
	{
		pointer = lst;
		while (lst->next)
		{
			if (lst->next == pointer)
				return ;
			lst = lst->next;
		}
		lst->next = pointer;
	}
}
