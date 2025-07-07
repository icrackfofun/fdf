/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:08:46 by psantos-          #+#    #+#             */
/*   Updated: 2025/07/07 21:54:00 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	add_len(int count, int *total_len)
{
	if (count < 0)
		return (-1);
	*total_len += count;
	return (*total_len);
}

int	ft_printarg(char c, va_list *args)
{
	if (c == '%')
		return (write(1, "%", 1));
	if (c == 'c')
		return (ft_putchar(va_arg(*args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(*args, char *)));
	if (c == 'p')
		return (ft_putptr(va_arg(*args, void *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	if (c == 'u')
		return (ft_putunbr(va_arg(*args, unsigned int)));
	if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(*args, unsigned int), c));
	return (-1);
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		total_len;
	int		count;
	int		i;

	if (!string)
		return (-1);
	total_len = 0;
	i = 0;
	va_start(args, string);
	while (string[i])
	{
		if (string[i] == '%')
			count = ft_printarg(string[++i], &args);
		else
			count = write(1, &string[i], 1);
		if (add_len(count, &total_len) < 0)
			return (-1);
		i++;
	}
	va_end(args);
	return (total_len);
}
