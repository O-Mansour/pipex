# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omansour <omansour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/28 11:39:52 by omansour          #+#    #+#              #
#    Updated: 2023/01/29 09:24:53 by omansour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_split.c pipex_fcts.c pipex.c show_error.c utils.c utils2.c

OBJS	=	${SRCS:.c=.o}

NAME	=	pipex

FLAGS	=	-Wall -Wextra -Werror

CC		=	CC

RM		=	rm -f

all : ${NAME}

${NAME} : ${OBJS}
		${CC} ${FLAGS} ${OBJS} -o ${NAME}

clean :
		${RM} ${OBJS}

fclean : clean
		${RM} ${NAME}

re : fclean all
