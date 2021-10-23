NAME = libftprintf.a

SRCS =  ft_printf.c ft_puthex.c ft_putnbr.c ft_putstr.c ft_putunnbr.c \
		ft_putchar.c

CC = gcc

RM = rm -rf

MAKE = Makefile

OBJS = ${SRCS:%.c=%.o}

CFLAGS = -Wall -Werror -Wextra

HEAD = ft_printf.h

%.o:		%.c $(HEAD) $(MAKE)
	  		$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

all:  		$(NAME)

$(NAME) : 	$(OBJS) $(HEAD)
			ar rcs $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean: 	clean
			$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re