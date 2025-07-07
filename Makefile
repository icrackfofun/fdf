
NAME        := fdf
CC          := cc
CFLAGS      := -Wall -Wextra -Werror -Iinclude -Ilib -Iminilibx
MLXFLAGS    := -Lminilibx -lmlx -framework OpenGL -framework AppKit
LIBFT       := lib/libft.a
MLX         := minilibx/libmlx.a

SRC_DIR     := src
OBJ_DIR     := obj

SRCS        := $(wildcard $(SRC_DIR)/*.c)
OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLXFLAGS) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C lib

$(MLX):
	make -C minilibx

clean:
	make -C lib clean
	make -C minilibx clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C lib fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
