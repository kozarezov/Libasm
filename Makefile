# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ceccentr <ceccentr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/10 17:01:50 by ceccentr          #+#    #+#              #
#    Updated: 2020/09/12 17:31:11 by ceccentr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_strdup.s ft_read.s ft_write.s

NAME = libasm.a

CC = nasm -f macho64

HEADER = libasm.h

OBJ = $(SRCS:.s=.o)
BONUS_OBJS = $(BONUS_SRCS:.s=.o)

%.o:%.s
	$(CC) $<

all:$(NAME)

$(NAME):$(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re