/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 13:06:51 by bahn              #+#    #+#             */
/*   Updated: 2021/10/07 17:08:29 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	julia_init(t_fractol *fractol)
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
	fractol->color.rgb_ptr = NULL;
	fractol->color.start.r = 0;
	fractol->color.start.g = 0;
	fractol->color.start.b = 112;
	fractol->color.end.r = 255;
	fractol->color.end.g = 255;
	fractol->color.end.b = 0;
}

int     julia(t_fractol *fractol, int w, int h, int iter)
{
	double c_re;
	double c_im;
	double z_x;
	double z_y;
	double temp;

	z_x = fractol->center.x + ((double)w / fractol->pixel) - (fractol->complex.x / 2);
	z_y = fractol->center.y + ((double)h / fractol->pixel) - (fractol->complex.y / 2);
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