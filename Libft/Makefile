NAME = libft.a
INCDIR = -I./
CC := gcc
CFLAGS := -Wall -Wextra -Werror
SRCS = ft_strlen.c\
	   ft_bzero.c\
	   ft_memcpy.c\
	   ft_calloc.c\
	   ft_itoa.c\
	   ft_putchar_fd.c\
	   ft_putstr_fd.c\

OBJS = $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) $(INCDIR) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $@ $(OBJS)

all:$(NAME)

clean:
	rm -f $(OBJS)

fclean:clean
	rm -f $(NAME)

re:fclean all

.PHONY : all clean fclean re
