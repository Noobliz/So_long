NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = -Lmlx -lmlx -Lminilibx-linux -lXext -lX11
OBJ_DIR = obj
LIBFT = LIBFT/libft.a
INCLUDES = minilibx-linux/libmlx_linux.a

SRCS = \
	main_test.c \
	valid_map.c \
	get_map.c \
	utils.c \
	valid_path.c \
	display_map.c \
	handle_window.c \

OBJS = \
	$(OBJ_DIR)/main_test.o \
	$(OBJ_DIR)/valid_map.o \
	$(OBJ_DIR)/get_map.o \
	$(OBJ_DIR)/utils.o \
	$(OBJ_DIR)/valid_path.o \
	$(OBJ_DIR)/display_map.o \
	$(OBJ_DIR)/handle_window.o \

all: $(LIBFT) $(INCLUDES) $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(INCLUDES)
	@echo "Linking $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_FLAGS) -L./LIBFT -lft

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@echo "Compiling $(notdir $<)..."
	@$(CC) $(CFLAGS) -I. -I LIBFT/ -I minilibx-linux/ -o $@ -c $<

$(LIBFT):
	@echo "Building libft..."
	@$(MAKE) -C LIBFT

$(INCLUDES):
	@echo "Building Mlx..."
	@$(MAKE) -C minilibx-linux

clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJ_DIR)

lclean:
	@echo "Cleaning libraries..."
	@$(MAKE) -C LIBFT fclean -C minilibx-linux fclean

fclean: clean lclean
	@echo "Cleaning executable $(NAME)..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean lclean re
