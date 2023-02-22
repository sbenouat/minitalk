# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbenouat <sbenouat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 14:20:15 by sbenouat          #+#    #+#              #
#    Updated: 2023/02/22 18:40:52 by sbenouat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= client.c server.c

OBJS	= ${SRCS:.c=.o}

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

all : server

server : libftprintf
		make -C ./libftprintf
		$(CC) -o server server.c -Llibftprintf -lftprintf

# %.o: %.c
# 		$(CC) -c $(CFLAGS) $?

libftprintf :
		make -C ./libftprintf

clean:
	rm -f $(OBJS)
	make -C libftprintf clean

fclean: clean
	rm -f server client libftprintf/libftprintf.a

re: fclean all
