# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/18 14:54:27 by psantos-          #+#    #+#              #
#    Updated: 2025/07/09 19:39:24 by psantos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc 
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a

SRC = 	ft_atoi.c ft_strdup.c ft_strjoin.c ft_split.c gnl.c gnl_utils.c \
		ft_putendl_fd.c ft_atoi_base.c ft_toupper.c ft_strncmp.c

OBJ = $(SRC:.c=.o)

AR = ar rcs

.PHONY: all bonus fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
