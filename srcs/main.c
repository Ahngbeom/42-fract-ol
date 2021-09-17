/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 14:55:11 by bahn              #+#    #+#             */
/*   Updated: 2021/09/17 16:26:10 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void  my_mlx_pixel_put(t_myimg *img, int x, int y, int color)
{
        char    *dst;

        dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
        *(unsigned int*)dst = color;
}

int     mandelbrot(t_fractol *fractol, int count_w, int count_h, int iter)
{
	double c_re;
	double c_im;
	double x;
	double y;
	double temp;

        c_re = fractol->zoom->min_x + count_w * fractol->zoom->dx;
        c_im = fractol->zoom->min_y + count_h * fractol->zoom->dy;
        // printf("c_re : %lf, c_im :%lf\n", c_re, c_im);
        
	x = 0;
	y = 0;
	while ((pow(x, 2.0) + pow(y, 2.0) <= 4) && (iter < ITER_MAX))
	{
		temp = pow(x, 2.0) - pow(y, 2.0) + c_re;
		y = 2 * x * y + c_im;
		x = temp;
		iter++;
	}
	return (iter);
}

int     julia(t_fractol *fractol, int count_w, int count_h, int iter)
{
	double c_re;
	double c_im;
	double x;
	double y;
	double temp;

        c_re = fractol->zoom->min_x + count_w * fractol->zoom->dx;
        c_im = fractol->zoom->min_y + count_h * fractol->zoom->dy;
        // printf("c_re : %lf, c_im :%lf\n", c_re, c_im);
        
	x = 0;
	y = 0;
	while ((pow(x, 2.0) + pow(y, 2.0) <= 4) && (iter < ITER_MAX))
	{
		temp = pow(x, 2.0) - pow(y, 2.0) + c_re;
		y = 2 * x * y + c_im;
		x = temp;
		iter++;
	}
	return (iter);
}

void    ft_fractol(t_fractol *fractol)
{
        int w;
        int h;
        int iter;
        static int     color = 0xFFFFFFFF;


        fractol->zoom->min_x = fractol->zoom->center_x - (1 / fractol->zoom->mag);
        fractol->zoom->max_x = fractol->zoom->center_x + (1 / fractol->zoom->mag);
        fractol->zoom->min_y = fractol->zoom->center_y - (fractol->zoom->max_x - fractol->zoom->min_x) * HEIGHT / WIDTH / 2;
        fractol->zoom->max_y = fractol->zoom->center_y + (fractol->zoom->max_x - fractol->zoom->min_x) * HEIGHT / WIDTH / 2;
        fractol->zoom->dx = (fractol->zoom->max_x - fractol->zoom->min_x) / WIDTH;
        fractol->zoom->dy = (fractol->zoom->max_y - fractol->zoom->min_y) / HEIGHT;

        // printf("center_x : %lf\n", fractol->zoom->center_x);
        // printf("center_y : %lf\n", fractol->zoom->center_y);
        // printf("min_x : %lf\n", fractol->zoom->min_x);
        // printf("max_x : %lf\n", fractol->zoom->max_x);
        // printf("min_y : %lf\n", fractol->zoom->min_y);
        // printf("max_y : %lf\n", fractol->zoom->max_y);
        // printf("dx : %lf\n", fractol->zoom->dx);
        // printf("dy : %lf\n", fractol->zoom->dy);
        w = 0;
        while (w < WIDTH)
        {
                h = 0;
                while (h < HEIGHT)
                {
                        // iter = mandelbrot(fractol, w, h, 0);
                        iter = julia(fractol, w, h, 0);
                        if (iter < ITER_MAX)
                        {
                                // color = rgb_bitset(iter / 16);
                                // my_mlx_pixel_put(fractol->img, w, h, color);
                                my_mlx_pixel_put(fractol->img, w, h, color_set(iter));
                        }
                        else
                                my_mlx_pixel_put(fractol->img, w, h, 0x00000000);
                        h++;
                }
                w++;
        }
        mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img->img, 0, 0);
}

int     main(void)
{
        t_fractol  fractol;
        t_myimg           img;
        t_zoom          zoom;
        
        fractol.mlx = mlx_init();
        fractol.win = mlx_new_window(fractol.mlx, WIDTH, HEIGHT, "bahn's fract-ol");
        // fractol.win = mlx_new_window(fractol.mlx, WIDTH, HEIGHT, "bahn's fract-ol - [Mandelbrot]");
        // fractol.win = mlx_new_window(fractol.mlx, WIDTH, HEIGHT, "bahn's fract-ol - [Julia]");

        img.img = mlx_new_image(fractol.mlx, WIDTH, HEIGHT);
        img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
        fractol.img = &img;

        zoom.mag = 0.5;
        zoom.center_x = 0.0;
        zoom.center_y = 0.0;
        fractol.zoom = &zoom;

        mlx_key_hook(fractol.win, press_key, &fractol);
        mlx_mouse_hook(fractol.win, mouse_button, &fractol);
        // mlx_hook(fractol.win, MotionNotify, PointerMotionMask, mouse_pos, &fractol);
        // color_map(&fractol, WIDTH, HEIGHT);

        ft_fractol(&fractol);
        
        mlx_loop(fractol.mlx);
}