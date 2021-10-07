/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:22:00 by bahn              #+#    #+#             */
/*   Updated: 2021/10/07 15:32:39 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	color_map(t_fractol *fractol, int w, int h)
{
        int	x;
        int	y;
        int color;
        
        x = w;
        while (x--)
        {
                y = h;
                while (y--)
                {
                        color = (x * 255) / w + ((((w - x) * 255) / w) << 16) + (((y * 255) / h) << 8);
                        mlx_pixel_put(fractol->mlx, fractol->win, x, y, color);
                }
        }
}

int     set_color(int iter, t_color *color)
{
        int	r;
	int	g;
	int	b;
        
        r = (int)(color->start.r - (color->start.r / 16 * fmod(iter, 16.0))) + (int)(color->end.r / 16 * fmod(iter, 16.0));
        g = (int)(color->start.g - (color->start.g / 16 * fmod(iter, 16.0))) + (int)(color->end.g / 16 * fmod(iter, 16.0));
        b = (int)(color->start.b - (color->start.b / 16 * fmod(iter, 16.0))) + (int)(color->end.b / 16 * fmod(iter, 16.0));
	return (r << 16 | g << 8 | b);
}