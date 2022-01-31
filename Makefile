NAME := libftprintf.a
CC := gcc
CFLAGS := -Wall -Wextra -Werror
SRCS = ft_printf.c\

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	ar rc $@ $(OBJS)

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re