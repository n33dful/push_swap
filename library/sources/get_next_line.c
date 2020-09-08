/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 12:18:27 by cdarci            #+#    #+#             */
/*   Updated: 2020/09/08 21:31:32 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_getline(int const fd, char **readed)
{
	char	buffer[GNL_BUF_SIZE + 1];
	char	*tmp;
	int		ret;

	ft_memset(buffer, '\0', GNL_BUF_SIZE + 1);
	while ((ret = read(fd, buffer, GNL_BUF_SIZE)) > 0)
	{
		if (!(*readed))
			tmp = ft_strdup(buffer);
		else
			tmp = ft_strjoin((*readed), buffer);
		ft_strdel(readed);
		if (!tmp)
			return (-1);
		(*readed) = tmp;
		if (ft_strrchr(buffer, '\n'))
			break ;
	}
	return (ret);
}

static int	ft_pushline(char **line, char **readed)
{
	int	return_code;

	return_code = 0;
	if ((*readed) && (*readed)[0])
	{
		if (!((*line) = ft_strdup((*readed))))
			return_code = -1;
	}
	ft_strdel(readed);
	return (return_code);
}

int			get_next_line(int const fd, char **line)
{
	static char	*readed[0];
	int			status;
	char		*ptr;

	if ((status = ft_getline(fd, &readed[fd])) < 0)
		return (-1);
	ptr = NULL;
	if (readed[fd])
		ptr = ft_strchr(readed[fd], '\n');
	if (status == 0 && !ptr)
		return (ft_pushline(line, &readed[fd]));
	(*line) = ft_substr(readed[fd], 0, ptr - readed[fd]);
	ft_memmove(readed[fd], ptr + 1, ft_strlen(ptr + 1) + 1);
	return (1);
}
