/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:16:13 by secros            #+#    #+#             */
/*   Updated: 2024/12/17 11:21:43 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	countsplit(const char *s, char c)
{
	size_t	i;
	size_t	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if ((i == 0 || s[i - 1] == c) && s[i] != c)
			word++;
		i++;
	}
	return (word);
}

static size_t	to_next_c(const char *s, char c, size_t index)
{
	size_t	i;

	i = 0;
	while (s[index] != c && s[index])
	{
		i++;
		index++;
	}
	return (i);
}

void	free_the_mallocs(char **pt)
{
	size_t	i;

	i = 0;
	if (!pt)
		return ;
	while (pt[i])
		free(pt[i++]);
	free(pt);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	i2;
	char	**fs;

	i = 0;
	i2 = 0;
	fs = (char **) ft_calloc(sizeof(char *), (countsplit(s, c) + 1));
	if (!fs)
		return (NULL);
	while (s[i])
	{
		if ((i == 0 || s[i - 1] == c) && s[i] != c)
		{
			fs[i2] = ft_substr(s, i, to_next_c(s, c, i));
			if (!fs[i2])
			{
				free_the_mallocs(fs);
				return (NULL);
			}
			i2++;
		}
		i++;
	}
	return (fs);
}
