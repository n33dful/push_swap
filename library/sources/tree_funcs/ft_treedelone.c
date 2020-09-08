/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treedelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 19:40:35 by cdarci            #+#    #+#             */
/*   Updated: 2020/08/30 17:26:24 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_treedelone(t_tree *node, void (*del)(void *))
{
	if (node)
	{
		if (del && node->content)
			del(node->content);
		ft_memdel((void*)(&node));
	}
}
