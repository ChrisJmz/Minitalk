# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjimenez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 16:03:33 by cjimenez          #+#    #+#              #
#    Updated: 2022/03/01 18:09:53 by cjimenez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server

PATH_PRINTF = ./ft_printf/ft_printf.a

SRCS = ft_server.c	\

OBJS = $(SRCS:.c=.o)

CC = gcc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:	$(NAME)


$(NAME):	$(OBJS)
	make -C ft_printf
	$(CC) $(CFLAGS) $(OBJS) $(PATH_PRINTF) -o $(NAME)

clean:
	make clean -C ft_printf
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(PATH_PRINTF)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
