# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ychufist <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/19 16:49:26 by ychufist          #+#    #+#              #
#    Updated: 2019/03/06 20:45:10 by ychufist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

LIBFT = ./libft/libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRC = main.c ft_adds.c ft_ants.c ft_is.c ft_list_room.c ft_ways.c ft_bonuses.c ft_get.c

OUT = $(SRC:.c=.o)

HDR = lem_in.h

all: lib $(NAME)

lib:
	make -C ./libft

$(NAME): $(OUT) $(LIBFT)
	gcc -g -o $(NAME) $(OUT) $(LIBFT)

%.o: %.c $(HDR)
	gcc $(FLAGS) -o $@ -c $< -I ./libft

clean:
	make clean -C ./libft
	/bin/rm -f $(OUT)
	/bin/rm -f *~

fclean: clean
	make fclean -C ./libft
	/bin/rm -f $(NAME)

debug: FLAGS += -g 
debug: all	

re: fclean all
