/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:05:43 by secros            #+#    #+#             */
/*   Updated: 2024/11/07 17:08:34 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*cpy;

	size = ft_strlen(s);
	cpy = (char *) malloc(sizeof(char) * size + 1);
	if (!cpy)
		return (0);
	cpy[size] = '\0';
	while (size--)
		cpy[size] = s[size];
	return (cpy);
}
