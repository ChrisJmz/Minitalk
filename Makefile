# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 16:03:33 by cjimenez          #+#    #+#              #
#    Updated: 2022/03/07 13:40:51 by cjimenez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = server
NAME2 = client

PATH_PRINTF = ./ft_printf/ft_printf.a

SRCS_SERVER = ft_server.c	\

SRCS_CLIENT =	ft_client.c	\
				utils.c		\

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

CC = gcc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:	$(NAME1) $(NAME2)

$(NAME1):	$(OBJS_SERVER)
	make -C ft_printf
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(PATH_PRINTF) -o $(NAME1)

$(NAME2):	$(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(PATH_PRINTF) -o $(NAME2)

clean:
	make clean -C ft_printf
	$(RM) $(OBJS_SERVER)
	$(RM) $(OBJS_CLIENT)

fclean: clean
	$(RM) $(PATH_PRINTF)
	$(RM) $(NAME1)
	$(RM) $(NAME2)

re: fclean all

.PHONY: all clean fclean re
