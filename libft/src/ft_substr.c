/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:17:39 by secros            #+#    #+#             */
/*   Updated: 2024/11/08 14:39:57 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*subs;

	if (ft_strlen(s) > start)
		i = ft_strlen(&s[start]);
	else
		i = 0;
	if (i > len)
		i = len;
	subs = (char *) malloc(sizeof(char) * (i + 1));
	if (!subs)
		return (NULL);
	subs[i] = '\0';
	while (i--)
		subs[i] = s[start + i];
	return (subs);
}
