/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   koch_curve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:03:45 by bahn              #+#    #+#             */
/*   Updated: 2021/10/06 16:27:31 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	koch_curve_init(t_fractol *fractol)
{
	fractol->f_fractol_calc = &koch_curve;

	if (WIDTH >= HEIGHT) {
		fractol->pixel = WIDTH / 8;
	} else {
		fractol->pixel = HEIGHT / 8;
	}
	
	fractol->complex.x = WIDTH / fractol->pixel;
	fractol->complex.y = HEIGHT / fractol->pixel;


	fractol->koch_const.leg = 3;
	fractol->koch_const.vertex_left.x = -(fractol->koch_const.leg / 2);
	fractol->koch_const.vertex_left.y = -(sqrt(3) / 2 * fractol->koch_const.leg / 2);
	fractol->koch_const.vertex_top.x = 0;
	fractol->koch_const.vertex_top.y = sqrt(3) / 2 * fractol->koch_const.leg / 2;
	fractol->koch_const.vertex_right.x = fractol->koch_const.leg / 2;
	fractol->koch_const.vertex_right.y = -(sqrt(3) / 2 * fractol->koch_const.leg / 2);
	

	fractol->center.x = 0;
	fractol->center.y = 0;

	fractol->color.rgb_ptr = NULL;

	fractol->color.start.r = 0;
	fractol->color.start.g = 0;
	fractol->color.start.b = 255;
	fractol->color.end.r = 0;
	fractol->color.end.g = 255;
	fractol->color.end.b = 0;
}

int	koch_curve(t_fractol *fractol, int w, int h, int iter)
{	
	double x;
	double y;

	x = fractol->center.x + (((double)w / fractol->pixel) - (fractol->complex.x / 2));
	y = fractol->center.y + (((double)h / fractol->pixel) - (fractol->complex.y / 2));
	
	if (y >= fractol->koch_const.vertex_left.y && y <= fractol->koch_const.vertex_top.y)
	{
		if (x >= fractol->koch_const.vertex_left.x - (fractol->koch_const.vertex_left.x - fractol->koch_const.vertex_top.x) \
			&& x <= fractol->koch_const.vertex_right.x - (fractol->koch_const.vertex_right.x - fractol->koch_const.vertex_top.x))
		{
			return (1);
		}
	}
	
	return (iter);
}