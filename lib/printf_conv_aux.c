/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 23:30:23 by psantos-          #+#    #+#             */
/*   Updated: 2025/05/11 13:12:34 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	return (write (1, &c, 1));
}

int	ft_numlen(uintptr_t n, size_t base)
{
	int	len;

	len = (n == 0);
	while (n > 0)
	{
		len++;
		n /= base;
	}
	return (len);
}

char	*ft_itoa_base(uintptr_t n, char *baseset)
{
	char		*number;
	size_t		len;
	int			base;

	base = ft_strlen(baseset);
	len = ft_numlen(n, base);
	number = malloc(len + 1);
	if (!number)
		return (NULL);
	number[len] = '\0';
	while (n > 0)
	{
		len--;
		number[len] = baseset[n % base];
		n /= base;
	}
	return (number);
}
