/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:53:43 by psantos-          #+#    #+#             */
/*   Updated: 2025/07/09 19:39:22 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdint.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

//libft
size_t			ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t			ft_strlen(const char *str);
void			*ft_memset(void *ptr, int value, size_t num);
long int		ft_atoi(const char *str);
char			**ft_split(char const *s, char c);
void			ft_putendl_fd(const char *s, int fd);
unsigned int	ft_atoi_base(const char *str, const char *base);
int				ft_toupper(int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);

//get_next_line
char			*get_next_line(int fd);
char			*ft_findnl(char *arr);
size_t			ft_linelen(const char *str);
size_t			ft_strlen(const char *str);
size_t			ft_strlcpy(char *dest, const char *src, size_t dstsize);
void			ft_buffercpy(char **ptr, char *arr);
void			ft_trimbuffer(char *arr);
char			*ft_valread(char **string, ssize_t bytes, char *arr);
char			*read_line(int fd, char **buffer);
void			*ft_memset(void *s, int c, size_t n);

#endif
