SRCS = ft_printf.c ft_printhexa.c ft_put.c
SRCSb = ft_printf_bonus.c ft_printhexa.c ft_put.c
NAME = libftprintf.a
HEADER = ft_printf.h 
OBJS = $(SRCS:.c=.o)
OBJSb = $(SRCSb:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS) $(OBJSb)
	ar rc $(NAME) $(OBJS) $(OBJSb)

bonus : $(OBJSb)
	ar rc $(NAME) $(OBJSb)

clean :
	rm -rf $(OBJS) $(OBJSb)

fclean : clean
	rm -rf $(NAME)

re : clean fclean all