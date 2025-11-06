NAME = cub3d

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

MLX_DIR = ./minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS = -lXext -lX11 -lm -lbsd

GNL_DIR = ./get_next_line
GNL = $(GNL_DIR)/gnl_lib.a

LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a

SRC_DIR = src

PARSE_DIR = $(SRC_DIR)/parse
PARSE_SRC = check_file.c parse_args.c check_map_wall.c parse_elements.c check_path.c read_file.c extract_map.c validate_map.c parse_free.c get_color.c
PARSE_LOC = $(addprefix $(PARSE_DIR)/, $(PARSE_SRC))

UTILS_DIR = $(SRC_DIR)/utils
UTILS_SRC = ft_is.c print_err.c
UTILS_LOC = $(addprefix $(UTILS_DIR)/, $(UTILS_SRC))

INIT_DIR = $(SRC_DIR)/init
INIT_SRC = init_data.c init_mlx.c init_render.c
INIT_LOC = $(addprefix $(INIT_DIR)/, $(INIT_SRC))

RENDER_DIR = $(SRC_DIR)/render
RENDER_SRC = draw.c
RENDER_LOC = $(addprefix $(RENDER_DIR)/, $(RENDER_SRC))

SRCS =	main.c \
		$(PARSE_LOC) \
		$(UTILS_LOC) \
		$(INIT_LOC) \
		$(RENDER_LOC)

INCLUDES = -Iincludes -I$(LIBFT_DIR) -I$(GNL_DIR) -I$(MLX_DIR)

OBJS_DIR = objs
OBJ = $(patsubst %.c, $(OBJS_DIR)/%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(GNL_DIR)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT_A) $(GNL) $(MLX_LIB) $(MLX_FLAGS)

$(OBJS_DIR)/%.o : %.c
	@mkdir	-p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make clean -C $(GNL_DIR)
	make clean -C $(LIBFT_DIR)
	rm -rf $(OBJS_DIR)

fclean: clean
	make fclean -C $(GNL_DIR)
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
