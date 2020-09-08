/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 11:49:37 by cdarci            #+#    #+#             */
/*   Updated: 2020/09/08 20:29:52 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASIC_H
# define BASIC_H

/*
** ***************************** External Includes *****************************
*/

# include "libft.h"

/*
** **************************** Structure Includes *****************************
*/

# include "t_data.h"
# include "t_elem.h"
# include "t_markup.h"
# include "t_wedding.h"

/*
** ******************************* Enum Includes *******************************
*/

# include "e_markup.h"
# include "e_rotate.h"
# include "e_stack.h"
# include "e_turn.h"
# include "e_wedding.h"

/*
** **************************** Colors Definitions *****************************
*/

# define GREEN "\033[32m"
# define RED "\033[1;31m"
# define YELLOW "\033[1;33m"

/*
** ********************** Functions For Working With Data **********************
*/

void	ft_data_struct_del(t_data *data);
void	ft_data_struct_init(t_data *data);

/*
** ********************* Functions For Working With Stack **********************
*/

char	ft_stack_new(int argc, char **argv, t_data *data);
char	ft_stack_rotate(char const mode,  char const *cmd, t_data *data);

/*
** *****************************************************************************
*/

#endif
