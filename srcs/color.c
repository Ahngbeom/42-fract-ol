/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:22:00 by bahn              #+#    #+#             */
/*   Updated: 2021/09/30 14:08:57 by bahn             ###   ########.fr       */
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
                        // printf("%d x %d Color : %d\n", x, y, color);
                }
        }
}

int     set_flexible_color(int iter, t_color *color)
{
        double	r;
	double	g;
	double	b;

        r = fmod(iter, 16.0) * color->r + color->r;
        g = fmod(iter, 16.0) * color->g + color->g;
        b = fmod(iter, 16.0) * color->b + color->b;
	return (create_trgb(0, r, g, b));
}   

int     set_color(int iter)
{
        int     iter_ratio;
	double	r;
	double	g;
	double	b;
	int     color;

        iter_ratio = (double)iter / ITER_MAX;
	// r = sin(0.3 * (double)iter);
	// g = sin(0.3 * (double)iter + 3) * 63 + 64;
	// b = sin(0.3 * (double)iter + 3) * 127 + 128;

        // r = fmod(ITER_MAX, iter) * 127.5 + 127.5;
        // g = fmod(ITER_MAX, iter) * 127.5 + 127.5;
        // b = fmod(ITER_MAX, iter) * 127.5 + 127.5;
        r = fmod(iter, 16.0);
        g = (fmod(iter, 16.0) + 3);
        b = (fmod(iter, 16.0) + 3) * 60 + 60;
	color = create_trgb(0, r, g, b);
        // printf("color : %#X, %#X, %#X\n", r, g, b);
	return (color);
}

int     set_mapcolor(int iter)
{
        int i = iter % 16;
        int color = 0;

        switch (i)
        {
        case 0:
                color = create_trgb(0, 66, 30, 15);
                break;
        case 1:
                color = create_trgb(0, 25, 7, 26);
                break;
        case 2:
                color = create_trgb(0, 9, 1, 47);
                break;
        case 3:
                color = create_trgb(0, 4, 4, 73);
                break;
        case 4:
                color = create_trgb(0, 0, 7, 100);
                break;
        case 5:
                color = create_trgb(0, 12, 44, 138);
                break;
        case 6:
                color = create_trgb(0, 24, 82, 177);
                break;
        case 7:
                color = create_trgb(0, 57, 125, 209);
                break;
        case 8:
                color = create_trgb(0, 134, 181, 229);
                break;
        case 9:
                color = create_trgb(0, 211, 236, 248);
                break;
        case 10:
                color = create_trgb(0, 241, 233, 191);
                break;
        case 11:
                color = create_trgb(0, 248, 201, 95);
                break;
        case 12:
                color = create_trgb(0, 255, 170, 0);
                break;
        case 13:
                color = create_trgb(0, 204, 128, 0);
                break;
        case 14:
                color = create_trgb(0, 153, 87, 0);
                break;
        case 15:
                color = create_trgb(0, 106, 52, 3);
                break;
        default:
                color = create_trgb(0, 0, 0, 0);
                break;
        }
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
