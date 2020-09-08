/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treeadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 19:07:24 by cdarci            #+#    #+#             */
/*   Updated: 2020/09/02 21:27:03 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_treeadd(t_tree **tree, t_tree *node, char (*f)(void *, void *))
{
	int	match_status;

	if (!(*tree))
		(*tree) = node;
	else
	{
		match_status = f(node->content, (*tree)->content);
		if ((*tree)->left && match_status <= 0)
			ft_treeadd(&((*tree)->left), node, f);
		else if ((*tree)->right && match_status > 0)
			ft_treeadd(&((*tree)->right), node, f);
		else if (!(*tree)->left && match_status <= 0)
			(*tree)->left = node;
		else
			(*tree)->right = node;
	}
}
