# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 19:08:37 by mdi-paol          #+#    #+#              #
#    Updated: 2023/05/15 12:03:28 by mdi-paol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers
SRC = main.c utils1.c initialize.c statements.c statements1.c
FLAGS = -Wall -Werror -Wextra -g -pthread

all : $(NAME)

$(NAME) : ps

ps:
			gcc $(FLAGS) $(SRC) -o $(NAME)
			@echo "\033[1;32m✅ Compiled ✅\033[0m"

clean :
			rm -rf $(NAME)
			@echo "\033[1;34m☑️  Clean ☑️\033[0m"

fclean :
			rm -rf $(NAME)
			@echo "\033[1;34m☑️  Clean ☑️\033[0m"

re : fclean all

.SILENT:
