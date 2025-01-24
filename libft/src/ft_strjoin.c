/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:36:35 by secros            #+#    #+#             */
/*   Updated: 2024/11/20 15:59:08 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fs;
	size_t	len1;
	size_t	len2;

	len1 = 0;
	len2 = 0;
	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;
	fs = (char *) malloc(sizeof(char) * (len1 + len2 + 1));
	if (!fs)
		return (NULL);
	fs[len1 + len2] = '\0';
	while ((len2--))
		fs[len1 + len2] = s2[len2];
	while (len1--)
		fs[len1] = s1[len1];
	return (fs);
}
