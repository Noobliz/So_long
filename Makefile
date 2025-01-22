NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = -Lmlx -lmlx -Lminilibx-linux -lXext -lX11
OBJ_DIR = obj
LIBFT = LIBFT/libft.a
MLX_LIB = minilibx-linux/libmlx_linux.a

SRCS = \
	main.c \
	valid_map.c \
	get_map.c \
	utils.c \
	valid_path.c \
	display_map.c \
	player_mov.c \
	window_utils.c \

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(LIBFT) $(MLX_LIB) $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX_LIB)
	@echo "Linking $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_FLAGS) -L./LIBFT -lft

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@echo "Compiling $(notdir $<)..."
	@$(CC) $(CFLAGS) -I. -I LIBFT/ -I minilibx-linux/ -o $@ -c $<

$(LIBFT):
	@echo "Building libft..."
	@$(MAKE) -C LIBFT

$(MLX_LIB):
	@echo "Building MiniLibX..."
	@$(MAKE) -C minilibx-linux

clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "Cleaning libraries and executable..."
	@$(MAKE) -C LIBFT fclean
	@$(MAKE) -C minilibx-linux clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

