/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 13:06:24 by bahn              #+#    #+#             */
/*   Updated: 2021/10/13 14:46:12 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	mandelbrot_init(t_fractol *fractol)
{
	fractol->f_fractol_calc = mandelbrot;
	fractol->center.x = -0.5;
	fractol->center.y = 0;
	if (WIDTH >= HEIGHT)
		fractol->pixel = WIDTH / 4;
	else
		fractol->pixel = HEIGHT / 4;
	fractol->complex.x = WIDTH / fractol->pixel;
	fractol->complex.y = HEIGHT / fractol->pixel;
	color_init(fractol, "255 0 0 255 255 0");
}

int	mandelbrot(t_fractol *fractol, int w, int h, int iter)
{
	double	z_x;
	double	z_y;
	double	c_re;
	double	c_im;
	double	temp;

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
