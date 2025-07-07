/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:53:48 by psantos-          #+#    #+#             */
/*   Updated: 2025/05/11 13:15:04 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

int	ft_putptr(void *ptr)
{
	char	*number;
	int		count;
	int		total_len;

	if (!ptr)
		return (ft_putstr("(nil)"));
	total_len = 0;
	number = ft_itoa_base((uintptr_t)ptr, "0123456789abcdef");
	if (!number)
		return (-1);
	count = write(1, "0x", 2);
	if (add_len(count, &total_len) < 0)
		return (-1);
	count = ft_putstr(number);
	free(number);
	number = NULL;
	return (add_len(count, &total_len));
}

int	ft_putnbr(int n)
{
	char		*number;
	long int	nb;
	int			total_len;
	int			count;

	nb = n;
	total_len = 0;
	if (nb == 0)
		return (ft_putchar('0'));
	if (nb < 0)
	{
		count = ft_putchar('-');
		if (add_len(count, &total_len) < 0)
			return (-1);
		nb *= -1;
	}
	number = ft_itoa_base((uintptr_t)nb, "0123456789");
	if (!number)
		return (-1);
	count = ft_putstr(number);
	free (number);
	number = NULL;
	return (add_len(count, &total_len));
}

int	ft_putunbr(unsigned int n)
{
	char	*number;
	int		count;

	if (n == 0)
		return (ft_putchar('0'));
	number = ft_itoa_base((uintptr_t)n, "0123456789");
	if (!number)
		return (-1);
	count = ft_putstr(number);
	free(number);
	number = NULL;
	return (count);
}

int	ft_puthex(unsigned int n, char c)
{
	char	*number;
	int		count;

	if (n == 0)
		return (ft_putchar('0'));
	if (c == 'x')
		number = ft_itoa_base((uintptr_t)n, "0123456789abcdef");
	if (c == 'X')
		number = ft_itoa_base((uintptr_t)n, "0123456789ABCDEF");
	count = ft_putstr(number);
	free(number);
	number = NULL;
	return (count);
}
