# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kadjane <kadjane@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 16:38:04 by kadjane           #+#    #+#              #
#    Updated: 2023/03/09 19:39:29 by kadjane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS = parser_textures.c main.c get_next_line.c \
	get_next_line_utils.c ft_split.c ft_strcmp.c\
	ft_atoi.c parser_map.c ft_split_textures.c

OBJ_D = obj

OBJS = $(addprefix $(OBJ_D)/,${SRCS:.c=.o})

CC = cc

CFLAGS = -Wall -Wextra -Werror -Imlx

all : ${NAME}

$(OBJ_D)/%.o:  %.c | ${OBJ_D}
	@$(CC) $(CFLAGS) -c $< -o $@

${NAME} :${OBJS}
	@$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME) -fsanitize=address -g3
	@echo "|  Compilation Done  |"

${OBJ_D} :
	@mkdir ${OBJ_D}

clean:
	@rm -rf ${OBJ_D}
	@echo "|  CLEANED |"

fclean: clean
	@rm -rf ${NAME}

re: fclean all
