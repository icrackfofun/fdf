/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 19:20:26 by psantos-          #+#    #+#             */
/*   Updated: 2025/07/01 20:35:35 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

long int	ft_atoi(const char *str)
{
	int			sign_counter;
	long int	number;

	sign_counter = 0;
	number = 0;
	while ((*str == 32 || (*str >= 9 && *str <= 13)) && *str)
	{
		str++;
	}
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign_counter++;
		str++;
	}
	while ((*str >= '0' && *str <= '9') && *str)
	{
		number = (number * 10) + (*str - '0');
		str++;
	}
	if (sign_counter == 1)
		return (-number);
	return (number);
}

/*int main(void)
{
    printf("Test 1: \"%s\" => %d\n", "42", ft_atoi("42"));
    printf("Test 2: \"%s\" => %d\n", "   -42", ft_atoi("   -42"));
    printf("Test 3: \"%s\" => %d\n", "   +123abc", ft_atoi("   +123abc"));
    printf("Test 4: \"%s\" => %d\n", "   
	\t\n\r\v\f56", ft_atoi("   \t\n\r\v\f56"));
    printf("Test 5: \"%s\" => %d\n", "abc123", ft_atoi("abc123"));
    printf("Test 6: \"%s\" => %d\n", "", ft_atoi(""));
    printf("Test 7: \"%s\" => %d\n", "+0", ft_atoi("+0"));
    printf("Test 8: \"%s\" => %d\n", "-2147483648", 
	ft_atoi("-2147483648")); // min int
    printf("Test 9: \"%s\" => %d\n", "2147483647", 
	ft_atoi("2147483647"));   // max int

    return 0;
}*/