# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbenaali <bbenaali@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/23 08:42:08 by bbenaali          #+#    #+#              #
#    Updated: 2025/03/03 11:16:39 by bbenaali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = pipex.c ft_split.c ft_strjoin.c other_function.c other_fun.c others.c

OBJ = ${SRC:.c=.o}

CC = cc

RM = rm -f

FLAGS = -Wall -Wextra -Werror

NAME = pipex

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${FLAGS} ${OBJ} -o ${NAME}

%.o: %.c pipex.h
	${CC} ${FLAGS} -c $< -o $@

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all