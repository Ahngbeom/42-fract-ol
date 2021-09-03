# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/03 12:52:27 by bahn              #+#    #+#              #
#    Updated: 2021/09/03 13:14:17 by bahn             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fractol

CC				= gcc
CFLAGS_MAC		= -lmlx -lm -framework OpenGL -framework AppKit
CFLAGS_LINUX	= -Lminilibx-linux/ -lmlx -lX11 -lXext -lm -lbsd

INCFLAGS		= -I./minilibx-linux

SRCS_PATH		= ./
SRCS_NAME		= main.c
SRCS 			= $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJS			= $(SRCS:.c=.o)

all 			: $(NAME)

.c.o			:
				$(CC) $(INCFLAGS) -c $< $(CFLAGS_LINUX) -o $@

$(NAME) 		: $(SRCS)
				$(CC) $(INCFLAGS) $^ $(CFLAGS_LINUX) -o $@

clean			: 
				rm -fv $(OBJS)

fclean			: clean
				rm -fv $(NAME)

re				: fclean all

.PHONY			: all clean fclean re