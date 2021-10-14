/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:15:52 by bahn              #+#    #+#             */
/*   Updated: 2021/10/14 10:56:04 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	burning_ship_init(t_fractol *fractol)
{
	fractol->f_fractol_calc = burning_ship;
	fractol->center.x = -0.5;
	fractol->center.y = -0.5;
	if (WIDTH >= HEIGHT)
		fractol->pixel = WIDTH / 4;
	else
		fractol->pixel = HEIGHT / 4;
	fractol->complex.x = WIDTH / fractol->pixel;
	fractol->complex.y = HEIGHT / fractol->pixel;
	color_init(fractol, "0 0 15 255 0 0");
}

int	burning_ship(t_fractol *fractol, int w, int h, int iter)
{
	double	z_x;
	double	z_y;
	double	c_re;
	double	c_im;
	double	temp;

	c_re = fractol->center.x + (w / fractol->pixel) - (fractol->complex.x / 2);
	c_im = fractol->center.y + (h / fractol->pixel) - (fractol->complex.y / 2);
	z_x = c_re;
	z_y = c_im;
	while ((pow(z_x, 2.0) + pow(z_y, 2.0) <= 4) && (iter < ITER_MAX))
	{
		temp = pow(z_x, 2.0) - pow(z_y, 2.0) + c_re;
		z_y = fabs(2 * z_x * z_y) + c_im;
		z_x = temp;
		iter++;
	}
	return (iter);
}
