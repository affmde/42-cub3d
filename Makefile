NAME = cub3D
FLAGS = -Wall -Werror -Wextra
LIBFT = libft.a
LSRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
ft_strnstr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_strrchr.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_nbr_of_digits.c \
ft_power_of.c get_next_line.c ft_isspace.c ft_abs.c ft_min.c ft_max.c ft_strrev.c ft_isprime.c ft_strdel.c ft_memdel.c ft_words_count.c \
ft_letters_count.c
LOBJECTS = $(LSRCS:.c=.o)
LODEST = $(addprefix ./libft/, $(LOBJECTS))
FILE_PARSING = file_read.c
FILE_PARSING_DEST = $(addprefix file_parsing/, $(FILE_PARSING))
INIT = cub3d_init.c
INIT_DEST = $(addprefix init/, $(INIT))
SRCS = handle_errors.c clean.c
SRCSDEST = $(addprefix ./srcs/, $(SRCS) $(FILE_PARSING_DEST) $(INIT_DEST))
all: $(NAME)

$(NAME): $(SRCSDEST) main.c
	@make -C libft
	cc $(FLAGS) -o $(NAME) main.c $(SRCSDEST) -L. ./libft/$(LIBFT)

clean:
	rm -f $(LODEST)

fclean:
	rm -f $(NAME) ./libft/$(LIBFT)

re: fclean all

$(LIBFT):
	make -C libft
