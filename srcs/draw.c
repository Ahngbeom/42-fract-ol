/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:48:34 by bahn              #+#    #+#             */
/*   Updated: 2021/10/11 12:29:59 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	draw_fractol(t_fractol *fractol)
{
	int	w;
	int	h;
	int	iter;

	w = 0;
	while (w < WIDTH)
	{
		h = 0;
		while (h < HEIGHT)
		{
			iter = fractol->f_fractol_calc(fractol, w, h, 0);
			if (iter == ITER_MAX)
				my_mlx_pixel_put(&fractol->img, w, h, 0x00000000);
			else
				my_mlx_pixel_put(&fractol->img, w, h, \
						set_color(iter, &fractol->color));
			h++;
		}
		w++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
}
