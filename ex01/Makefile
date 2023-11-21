# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 04:32:17 by faksouss          #+#    #+#              #
#    Updated: 2023/11/21 04:38:37 by faksouss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp RPN.cpp

OBJ = $(SRC:.cpp=.o)

INC = RPN.hpp

FLGS = -Wall -Wextra -Werror -std=c++98

NAME = RPN

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

.SILENT : all re fclean clean $(NAME) $(OBJ)
