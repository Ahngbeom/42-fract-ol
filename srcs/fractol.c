/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:13:57 by bahn              #+#    #+#             */
/*   Updated: 2021/09/27 20:10:48 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int     mandelbrot(t_fractol *fractol, int w, int h, int iter)
{
	double c_re;
	double c_im;
	double x;
	double y;
	double temp;

	c_re = fractol->center.x + ((double)w / fractol->pixel) - (fractol->w_l.x / 2);
	c_im = fractol->center.y + ((double)h / fractol->pixel) - (fractol->w_l.y / 2);
        
	x = c_re;
	y = c_im;
	while ((pow(x, 2.0) + pow(y, 2.0) <= 4) && (iter < ITER_MAX))
	{
		temp = pow(x, 2.0) - pow(y, 2.0) + c_re;
		y = 2 * x * y + c_im;
		x = temp;
		iter++;
	}
	return (iter);
}

int     julia(t_fractol *fractol, int w, int h, int iter)
{
	double c_re;
	double c_im;
	double x;
	double y;
	double temp;

	c_re = fractol->julia_const.x;
	c_im = fractol->julia_const.y;
        
	x = fractol->center.x + ((double)w / fractol->pixel) - (fractol->w_l.x / 2);
	y = fractol->center.y + ((double)h / fractol->pixel) - (fractol->w_l.y / 2);
	while ((pow(x, 2.0) + pow(y, 2.0) <= 4) && (iter < ITER_MAX))
	{
		temp = pow(x, 2.0) - pow(y, 2.0) + c_re;
		y = 2 * x * y + c_im;
		x = temp;
		iter++;
	}
	return (iter);
}