# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myukang <myukang@student.42.kr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/15 22:08:17 by myukang           #+#    #+#              #
#    Updated: 2022/05/15 22:13:58 by myukang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRCS = 
OBJS = $(SRCS:.c=.o)
INC = ./
GCC = gcc
CFLAGS = -Wall -Wextra -Werror

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

