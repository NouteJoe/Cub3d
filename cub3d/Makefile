# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmarzull <gmarzull@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 22:12:04 by gmarzull          #+#    #+#              #
#    Updated: 2023/03/30 15:43:32 by gmarzull         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3d

LIBFT		= ./libft/libft.a

GNL			= ./gnl/libgnl.a

MLX			= ../MLX42/build/libmlx42.a

SRC			= src/main.c src/init_map.c src/init_player.c src/check.c\
			src/utils.c src/free.c src/move.c src/ray.c src/init_cub.c\
			src/minimap.c src/check_file.c src/check_map.c


#SRC			= $(foreach file, $(ALL), src/$(file).c)

OBJS		= ${SRC:.c=.o}

HEADER		= cub3d.h

CC			= gcc

FLAGS		= -Wall -Wextra -Werror -g
LINKER		= -g

.c.o:
			${CC} $(FLAGS) -c -I./libft $< -o ${<:.c=.o}

all:		 $(LIBFT) $(NAME)

$(NAME)	: 	${OBJS} 
			$(CC) $(FLAGS) $(LIBFT) ${OBJS} $(MLX) -Iinclude -lglfw -L"/Users/$$USER/.brew/opt/glfw/lib/" -framework Cocoa -framework OpenGL -framework IOKit -o $(NAME)

$(LIBFT):	
			@$(MAKE) -sC ./libft

clean:		
			@$(MAKE) clean -sC ./libft
			@rm -f $(OBJS)

fclean:		clean
			@$(MAKE) fclean -sC ./libft
			@rm -f $(NAME)

relib:
			@make re -sC ./libft

re:			fclean all

.PHONY:		all clean fclean re relib

