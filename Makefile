# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dclark <dclark@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/26 12:16:27 by dclark            #+#    #+#              #
#    Updated: 2021/10/11 15:05:44 by dclark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= main.c \
			  srcs/check_data.c \
			  srcs/ft_isdigit.c \
			  srcs/ft_strlen.c \
			  srcs/ft_putstr.c \
			  srcs/ft_atoi.c \
			  srcs/taking_data.c \
			  srcs/table_of_philo.c \
			  srcs/init_data.c

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
