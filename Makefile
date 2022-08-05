# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 13:17:29 by amarzana          #+#    #+#              #
#    Updated: 2022/08/05 09:31:13 by amarzana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3
OBJ = $(SRC:.c=.o)

SRC = 	mov_push_rrotate.c		\
		mov_swap_rotate.c		\
		utils_exit.c			\
		utils_lst.c				\
		utils_count.c			\
		utils_init.c			\
		ft_atoi.c 				\
		ft_split.c				\
		ft_checks.c				\
		ft_index.c				\
		ord_three_five.c		\
		ord_any.c				\
		push_swap.c	

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo Mandatory: Compilation done


%.o: %.c
	@echo Generating object $@
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo Object files removed

fclean: clean
	@rm -f $(NAME)
	@echo Executable file removed

re: fclean all

.PHONY: all clean fclean re bonus