# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rel-maza <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 14:20:15 by rel-maza          #+#    #+#              #
#    Updated: 2021/12/15 14:20:20 by rel-maza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
