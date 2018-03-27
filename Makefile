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

NAME = daleksan.filler

SRC = filler.c reading.c choose_move.c check_fig.c ft_check_fig.c 

COLOR = color

COLOR_SRC = my_color.c

LIB = libft.a
LIBPRINT = libftprintf.a

OBJ = $(SRC:.c=.o)
OBJ_COL = $(COLOR_SRC:.c=.o)

all: $(NAME) $(COLOR)

$(NAME): $(OBJ)
	@make -C libft/
	@make -C ft_printf/
	$(CC) -o $(NAME) $(OBJ) libft/libft.a ft_printf/libftprintf.a
	@echo "\033[32;1m<<filler done>>\033[0m"

$(COLOR): $(OBJ_COL)
	$(CC) -o $(COLOR) $(OBJ_COL) libft/libft.a ft_printf/libftprintf.a

clean:
	@make clean -C libft/
	@make clean -C ft_printf/
	@rm -f $(OBJ)
	@rm -f $(OBJ_COL)
	@echo "\033[32;1m<<delete objects>>\033[0m"
	
fclean: clean
	@make fclean -C libft/
	@make fclean -C ft_printf/
	@rm -rf $(NAME)
	@rm -rf $(COLOR)
	@echo "\033[32;1m<<delete filler>>\033[0m"

re: fclean all
