# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chorse <chorse@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/23 13:47:56 by ysachiko          #+#    #+#              #
#    Updated: 2022/04/26 19:59:29 by chorse           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

CC = gcc

CFLAGS = -Wall -Werror -Wextra -fsanitize=address -pthread -g

INC = philo_bonus.h

SRC	   = main.c init.c usage.c action.c monitoring.c exit.c\

OBJ = $(patsubst %.c,%.o,$(SRC))

all : $(NAME)

$(NAME) : $(OBJ)
	@echo "\033[0;33m\n\nCompiling philosophers..."
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "\n\033[0;36mDone."

%.o : %.c $(INC)
	@printf "\033[0;34mGenerating philosophers objects... %-10.10s\r" $@
	gcc $(CFLAGS) -c $< -o $@

clean :
	@echo "\033[0;31m\nDeleting objects..."
	rm -f $(OBJ)
	@echo "\n\033[0;31mDeleted.\n"

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
