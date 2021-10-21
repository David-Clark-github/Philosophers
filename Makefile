# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dclark <dclark@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/26 12:16:27 by dclark            #+#    #+#              #
#    Updated: 2021/10/21 15:28:38 by dclark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= main.c \
			  srcs/check_data.c \
			  srcs/ft_isdigit.c \
			  srcs/ft_strlen.c \
			  srcs/ft_putstr.c \
			  srcs/ft_atoi.c \
			  srcs/display_time.c \
			  srcs/ft_putnbr.c

HEADER		= includes/

NAME		= philo

OBJS		= $(SRCS:.c=.o)

CFLAGS		+= -Wall -Werror -Wextra -I $(HEADER)

CC			= gcc

all:	$(NAME)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f philo

re:		fclean
	make

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

.PHONY: all bonus clean fclean re
