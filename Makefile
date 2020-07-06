# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adietric <adietric@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 17:16:35 by flafonso          #+#    #+#              #
#    Updated: 2019/01/10 19:00:54 by adietric         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC =	fill_struct.c	\
		ft_check.c		\
		main.c			\
		morback_track.c	\
		map.c

PO = $(SRC:.c=.o)

INCLUDE = ./

CC = gcc

FLAG = -Wall -Werror -Wextra

all: $(NAME)

check:
	make -C ./libft

$(NAME): check $(PO)
	$(CC) $(FLAG) -c $(SRC) -I $(INCLUDE)
	$(CC) $(FLAG) $(PO) ./libft/libft.a -I $(INCLUDE) -o $(NAME)

clean:
	make clean -C ./libft
	rm -f $(PO)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all
