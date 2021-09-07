/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:22:00 by bahn              #+#    #+#             */
/*   Updated: 2021/09/07 16:22:12 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	color_map(t_vars *vars, int w, int h)
{
        int	x;
        int	y;
        int	color;

        x = w;
        while (x--)
        {
                y = h;
                while (y--)
                {
                        color = (x * 255) / w + ((((w - x) * 255) / w) << 16) + (((y * 255) / h) << 8);
                        mlx_pixel_put(vars->mlx, vars->win, x, y, color);
                        printf("%d x %d Color : %d\n", x, y, color);
                }
        }
}

int	set_bgcolor(t_vars *vars, int w, int h, int color)
{
        int	x;
        int	y;

        x = w;
        while (x--)
        {
                y = h;
                while (y--)
                {
                        mlx_pixel_put(vars->mlx, vars->win, x, y, color);
                }
        }
}