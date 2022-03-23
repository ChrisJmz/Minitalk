# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 16:03:33 by cjimenez          #+#    #+#              #
#    Updated: 2022/03/14 10:47:02 by cjimenez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = server
NAME2 = client

NAMEBONUS1 = server_bonus
NAMEBONUS2 = client_bonus

PATH_PRINTF = ./ft_printf/ft_printf.a

SRC_SERVER =	ft_server.c	\

SRC_CLIENT =	ft_client.c	\
				utils.c	\

OBJS_SERVER = $(SRC_SERVER:.c=.o)

OBJS_CLIENT = $(SRC_CLIENT:.c=.o)

BONUS_SERVER =	ft_server_bonus.c	\

BONUS_CLIENT =	ft_client_bonus.c	\
				utils_bonus.c		\

OBJS_SERVER_BONUS = $(BONUS_SERVER:.c=.o)

OBJS_CLIENT_BONUS = $(BONUS_CLIENT:.c=.o)

INC = minitalk.h
INC_BONUS = minitalk_bonus.h

CC = gcc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror -g

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:	$(NAME1) $(NAME2)

$(NAME1):	$(OBJS_SERVER) $(INC)
	make -C ft_printf
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(PATH_PRINTF) -o $(NAME1)

$(NAME2):	$(OBJS_CLIENT) $(INC)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(PATH_PRINTF) -o $(NAME2)

bonus:	$(NAMEBONUS1) $(NAMEBONUS2)

$(NAMEBONUS1): $(OBJS_SERVER_BONUS) $(INC_BONUS)
	make -C ft_printf
	$(CC) $(CFLAGS) $(OBJS_SERVER_BONUS) $(PATH_PRINTF) -o $(NAMEBONUS1)
	
$(NAMEBONUS2): $(OBJS_CLIENT_BONUS) $(INC_BONUS)
	$(CC) $(CFLAGS) $(OBJS_CLIENT_BONUS) $(PATH_PRINTF) -o $(NAMEBONUS2)

clean:
	make clean -C ft_printf
	$(RM) $(OBJS_SERVER)
	$(RM) $(OBJS_CLIENT)
	$(RM) $(OBJS_SERVER_BONUS)
	$(RM) $(OBJS_CLIENT_BONUS)

fclean: clean
	$(RM) $(PATH_PRINTF)
	$(RM) $(NAME1)
	$(RM) $(NAME2)
	$(RM) $(NAMEBONUS1)
	$(RM) $(NAMEBONUS2)

re: fclean all

.PHONY: all clean fclean re
