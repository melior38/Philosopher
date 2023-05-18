# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asouchet <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 15:14:22 by asouchet          #+#    #+#              #
#    Updated: 2022/11/04 15:14:24 by asouchet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME =	libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRC_PATH = ./src/
OPTION = -I$(SRC_PATH) -c
SRC =	ft_printf.c \
	ft_print_nbr.c \
	ft_printf_utils.c

SRCS = $(addprefix $(SRC_PATH), $(SRC))
OBJS = $(SRCS:.c=.o)
CC = gcc


all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) $(OPTION) $(<) -o $(<:.c=.o)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all
