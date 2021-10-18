# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/03 12:52:27 by bahn              #+#    #+#              #
#    Updated: 2021/10/18 16:06:28 by bahn             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OS				= $(shell uname -s)

NAME			= fractol

CC				= gcc
CFLAGS			= -Wall -Werror -Wextra -g
INCFLAGS		= -I./includes -I./libft



LIBFT_PATH		= ./libft/
LIBFT_LINK		= -Llibft -lft

ifeq ($(OS), Linux)
	MLX_PATH	= ./minilibx-linux
	MLX_FLAGS	= -I./minilibx-linux -Lminilibx-linux/ -lmlx -lX11 -lXext -lm -lbsd -O3
	SRCS_FREE	= free_on_linux.c
else
	MLX_PATH	= ./minilibx-mac
	MLX_FLAGS	= -I./minilibx-mac -Lminilibx-mac/ -lmlx -lm -framework OpenGL -framework AppKit -O3
	SRCS_FREE 	= free_on_macos.c
endif

SRCS_PATH		= ./srcs/
SRCS_NAME		= main.c fractol.c draw.c \
					mandelbrot.c julia.c burning_ship.c \
					mouse.c keyboard.c color.c centroid.c scene.c utils.c
SRCS 			= $(addprefix $(SRCS_PATH), $(SRCS_NAME) $(SRCS_FREE))
OBJS			= $(SRCS:.c=.o)

all 			: $(NAME)

ifeq ($(OS), Linux)
.c.o :
	$(CC) $(CFLAGS) -c $< $(INCFLAGS) $(MLX_FLAGS) $(LIBFT_LINK) -o $@
else
.c.o :
	$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@
endif

$(NAME) 		: $(OBJS)
				$(MAKE) all -C $(LIBFT_PATH)
				$(MAKE) all -C $(MLX_PATH)
ifeq ($(OS), Linux)
				$(CC) $(CFLAGS) $^ $(INCFLAGS) $(LIBFT_LINK) $(MLX_FLAGS) -o $@
else
				$(CC) $(CFLAGS) $(INCFLAGS) $(LIBFT_LINK) $(MLX_FLAGS) -o $@ $^
endif

clean			: 
				$(MAKE) clean -C $(MLX_PATH)
				$(MAKE) clean -C $(LIBFT_PATH)
				rm -fv $(OBJS)

fclean			: clean
				rm -fv $(NAME) $(addprefix $(LIBFT_PATH), libft.a)

re				: fclean all

.PHONY			: all clean fclean re
