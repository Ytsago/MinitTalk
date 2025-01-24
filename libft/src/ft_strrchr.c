/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:37:56 by secros            #+#    #+#             */
/*   Updated: 2024/11/07 14:55:34 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if (!*s)
	{
		if (!(char)c)
			return ((char *)s);
		return (0);
	}
	if ((char)c == *(s + i))
		return ((char *)(s + i));
	while (i--)
		if ((char)c == *(s + i))
			return ((char *)(s + i));
	return (0);
}
