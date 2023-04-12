NAME = cub3D
FLAGS = -Wall -Werror -Wextra
LINFLAGS = -lmlx -lXext -lX11
MOSFLAGS = -lmlx -framework OpenGl -framework AppKit
LIBFT = libft.a
LSRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
ft_strnstr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_strrchr.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_nbr_of_digits.c \
ft_power_of.c get_next_line.c ft_isspace.c ft_abs.c ft_min.c ft_max.c ft_strrev.c ft_isprime.c ft_strdel.c ft_memdel.c ft_words_count.c \
ft_letters_count.c
LOBJECTS = $(LSRCS:.c=.o)
LFTBONUS_SRCS = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstlast_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c \
ft_lstiter_bonus.c ft_lstmap_bonus.c get_next_line_bonus.c
LFTBONUS_OBJS = $(LFTBONUS_SRCS:.c=.o)
LODEST = $(addprefix ./libft/, $(LOBJECTS) $(LFTBONUS_OBJS));
FILE_PARSING = file_read.c parse_elements.c parse_map.c
FILE_PARSING_DEST = $(addprefix file_parsing/, $(FILE_PARSING))
INIT = cub3d_init.c cam_init.c
INIT_DEST = $(addprefix init/, $(INIT))
UTILS = parse_utils.c texture_creator.c walls_creator.c map_validation_utils.c return_textures.c math_utils.c bresenham_algo.c \
colors.c graphics_utils.c
UTILS_DEST = $(addprefix utils/, $(UTILS))
FILE_VALIDATION = map_validity.c file_validity.c elements_validity.c map_closed.c fc_validity.c
FILE_VALIDATION_DEST = $(addprefix file_validation/, $(FILE_VALIDATION))
MLX_HANDLING = mlx_handling.c events.c
MLX_HANDLING_DEST = $(addprefix mlx_handling/, $(MLX_HANDLING))
RAYCASTING = raycast.c
RAYCASTING_DEST = $(addprefix raycasting/, $(RAYCASTING))
SRCS = handle_errors.c clean.c
SRCSDEST = $(addprefix ./srcs/, $(SRCS) $(FILE_PARSING_DEST) $(UTILS_DEST) $(INIT_DEST) $(FILE_VALIDATION_DEST) $(MLX_HANDLING_DEST) \
$(RAYCASTING_DEST))
all: $(NAME)

$(NAME): $(SRCSDEST) main.c draw_example.c
	@make -C libft
	@make bonus -C libft
	cc $(FLAGS) -o $(NAME) main.c draw_example.c $(SRCSDEST) -L. ./libft/$(LIBFT) $(MOSFLAGS)
#cc $(FLAGS) -o $(NAME) main.c draw_example.c $(SRCSDEST) -L. ./libft/$(LIBFT) $(LINFLAGS) -lm

clean:
	rm -f $(LODEST)

fclean:
	rm -f $(NAME) ./libft/$(LIBFT)

re: fclean all

$(LIBFT):
	make -C libft
