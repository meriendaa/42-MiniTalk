# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmerida- <tmerida-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 18:25:22 by tmerida-          #+#    #+#              #
#    Updated: 2022/03/21 18:25:25 by tmerida-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_SERVER = server.c minitalk_utils.c minitalk_utils2.c
SRC_CLIENT = client.c minitalk_utils.c minitalk_utils2.c

NAME_SERVER = server
NAME_CLIENT = client

OBJ_SERVER = server.o minitalk_utils.o minitalk_utils2.o
OBJ_CLIENT = client.o minitalk_utils.o minitalk_utils2.o

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I.

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) -o $@ $(OBJ_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) -o $@ $(OBJ_CLIENT)


clean:
		rm -f $(OBJ_SERVER) $(OBJ_CLIENT)
fclean: clean
		rm -f $(OBJ_SERVER) $(OBJ_CLIENT) $(NAME_SERVER) $(NAME_CLIENT)
re: fclean all

.PHONY: server client all re fclean clean