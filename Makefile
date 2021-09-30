# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/03 12:52:27 by bahn              #+#    #+#              #
#    Updated: 2021/09/30 13:07:38 by bahn             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fractol

CC				= gcc
CFLAGS			= -Wall -Werror -Wextra -g

INCFLAGS		= -I./includes -I./minilibx-linux -I./libft

MLX_PATH		= ./minilibx-linux
MLX_FLAGS_MAC	= -lmlx -lm -framework OpenGL -framework AppKit
MLX_FLAGS_LINUX	= -Lminilibx-linux/ -lmlx -lX11 -lXext -lm -lbsd -O3

LIBFT_PATH		= ./libft/
LIBFT_LINK		= -Llibft -lft

SRCS_PATH		= ./srcs/
SRCS_NAME		= main.c fractol.c \
					mandelbrot.c julia.c \
					mouse.c keyboard.c color.c utils.c
SRCS 			= $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJS			= $(SRCS:.c=.o)

all 			: $(NAME)

.c.o			:
				$(CC) $(INCFLAGS) -c $< $(MLX_FLAGS_LINUX) $(LIBFT_LINK) -o $@

$(NAME) 		: $(OBJS)
				$(MAKE) all -C $(MLX_PATH)
				$(MAKE) all -C $(LIBFT_PATH)
				$(CC) $(INCFLAGS) $^ $(MLX_FLAGS_LINUX) $(LIBFT_LINK) -o $@

clean			: 
				$(MAKE) clean -C $(MLX_PATH)
				$(MAKE) clean -C $(LIBFT_PATH)
				rm -fv $(OBJS)

fclean			: clean
				rm -fv $(NAME) $(addprefix $(LIBFT_PATH), libft.a)

re				: fclean all

.PHONY			: all clean fclean re