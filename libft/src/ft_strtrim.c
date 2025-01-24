/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:46:26 by secros            #+#    #+#             */
/*   Updated: 2024/11/13 11:05:47 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(const char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static size_t	ft_tsize(const char *s, const char *set)
{
	size_t	size;
	size_t	i;

	i = 0;
	size = 0;
	while (is_set(s[i], set))
	{
		size++;
		i++;
	}
	if (!s[i])
		return (size);
	i = ft_strlen(s) - 1;
	while (is_set(s[i], set))
	{
		size++;
		i--;
	}
	return (size);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	i2;
	size_t	size;
	size_t	s_len;
	char	*fs;

	i = 0;
	i2 = 0;
	s_len = ft_strlen(s1);
	size = ft_tsize(s1, set);
	fs = (char *)malloc(sizeof(char) * (1 + s_len - size));
	if (!fs)
		return (NULL);
	while (is_set(s1[i], set))
		i++;
	while (i2 < s_len - size)
	{
		fs[i2++] = s1[i++];
	}
	fs[i2] = '\0';
	return (fs);
}
