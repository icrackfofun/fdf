/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 23:05:01 by psantos-          #+#    #+#             */
/*   Updated: 2025/07/01 20:33:21 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*c;
	size_t	total_size;

	total_size = nmemb * size;
	if (size && (total_size / size != nmemb))
		return (NULL);
	c = (void *)malloc(total_size);
	if (!c)
		return (NULL);
	ft_memset(c, 0, total_size);
	return (c);
}

void	*ft_memset(void *ptr, int value, size_t num)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)ptr;
	i = 0;
	while (i < num)
	{
		p[i] = value;
		i++;
	}
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	str = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
	if (!str)
		return (NULL);
	ft_strlcpy((char *)str, s1, ft_strlen(s1) + 1);
	ft_strlcpy((char *)&str[ft_strlen(s1)], s2, ft_strlen(s2) + 1);
	return (str);
}
