/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 13:06:51 by bahn              #+#    #+#             */
/*   Updated: 2021/10/13 14:46:09 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	julia_init(t_fractol *fractol)
{
	fractol->f_fractol_calc = julia;
	fractol->center.x = 0;
	fractol->center.y = 0;
	if (WIDTH >= HEIGHT)
		fractol->pixel = WIDTH / 8;
	else
		fractol->pixel = HEIGHT / 8;
	fractol->complex.x = WIDTH / fractol->pixel;
	fractol->complex.y = HEIGHT / fractol->pixel;
	fractol->julia_const.x = -0.1875;
	fractol->julia_const.y = -1.0944;
	color_init(fractol, "0 0 120 255 255 0");
}

int	julia(t_fractol *fractol, int w, int h, int iter)
{
	double	z_x;
	double	z_y;
	double	c_re;
	double	c_im;
	double	temp;

	z_x = fractol->center.x + ((w / fractol->pixel) - (fractol->complex.x / 2));
	z_y = fractol->center.y + ((h / fractol->pixel) - (fractol->complex.y / 2));
	c_re = fractol->julia_const.x;
	c_im = fractol->julia_const.y;
	while ((pow(z_x, 2.0) + pow(z_y, 2.0) <= 4) && (iter < ITER_MAX))
	{
		temp = pow(z_x, 2.0) - pow(z_y, 2.0) + c_re;
		z_y = 2 * z_x * z_y + c_im;
		z_x = temp;
		iter++;
	}
	return (iter);
}
