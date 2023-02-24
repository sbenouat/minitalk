# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbenouat <sbenouat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 14:20:15 by sbenouat          #+#    #+#              #
#    Updated: 2023/02/24 16:20:09 by sbenouat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= srcs/client.c srcs/server.c
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

all: server client

server: objs/server.o
		make -C ./libftprintf
		$(CC) -o $@ $< -Llibftprintf -lftprintf

objs/server.o: srcs/server.c objs/
		$(CC) -c $(CFLAGS) $< -o $@

client: objs/client.o
		make -C ./libftprintf
		$(CC) -o $@ $< -Llibftprintf -lftprintf

objs/client.o: srcs/client.c objs/
		$(CC) -c $(CFLAGS) $< -o $@

objs/:
		mkdir objs

clean:
		rm -rf objs/
		make -C libftprintf clean

fclean: clean
		rm -f server client libftprintf/libftprintf.a

re: fclean all

.PHONY: all clean fclean re
