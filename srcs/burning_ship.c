/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:15:52 by bahn              #+#    #+#             */
/*   Updated: 2021/10/08 22:23:38 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	burning_ship_init(t_fractol *fractol)
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
	color_init(fractol, fractol->color->start, 0, 0, 16);
	color_init(fractol, fractol->color->end, 255, 0, 0);
	// printf("start r addr : %i\n", fractol->color->start);
	// printf("start g addr : %i\n", fractol->color->start->next);
	// printf("start b addr : %i\n", fractol->color->start->next->next);
	// printf("start r addr : %i\n", fractol->color->end->prev->prev->prev);
	// printf("start g addr : %i\n", fractol->color->end->prev->prev);
	// printf("start b addr : %i\n", fractol->color->end->prev);
	// printf("end r addr : %i\n", fractol->color->end);
	// printf("end g addr : %i\n", fractol->color->end->next);
	// printf("end b addr : %i\n", fractol->color->end->next->next);
	// printf("end r addr : %i\n", fractol->color->start->next->next->next);
	// printf("end g addr : %i\n", fractol->color->start->next->next->next->next);
	// printf("end b addr : %i\n", fractol->color->start->next->next->next->next->next);
}

int	burning_ship(t_fractol *fractol, int w, int h, int iter)
{
	double	c_re;
	double	c_im;
	double	x;
	double	y;
	double	temp;

	c_re = fractol->center.x + \
					((w / fractol->pixel) - (fractol->complex.x / 2));
	c_im = fractol->center.y + \
					((h / fractol->pixel) - (fractol->complex.y / 2));
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
