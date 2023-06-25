# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dclark <dclark@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/26 12:16:27 by dclark            #+#    #+#              #
#    Updated: 2021/11/22 12:59:16 by dclark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= main.c \
			  srcs/check_data.c \
			  srcs/taking_data.c \
			  srcs/init_data.c \
			  srcs/ft_isdigit.c \
			  srcs/ft_strlen.c \
			  srcs/ft_putstr.c \
			  srcs/ft_atoi.c \
			  srcs/ft_putnbr.c \
			  srcs/time_passed.c \
			  srcs/time_to_passe.c \
			  srcs/check_death.c \
			  srcs/restart_death.c \
			  srcs/kill_philo.c \
			  srcs/table_of_philo2.c \
			  srcs/taking_fork.c \
			  srcs/release_fork.c \
			  srcs/grid_philo.c

HEADER		= includes/

NAME		= philo

OBJS		= $(SRCS:.c=.o)

CFLAGS		+= -Wall -Werror -Wextra -I $(HEADER) -pthread

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
