/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_markup.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 22:51:13 by cdarci            #+#    #+#             */
/*   Updated: 2020/09/08 20:26:27 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MARKUP_H
# define T_MARKUP_H

/*
** ***************************** External Includes *****************************
*/

# include "t_list.h"

/*
** *************************** Structure Definition ****************************
*/

typedef struct	s_markup
{
	char		mode;
	int			saved;
	t_list		*markup_head;
}				t_markup;

/*
** *****************************************************************************
*/

#endif
