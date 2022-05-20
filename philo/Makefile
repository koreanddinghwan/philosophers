# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myukang <myukang@student.42.kr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/15 22:08:17 by myukang           #+#    #+#              #
#    Updated: 2022/05/21 04:50:56 by myukang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
INC = ./includes
GCC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=thread

ACT_MOD_D = ./act_module/
ACT_SRCS = pick_fork.c
ACT_OBJS = $(addprefix $(ACT_MOD_D), $(ACT_SRCS:.c=.o))

INIT_MOD_D = ./init_module/
INIT_SRCS = main.c init_argv.c init_mutex.c init_philo_data.c
INIT_OBJS = $(addprefix $(INIT_MOD_D), $(INIT_SRCS:.c=.o))

THR_MOD_D = ./thread_module/
THR_SRCS = init_philo_thread.c init_reaper_thread.c routine_philo.c
THR_OBJS = $(addprefix $(THR_MOD_D), $(THR_SRCS:.c=.o))

TOOLS_D = ./tools/
TOOLS_SRCS = cal_time.c ft_atoi.c logger.c philo_free.c print_err.c print_log.c
TOOLS_OBJS = $(addprefix $(TOOLS_D), $(TOOLS_SRCS:.c=.o))



OBJS = $(ACT_OBJS) $(INIT_OBJS) $(THR_OBJS) $(TOOLS_OBJS)

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

