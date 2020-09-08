/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treeclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 16:19:25 by cdarci            #+#    #+#             */
/*   Updated: 2020/09/04 22:38:46 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_treeclear(t_tree **node, void (*del)(void *))
{
	if ((*node))
	{
		if ((*node)->left)
			ft_treeclear(&((*node)->left), del);
		if ((*node)->right)
			ft_treeclear(&((*node)->right), del);
		ft_treedelone((*node), del);
		(*node) = NULL;
	}
}
