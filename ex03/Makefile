# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aiblanco <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/15 23:05:13 by aiblanco          #+#    #+#              #
#    Updated: 2024/08/15 23:05:21 by aiblanco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Fixer
library.h = Fixed.hpp Point.hpp
CFLAGS = -Wall -Wextra -Werror
FILES = Fixed.cpp Point.cpp Bsp.cpp main.cpp
COMPILED_FILES = Fixed.o Point.o Bsp.o main.o
OBJ = $(FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(library.h) $(OBJ)
	g++ -o $(NAME) $(CFLAGS) $(OBJ) $(library.h)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
