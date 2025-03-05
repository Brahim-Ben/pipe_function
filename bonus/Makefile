# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbenaali <bbenaali@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/03 10:48:18 by bbenaali          #+#    #+#              #
#    Updated: 2025/03/05 11:08:25 by bbenaali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = pipex_bonus.c ft_split.c ft_strjoin.c get_next_line.c get_next_line_utils.c \
		here_doc.c 

OBJ = ${SRC:.c=.o}

RM = rm -f

BONUS = bonus

FLAGS = -Wall -Wextra -Werror

CC = cc

all: ${BONUS}

${BONUS}: ${OBJ}
	${CC} ${FLAGS} ${OBJ} -o ${BONUS}
	
%.o: %.c pipex_bonus.h
	${CC} ${FLAGS} -c $< -o $@
	
clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${BONUS}

re: fclean all	
