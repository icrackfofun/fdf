/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 20:19:03 by psantos-          #+#    #+#             */
/*   Updated: 2025/07/01 20:39:48 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char		*dest;
	size_t		i;

	i = 0;
	dest = (char *)malloc(ft_strlen(s) + 1);
	if (dest == NULL)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		dest[i] = s[i];
		i++;
	}
	return (dest);
}

/*int main(void)
{
	char *s = "libft is fun";
	char *copy = ft_strdup(s);
	printf("Original: %s\nCopy:     %s\n", s, copy);
	free(copy);
}*/