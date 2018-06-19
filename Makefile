#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/27 13:32:35 by dpozinen          #+#    #+#              #
#    Updated: 2018/04/21 13:17:01 by dpozinen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = dpozinen.filler
SRCS = main.c execute.c make_points.c place_token.c
FLAGS = -o $(NAME) -Wall -Werror -Wextra

all:
	@cd libft; make
	@gcc $(FLAGS) $(SRCS) libft/libft.a
	@echo "compiled $(NAME)"

b:
	@cd libft; make
	@gcc $(FLAGS) $(SRCS) libft/libft.a
	@echo "compiled $(NAME)"

r:
	@cd libft; make
	@gcc $(FLAGS) $(SRCS) libft/libft.a
	@cp $(NAME) resources
	@cd resources
	@echo "compiled $(NAME)"

rm:
	@rm $(NAME)
