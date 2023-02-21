NAME = libftprintf.a
SRCS = ft_printf.c handle_d.c handle_c.c handle_s.c handle_p.c handle_x.c handle_u.c power_of.c int_to_hex.c
SRCSDEST = $(addprefix ./srcs/, $(SRCS))
OBJS = $(SRCS:.c=.o)
INC = ./includes/ft_printf.h
LIBFT = libft.a
LIBFTSRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
ft_strnstr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_strrchr.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_nbr_of_digits.c
LIBSRCS = $(addprefix ../, $(LIBFTSRCS));
LIBOBJ = $(LIBFTSRCS:.c=.o)

all: $(NAME)

$(NAME) : $(SRCSDEST) $(LIBFT)
	@cc -c $(SRCSDEST)
	@ar -rcs $(NAME) $(OBJS) $(LIBOBJ)
	@rm -f $(LIBFT)

clean:
	rm -f $(OBJS) $(LIBOBJ)

fclean: clean
	rm -f $(NAME) $(LIBFT)

re: fclean all

$(LIBFT): $(LIBSRCS)
	@cc -c $(LIBSRCS)
	@ar -rcs $(LIBFT) $(LIBOBJ)
