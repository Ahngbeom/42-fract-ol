/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:22:00 by bahn              #+#    #+#             */
/*   Updated: 2021/09/27 13:11:17 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	color_map(t_fractol *fractol, int w, int h)
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
                        mlx_pixel_put(fractol->mlx, fractol->win, x, y, color);
                        printf("%d x %d Color : %d\n", x, y, color);
                }
        }
}

int     color_set(int iter)
{
        int     iter_ratio;
	double	r;
	double	g;
	double	b;
	int     color;

        iter_ratio = (double)iter / ITER_MAX;
	r = sin(0.3 * (double)iter);
	g = sin(0.3 * (double)iter + 3) * 63 + 64;
	b = sin(0.3 * (double)iter + 3) * 127 + 128;

	color = create_trgb(0, r, g, b);
	return (color);
}

int	set_bgcolor(t_fractol *fractol, int w, int h, int color)
{
        int	x;
        int	y;

        x = w;
        while (x--)
        {
                y = h;
                while (y--)
                {
                        mlx_pixel_put(fractol->mlx, fractol->win, x, y, color);
                }
        }
}

int	rgb_bitset(int brightness)
{
	int	bit = 0xFFFFFFFF;
	int	power;
	int	count = 16;
	
	while (--count >= brightness)
	{
		power = 0;
		while (power < 32)
		{
			bit = bit - (int)pow(2, power);
			power += 4;
		}
	}
	return(bit);
}
