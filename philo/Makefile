# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myukang <myukang@student.42.kr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/15 22:08:17 by myukang           #+#    #+#              #
#    Updated: 2022/05/18 22:17:20 by myukang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRCS = main.c print_err.c init_argv.c ft_atoi.c
OBJS = $(SRCS:.c=.o)
INC = ./
GCC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=thread

all : $(NAME)

$(NAME) : $(OBJS)
	$(GCC) -o $(NAME) $(CFLAGS) $^ -I$(INC)

%.o : %.c
	$(GCC) $(CFLAGS) -c $^ -I$(INC)

clean : 
	rm -rf $(OBJS)

fclean : 
	make clean
	rm -rf $(NAME)

re : 
	make fclean
	make all

