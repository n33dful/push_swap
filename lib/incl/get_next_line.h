/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 12:18:56 by cdarci            #+#    #+#             */
/*   Updated: 2020/03/15 23:25:48 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*
** ----------------------------- External Headers ------------------------------
*/

# include "libft.h"
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>

/*
** ------------------------------ Buf Definition -------------------------------
*/

# define GNL_BUF_SIZE 42

/*
** -----------------------------------------------------------------------------
** ---------------------------------- Sources ----------------------------------
** -----------------------------------------------------------------------------
*/

int			get_next_line(const int fd, char **line);

#endif
