# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/16 19:21:00 by user42            #+#    #+#              #
#    Updated: 2021/03/16 19:39:46 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl

CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=10000000

SRC = get_next_line.c get_next_line_utils.c main.c

all: $(NAME)

$(NAME):
		gcc $(CFLAGS) $(SRC)
fclean:
		rm *.out
re: fclean all