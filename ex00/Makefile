# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/19 09:41:10 by faksouss          #+#    #+#              #
#    Updated: 2023/11/19 09:46:15 by faksouss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp BitcoinExchange.cpp

INC = BitcoinExchange.hpp

FLGS = -Wall -Wextra -Werror -std=c++98

NAME = btc

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	c++ $(FLGS) $^ -o $@

%.o : %.cpp $(INC)
	c++ $(FLGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all re clean fclean

.SILENT : all $(NAME) clean fclean $(OBJ) re
