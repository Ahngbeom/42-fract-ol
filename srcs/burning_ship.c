/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:15:52 by bahn              #+#    #+#             */
/*   Updated: 2021/10/06 18:33:58 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int burning_ship_init(t_fractol *fractol)
{
	fractol->f_fractol_calc = &burning_ship;
	fractol->center.x = -0.5;
	fractol->center.y = -0.5;
	if (WIDTH >= HEIGHT)
		fractol->pixel = WIDTH / 4;
	else
		fractol->pixel = HEIGHT / 4;
	fractol->complex.x = WIDTH / fractol->pixel;
	fractol->complex.y = HEIGHT / fractol->pixel;

	fractol->color.rgb_ptr = NULL;
	fractol->color.start.r = 0;
	fractol->color.start.g = 0;
	fractol->color.start.b = 16;
	fractol->color.end.r = 255;
	fractol->color.end.g = 0;
	fractol->color.end.b = 0;
}

int burning_ship(t_fractol *fractol, int w, int h, int iter)
{
	double c_re;
	double c_im;
	double x;
	double y;
	double temp;

	c_re = fractol->center.x + (((double)w / fractol->pixel) - (fractol->complex.x / 2));
	c_im = fractol->center.y + (((double)h / fractol->pixel) - (fractol->complex.y / 2));
	x = c_re;
	y = c_im;
	while ((pow(x, 2.0) + pow(y, 2.0) <= 4) && (iter < ITER_MAX))
	{
		temp = pow(x, 2.0) - pow(y, 2.0) + c_re;
		y = fabs(2 * x * y) + c_im;
		x = temp;
		iter++;
	}
	return (iter);
}