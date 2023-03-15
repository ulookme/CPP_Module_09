# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chajjar <chajjar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 15:46:23 by chajjar           #+#    #+#              #
#    Updated: 2023/03/15 10:52:54 by chajjar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RPN

SRC = main.cpp RPN.cpp
OBJ = $(SRC:.cpp=.o)
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(FLAGS) -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)
fclean: clean 
		rm -f $(NAME)
re: clean all

.PHONY: all clean fclean re 