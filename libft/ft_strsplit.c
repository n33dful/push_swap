/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 14:46:56 by cdarci            #+#    #+#             */
/*   Updated: 2019/09/07 16:44:02 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int ft_wordscount(char *s, char c)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		if (*s != c && *s != '\0')
		{
			while (*s != c && *s != '\0')
				s++;
			count++;
		}
		else
			s++;
	}
	return (count);
}

static int	ft_wordlen(char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	return (len);
}

static char	*ft_copyandmove(char **str, int len)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc(sizeof(char) * (len + 1));
	while (i < len)
		new[i++] = *((*str)++);
	new[i] = '\0';
	return (new);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	arr = NULL;
	if (str)
	{
		arr = (char **)malloc(sizeof(char *) * (ft_wordscount(str, c) + 1));
		while ((*str) != '\0')
		{
			if ((*str) == c && (*str) != '\0')
				str++;
			else
			{
				arr[i] = ft_copyandmove(&str, ft_wordlen(str, c));
				i++;
			}
		}
		str = NULL;
		arr[i] = NULL;
	}
	return (arr);
}
