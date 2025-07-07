/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:22:34 by psantos-          #+#    #+#             */
/*   Updated: 2025/04/30 14:53:28 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_valread(char **string, ssize_t bytes, char *arr)
{
	if (bytes < (ssize_t)0)
	{
		*arr = '\0';
		free(*string);
		*string = NULL;
		return (NULL);
	}
	if (*string)
		return (*string);
	return (NULL);
}

char	*ft_findnl(char *arr)
{
	size_t		i;

	i = 0;
	while (arr[i])
	{
		if (arr[i] == '\n')
		{
			return (&arr[i]);
		}
		i++;
	}
	return (NULL);
}

void	ft_buffercpy(char **ptr, char *arr)
{
	char	*temp;
	size_t	len_ptr;
	size_t	len_arr;

	len_arr = ft_linelen(arr);
	len_ptr = 0;
	if (*ptr)
		len_ptr = ft_strlen(*ptr);
	temp = *ptr;
	*ptr = malloc(len_ptr + len_arr + 1);
	if (!*ptr)
	{
		free(temp);
		*ptr = NULL;
		return ;
	}
	if (temp)
	{
		ft_strlcpy(*ptr, temp, len_ptr + 1);
		free(temp);
		temp = NULL;
	}
	ft_strlcpy(*ptr + len_ptr, arr, len_arr + 1);
}

void	ft_trimbuffer(char *arr)
{
	int	i;

	i = 0;
	while (arr[i] && arr[i] != '\n')
		i++;
	if (arr[i] == '\n')
		i++;
	ft_strlcpy(arr, arr + i, ft_strlen(arr + i) + 1);
}
