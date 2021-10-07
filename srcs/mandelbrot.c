/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 13:06:24 by bahn              #+#    #+#             */
/*   Updated: 2021/10/07 20:52:12 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int		mandelbrot_init(t_fractol *fractol)
{
	fractol->f_fractol_calc = mandelbrot;
	fractol->center.x = -0.5;
	fractol->center.y = 0;
	fractol->pixel = WIDTH / 4;
	fractol->complex.x = WIDTH / fractol->pixel;
	fractol->complex.y = HEIGHT / fractol->pixel;
	fractol->color.rgb_ptr = NULL;
	fractol->color.start.r = 255;
	fractol->color.start.g = 0;
	fractol->color.start.b = 0;
	fractol->color.end.r = 255;
	fractol->color.end.g = 255;
	fractol->color.end.b = 0;
}

int     mandelbrot(t_fractol *fractol, int w, int h, int iter)
{
	double c_re;
	double c_im;
	double z_x;
	double z_y;
	double temp;

	z_x = fractol->center.x + ((w / fractol->pixel) - (fractol->complex.x / 2));
	z_y = fractol->center.y + ((h / fractol->pixel) - (fractol->complex.y / 2));
	c_re = z_x;
	c_im = z_y;
	while ((pow(z_x, 2.0) + pow(z_y, 2.0) <= 4) && (iter < ITER_MAX))
	{
		temp = z_x;
		z_x = pow(z_x, 2.0) - pow(z_y, 2.0) + c_re;
		z_y = 2 * temp * z_y + c_im;
		iter++;
	}
	return (iter);
}