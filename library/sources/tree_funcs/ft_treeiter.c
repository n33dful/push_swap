/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treeiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 16:42:44 by cdarci            #+#    #+#             */
/*   Updated: 2020/08/30 17:08:47 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_treeiter(t_tree *tree, void (*f)(void *))
{
	if (tree)
	{
		if (tree->left)
			ft_treeiter(tree->left, f);
		if (f && tree->content)
			f(tree->content);
		if (tree->right)
			ft_treeiter(tree->right, f);
	}
}
