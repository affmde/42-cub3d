NAME = libft.a
FLAGS = -Wall -Werror -Wextra
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
ft_strnstr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_strrchr.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_nbr_of_digits.c \
ft_power_of.c get_next_line.c ft_isspace.c ft_abs.c ft_min.c ft_max.c ft_strrev.c ft_isprime.c ft_strdel.c ft_memdel.c ft_words_count.c \
ft_letters_count.c
OBJECTS = $(SRCS:.c=.o)
PRINTF = ft_printf

BONUS_SRCS = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstlast_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c \
ft_lstiter_bonus.c ft_lstmap_bonus.c get_next_line_bonus.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
INC = ./my_libtf libft.h

all: $(NAME)

$(NAME) : $(SRCS)
	@make -C $(PRINTF)
	@cp ./$(PRINTF)/libftprintf.a $(NAME)
	@cc -c $(FLAGS) -I$(INC) $(SRCS)
	@ar -rcs $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS) $(BONUS_OBJS) ./ft_printf/*.o
fclean: clean
	rm -f $(NAME) ./$(PRINTF)/libftprintf.a

re: fclean all

bonus: $(BONUS_SRCS)
	cc -c $(FLAGS) -I$(INC) $(BONUS_SRCS)
	ar -rcs $(NAME) $(BONUS_OBJS)
