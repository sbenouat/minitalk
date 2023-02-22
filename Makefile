# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbenouat <sbenouat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 14:20:15 by sbenouat          #+#    #+#              #
#    Updated: 2023/02/22 18:48:26 by sbenouat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= client.c server.c
OBJS	= ${SRCS:.c=.o}
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

all: server client

server: server.o
		make -C ./libftprintf
		$(CC) -o $@ $< -Llibftprintf -lftprintf

client: client.o
		make -C ./libftprintf
		$(CC) -o $@ $< -Llibftprintf -lftprintf

%.o: %.c
		$(CC) -c $(CFLAGS) $?

clean:
		rm -f $(OBJS)
		make -C libftprintf clean

fclean: clean
		rm -f server client libftprintf/libftprintf.a

re: fclean all

.PHONY: all clean fclean re
