/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstloop_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 23:30:10 by cdarci            #+#    #+#             */
/*   Updated: 2020/03/15 23:30:13 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstloop_create(t_list *lst)
{
	t_list	*pointer;

	if (lst)
	{
		pointer = lst;
		while (lst->next != NULL)
		{
			if (lst->next == pointer)
				return ;
			lst = lst->next;
		}
		lst->next = pointer;
	}
}
