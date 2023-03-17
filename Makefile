NAME	= so_long
CFLAGS	= -Wall -Wextra -Werror -D BUFFER_SIZE=42 -g
LIBMLX	= /Users/${USER}/Desktop/MLX42
LIBFT	= libft
GNL_DIR = gnl
HEADERS = -I $(GNL_DIR) -I $(LIBMLX)/include -I $(LIBFT)
LIBS = -lglfw -L /Users/${USER}/.brew/opt/glfw/lib/ $(LIBMLX)/libmlx42.a $(LIBFT)/libft.a
SRCS	= 	src/map_checker.c \
			src/so_long.c \
			src/print_error.c \
			src/map_checker_utils.c \
			src/load_sprites.c \
			src/print_map.c \
			src/move_player.c \
			src/free_alloc.c \
			src/path_finding.c \
			$(GNL_SRCS)

GNL_SRCS = $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
OBJS	= $(SRCS:.c=.o)

all: libft libmlx $(NAME)

libft:	
	make -C $(LIBFT)

libmlx:	
	make -C $(LIBMLX)

%.o: %.c
	gcc $(CFLAGS) $(HEADERS) -c $< -o $@

$(NAME): $(OBJS)
	gcc $(CFLAGS) $(SRCS) $(LIBFT)/libft.a $(LIBMLX)/libmlx42.a $(HEADERS) $(LIBS) -o $(NAME)

clean:
	rm -rf $(OBJS)
	make clean -C $(LIBFT)
	make clean -C $(LIBMLX)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIBFT)/libft.a
	rm -rf $(LIBMLX)/libmlx42.a

re: fclean all

.PHONY: all clean fclean re libmlx libft
