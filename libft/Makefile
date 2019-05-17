# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ychufist <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/24 14:31:10 by ychufist          #+#    #+#              #
#    Updated: 2018/04/19 17:05:46 by ychufist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCLIBA = ft_memset.c ft_bzero.c ft_memcpy.c\
		ft_memccpy.c ft_memmove.c ft_memchr.c\
		ft_memcmp.c ft_strlen.c ft_strdup.c\
		ft_strncpy.c ft_strcpy.c ft_strstr.c\
		ft_strnstr.c ft_strcmp.c ft_strncmp.c\
		ft_strchr.c ft_strrchr.c ft_toupper.c\
		ft_tolower.c ft_isalpha.c ft_isalnum.c\
		ft_isprint.c ft_isdigit.c ft_isascii.c\
		ft_strcat.c ft_strncat.c ft_atoi.c ft_itoa.c\
		ft_memalloc.c ft_memdel.c ft_strnew.c\
		ft_strdel.c ft_strclr.c ft_striter.c\
		ft_striteri.c ft_strmap.c ft_strmapi.c\
		ft_strequ.c ft_strnequ.c ft_strsub.c\
		ft_strjoin.c ft_strlcat.c ft_strtrim.c\
		ft_strsplit.c ft_putchar.c ft_putstr.c\
		ft_putendl.c ft_putnbr.c ft_putchar_fd.c\
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
		ft_cl.c ft_cw.c ft_lstnew.c ft_lstdelone.c\
		ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c\
		ft_foreach.c ft_mmap.c ft_sqrt.c ft_intlength.c\
		get_next_line.c
	  
SRCPRNTF = ft_printf.c \
		ft_print_id.c\
	  	ft_print_o.c\
	  	ft_print_x_u.c\
	  	ft_print_bigs.c\
	  	ft_print_s.c\
	  	ft_print_c.c\
	  	ft_print_p.c\
	  	ft_itoa_unsigned.c \
	  	ft_new_tout.c\
	  	ft_params.c\
	  	ft_flags.c\
	  	ft_presflags.c\
	  	ft_octflag.c\
	  	ft_dopfile.c\
	  	ft_dopfile1.c

HDR = libft.h ft_printf.h get_next_line.h

FLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): 
	gcc $(FLAG) -c $(SRCLIBA) $(SRCPRNTF) -I $(HDR)
	ar rc $(NAME) *.o

clean:
	/bin/rm -f *.o
	/bin/rm -f *~

fclean: clean
	/bin/rm -f $(NAME)

re : fclean all
