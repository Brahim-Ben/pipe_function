# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbenaali <bbenaali@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/23 08:42:08 by bbenaali          #+#    #+#              #
#    Updated: 2025/03/06 21:57:29 by bbenaali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = Mandatory/pipex.c Mandatory/ft_split.c Mandatory/ft_strjoin.c Mandatory/other_function.c Mandatory/other_fun.c Mandatory/others.c

OBJ = ${SRC:.c=.o}

BSRC = bonus/pipex_bonus.c bonus/ft_split_bonus.c bonus/ft_strjoin_bonus.c bonus/get_next_line_bonus.c bonus/get_next_line_utils_bonus.c bonus/here_doc_bonus.c \
		bonus/other_function_bonus.c bonus/other_fun_bonus.c bonus/others_bonus.c bonus/pipex_tow_bonus.c

BOBJ = ${BSRC:.c=.o}

CC = cc

RM = rm -f

FLAGS = -Wall -Wextra -Werror

NAME = pipex

all: ${NAME}

%bonus.o: %bonus.c bonus/pipex_bonus.h bonus/get_next_line_bonus.h
	${CC} ${FLAGS} -c $< -o $@

bonus: ${BOBJ}
	${CC} ${FLAGS} ${BOBJ} -o ${NAME}

${NAME}: ${OBJ} 
	${CC} ${FLAGS} ${OBJ} -o ${NAME}

%.o: %.c Mandatory/pipex.h 
	${CC} ${FLAGS} -c $< -o $@


clean:
	${RM} ${OBJ} ${BOBJ}

fclean: clean
	${RM} ${NAME} 

re: fclean all