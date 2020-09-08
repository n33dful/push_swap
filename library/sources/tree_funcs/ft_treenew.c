/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treenew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 16:16:12 by cdarci            #+#    #+#             */
/*   Updated: 2020/08/30 17:11:50 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tree	*ft_treenew(void *content)
{
	t_tree	*node;

	if (!(node = (t_tree*)ft_memalloc(sizeof(t_tree))))
		return (NULL);
	node->content = content;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
