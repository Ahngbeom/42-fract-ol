/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 14:55:11 by bahn              #+#    #+#             */
/*   Updated: 2021/09/08 00:38:06 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void  my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
        char    *dst;

        dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
        *(unsigned int*)dst = color;
}

int     mandelbrot(int count_w, int count_h, int iter)
{
	double c_re;
	double c_im;
	double x;
	double x_new;
	double y;

	c_re = ((count_w - WIDTH / 2) * 3.0 / WIDTH) - 0.5;
	c_im = ((HEIGHT / 2) - count_h) * 2.0 / HEIGHT;
	x = 0;
	y = 0;
	while ((pow(x, 2.0) + pow(y, 2.0) < 4) && (iter < ITER_MAX))
	{
		x_new = pow(x, 2.0) - pow(y, 2.0) + c_re;
		y = 2 * x * y + c_im;
		x = x_new;
		iter++;
	}
	return (iter);
}

void    mandelbrot_init(t_vars *vars)
{
        int     iter;
        int     w;
        int     h;
        int     color;
        int     power;
        int     count;

        h = 0;
        while (h++ <= HEIGHT)
        {
                w = 0;
                while (w++ <= WIDTH)
                {
                        color = 0xFFFFFFF;
                        iter = mandelbrot(w, h, 0);
                        if (iter < ITER_MAX)
                        {
                                count = ITER_MAX / 16;
                                while (iter)
                                {
                                        power = 0;
                                        while (power < 32)
                                        {
                                                color = color - (int)pow(2, power);
                                                power += 4;
                                        }
                                        iter /= count;
                                }
                                my_mlx_pixel_put(vars->img, w, h, color);
                        }
                        else
                        {
                                my_mlx_pixel_put(vars->img, w, h, 0x00000000);
                        }
                }
        }
}

int     main(void)
{
        t_vars  vars;
        t_data  data;
        int     i;
        int     j;
        int     k;

        vars.mlx = mlx_init();
        vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "bahn's MiniLibX!");
        vars.img = &data;
        data.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
        data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
        
        mlx_key_hook(vars.win, press_key, &vars);
        mlx_mouse_hook(vars.win, mouse_button, &vars);
        // mlx_hook(vars.win, MotionNotify, PointerMotionMask, mouse_pos, &vars);
        // color_map(&vars, 800, 600);

        mandelbrot_init(&vars);
        mlx_put_image_to_window(vars.mlx, vars.win, data.img, 0, 0);
        mlx_loop(vars.mlx);
}