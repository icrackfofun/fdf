
NAME	=	fdf
LIBFT	=	lib/
MLX		=	minilibx/
LIBFT_A	=	$(LIBFT)libft.a
MLX_A	=	$(MLX)libmlx.a
OBJDIR	=	obj

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -Iinclude -I$(LIBFT) -I$(MLX)
RM		=	rm -f

SRCS	=	srcs/main.c \
			srcs/alg_utils.c \
			srcs/controls.c \
			srcs/draw.c \
			srcs/line_alg.c \
			srcs/parse_map.c \
			srcs/utils.c \
			srcs/utils_2.c

OBJS	=	$(patsubst srcs/%.c,$(OBJDIR)/%.o,$(SRCS))

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS) $(LIBFT_A) $(MLX_A)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT) -lft -L$(MLX) -lmlx -lm -o $(NAME) -framework OpenGL -framework AppKit

$(LIBFT_A):
	$(MAKE) -C $(LIBFT)

$(MLX_A):
	$(MAKE) -C $(MLX)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: srcs/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJDIR)/*.o
	$(MAKE) clean -C $(LIBFT)
	$(MAKE) clean -C $(MLX)

fclean: clean
	$(MAKE) fclean -C $(LIBFT)
	$(MAKE) clean -C $(MLX)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

