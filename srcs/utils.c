/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:56:21 by bahn              #+#    #+#             */
/*   Updated: 2021/10/06 18:25:06 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void  my_mlx_pixel_put(t_myimg *img, int x, int y, int color)
{
        char    *dst;

        dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
        *(unsigned int*)dst = color;
}

void	ft_exception_exit(char *title, char *detail)
{
	perror("\e[91m>>> Error \e[0m");
	if (title != NULL) {
		ft_putstr_fd("\e[95m", 1);
		ft_putstr_fd(title, 1);
	}
	if (detail != NULL) {
		ft_putstr_fd(" : ", 1);
		ft_putendl_fd(detail, 1);
	}
	else
		ft_putchar_fd('\n', 1);
	// free
	exit(1);
}