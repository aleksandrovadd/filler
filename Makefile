# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daleksan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/04 19:23:14 by daleksan          #+#    #+#              #
#    Updated: 2017/10/04 19:23:19 by daleksan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = @gcc -Wall -Wextra -Werror

NAME = filler

SRC = filler.c reading.c choose_move.c check_fig.c ft_check_fig.c

LIB = libft.a
LIBPRINT = libftprintf.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@make -C ft_printf/
	$(CC) -o $(NAME) $(OBJ) libft/libft.a ft_printf/libftprintf.a
	@echo "\033[32;1m<<fillit done>>\033[0m"

clean:
	@make clean -C libft/
	@make clean -C ft_printf/
	@rm -f $(OBJ)
	@echo "\033[32;1m<<delete objects>>\033[0m"
	
fclean: clean
	@make fclean -C libft/
	@make fclean -C ft_printf/
	@rm -rf $(NAME)
	@echo "\033[32;1m<<delete>>\033[0m"

re: fclean all
	@echo "\033[32;1m<<re succes>>\033[0m"
