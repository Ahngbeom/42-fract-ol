# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/03 12:52:27 by bahn              #+#    #+#              #
#    Updated: 2021/09/07 16:22:19 by bahn             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fractol

CC				= gcc
CFLAGS_MAC		= -lmlx -lm -framework OpenGL -framework AppKit
CFLAGS_LINUX	= -Lminilibx-linux/ -lmlx -lX11 -lXext -lm -lbsd

INCFLAGS		= -I./includes -I./minilibx-linux

SRCS_PATH		= ./srcs/
SRCS_NAME		= main.c \
					mouse.c keyboard.c color.c
SRCS 			= $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJS			= $(SRCS:.c=.o)

all 			: $(NAME)

.c.o			:
				$(CC) $(INCFLAGS) -c $< $(CFLAGS_LINUX) -o $@

$(NAME) 		: $(OBJS)
				$(CC) $(INCFLAGS) $^ $(CFLAGS_LINUX) -o $@

clean			: 
				rm -fv $(OBJS)

fclean			: clean
				rm -fv $(NAME)

re				: fclean all

.PHONY			: all clean fclean re