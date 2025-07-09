
NAME		=	fdf
LIBFT		=	lib/
MLX			=	minilibx/
LIBFT_A		=	$(addprefix $(LIBFT),libft.a)
MLX_A		=	$(addprefix $(MLX),libmlx.a)
OBJDIR		=	obj


CC			=	gcc
INCLUDE 	=	include
CFLAGS		=	-Wall -Wextra -Werror -Wno-unused-parameter -I$(INCLUDE) -I$(LIBFT) -I$(MLX)
RM			=	rm -f

SRCS		=	srcs/main.c \
				srcs/alg_utils.c \
				srcs/controls.c \
				srcs/draw.c \
				srcs/line_alg.c \
				srcs/parse_map.c \
				srcs/utils.c \
				srcs/utils_2.c

OBJS		=	$(patsubst srcs/%.c,$(OBJDIR)/%.o,$(SRCS))


all:			$(NAME)

$(NAME):		$(OBJS) $(LIBFT_A) $(MLX_A)
				@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT) -lft -L$(MLX) -lmlx -lm -o $(NAME) -framework OpenGL -framework AppKit

$(LIBFT_A):
				@$(MAKE) -s -C $(LIBFT)

$(MLX_A):
				@$(MAKE) -s -C $(MLX)

$(OBJDIR)/%.o: 	srcs/%.c | $(OBJDIR)
				@$(CC) $(CFLAGS) -c $< -o $@

clean:
				@$(RM) $(OBJDIR)/*.o
				@$(MAKE) clean -s -C $(LIBFT)
				@$(MAKE) clean -s -C $(MLX)


fclean:			clean
				@$(MAKE) fclean -s -C $(LIBFT)
				@$(MAKE) clean -s -C $(MLX)
				@$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
