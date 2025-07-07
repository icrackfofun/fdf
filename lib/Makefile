# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/18 14:54:27 by psantos-          #+#    #+#              #
#    Updated: 2025/07/01 20:19:23 by psantos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc 
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a

SRC = 	ft_atoi.c ft_strdup.c ft_strjoin.c ft_split.c gnl.c gnl_utils.c \
		printf.c printf_conv.c printf_conv_aux.c

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
