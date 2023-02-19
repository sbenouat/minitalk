# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbenouat <sbenouat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 14:20:15 by sbenouat          #+#    #+#              #
#    Updated: 2023/02/13 14:38:24 by sbenouat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= client.c server.c

OBJS	= ${SRCS:.c=.o}

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

all :
		make -C ./printf
		gcc -Wall -Wextra -Werror client.c -L ./printf/libftprintf.a -lftprintf -o client

client: ${OBJS}



