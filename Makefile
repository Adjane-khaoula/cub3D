# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kadjane <kadjane@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 16:38:04 by kadjane           #+#    #+#              #
#    Updated: 2023/02/25 23:56:22 by kadjane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = parser.c main.c get_next_line.c get_next_line_utils.c ft_split.c

NAME := cub3D

OBJS = $(SRCS:.c=.o)
CC = gcc

CFLAGS := -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) -I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit -o $(NAME)
bonus : all

clean : 
	@rm -f *.o
fclean : clean
	@rm -f $(NAME)
re : fclean all
