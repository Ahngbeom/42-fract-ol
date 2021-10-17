/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:20:09 by bahn              #+#    #+#             */
/*   Updated: 2021/10/17 17:14:38 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	mouse_hook(int key, int x, int y, t_fractol *fractol)
{
	if (key == SCROLL_UP || key == SCROLL_DOWN)
	{
		fractol->mouse.x = x / fractol->pixel - fractol->complex.x / 2;
		fractol->mouse.y = -(y / fractol->pixel - fractol->complex.y / 2);
		if (key == SCROLL_UP)
		{
			fractol->center.x += fractol->mouse.x * (ZOOM - 1.0);
			fractol->center.y -= fractol->mouse.y * (ZOOM - 1.0);
			fractol->pixel *= ZOOM;
			fractol->complex.x /= ZOOM;
			fractol->complex.y /= ZOOM;
		}
		else
		{
			fractol->center.x -= fractol->mouse.x * (ZOOM - 1.0);
			fractol->center.y += fractol->mouse.y * (ZOOM - 1.0);
			fractol->pixel /= ZOOM;
			fractol->complex.x *= ZOOM;
			fractol->complex.y *= ZOOM;
		}
		draw_fractol(fractol);
	}
	return (0);
}

int	mouse_motion_hook(int x, int y, t_fractol *fractol)
{
	if (fractol->f_fractol_calc == julia)
	{
		fractol->julia_const.x = x / fractol->pixel - fractol->complex.x / 2;
		fractol->julia_const.y = -(y / fractol->pixel - fractol->complex.y / 2);
		draw_fractol(fractol);
	}
	return (0);
}
