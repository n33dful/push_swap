/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 14:46:56 by cdarci            #+#    #+#             */
/*   Updated: 2020/08/28 20:59:37 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_length(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	return (len);
}

static size_t	ft_words_count(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while(s[i] == c)
			i++;
		i += ft_word_length(&(s[i]), c);
		count++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;
	size_t	word_number;
	size_t	word_length;
	size_t	i;

	i = 0;
	word_number = 0;
	if (!s || !(arr = (char **)ft_arrnew(ft_words_count(s, c))))
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			word_length = ft_word_length(&(s[i]), c);
			if (!(arr[word_number++] = ft_substr(s, i, word_length)))
			{
				ft_arrdel((void*)(&arr));
				return (NULL);
			}
			i += word_length;
		}
		else
			i++;
	}
	return (arr);
}
