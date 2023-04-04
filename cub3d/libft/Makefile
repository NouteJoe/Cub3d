# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmarzull <gmarzull@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/03 12:15:22 by gmarzull          #+#    #+#              #
#    Updated: 2023/03/16 13:29:50 by gmarzull         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

SRCS		= ft_itoa.c ft_atoi.c ft_strncmp.c ft_strlen.c get_next_line.c\
			get_next_line_utils.c ft_strjoin.c ft_memcpy.c ft_split.c ft_substr.c

OBJS		= ${SRCS:.c=.o}

CC			= gcc

FLAGS		= -Wall -Wextra -Werror

.c.o:		
			${CC} ${FLAGS} -I. -c $< -o ${<:c=o}

$(NAME)	:	$(OBJS)
			ar -rc $(NAME) $(OBJS)

all:		$(NAME)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re