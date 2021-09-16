/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 14:55:11 by bahn              #+#    #+#             */
/*   Updated: 2021/09/16 14:29:22 by bahn             ###   ########.fr       */
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

	// c_re = (count_w - (WIDTH / 2)) * 3.0 / WIDTH - 0.5;  // 실수부
	// c_im = ((HEIGHT / 2) - count_h) * 2.0 / HEIGHT; // 허수부
        c_re = fractol->zoom->min_y + count_h * fractol->zoom->dy;
        c_im = fractol->zoom->min_x + count_w * fractol->zoom->dx;

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
        int     color = 0xFFFFFF;


        fractol->zoom->min_x = fractol->zoom->center_x - (1 / fractol->zoom->mag);
        fractol->zoom->max_x = fractol->zoom->center_x + (1 / fractol->zoom->mag);
        fractol->zoom->min_y = fractol->zoom->center_y - (fractol->zoom->max_x - fractol->zoom->min_x) * HEIGHT / WIDTH / 2;
        fractol->zoom->max_y = fractol->zoom->center_y + (fractol->zoom->max_x - fractol->zoom->min_x) * HEIGHT / WIDTH / 2;
        fractol->zoom->dx = (fractol->zoom->max_x - fractol->zoom->min_x) / WIDTH;
        fractol->zoom->dy = (fractol->zoom->max_y - fractol->zoom->min_y) / HEIGHT;

        w = 0;
        while (w < WIDTH)
        {
                h = 0;
                while (h < HEIGHT)
                {
                        iter = mandelbrot(fractol, h, w, 0);
                        if (iter < ITER_MAX)
                                my_mlx_pixel_put(fractol->img, w, h, color * ((255 / ITER_MAX) * iter));
                        else
                                my_mlx_pixel_put(fractol->img, w, h, 0x000000);
                        h++;
                }
                w++;
        }
}

int     main(void)
{
        t_fractol  fractol;
        t_myimg           img;
        t_zoom          zoom;
        
        fractol.mlx = mlx_init();
        fractol.win = mlx_new_window(fractol.mlx, WIDTH, HEIGHT, "bahn's fract-ol!");
        
        img.img = mlx_new_image(fractol.mlx, WIDTH, HEIGHT);
        img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
        fractol.img = &img;

        zoom.mag = 0.5;
        zoom.center_x = 0;
        zoom.center_y = 0;
        // zoom.pixel = (WIDTH < HEIGHT ? WIDTH : HEIGHT) / 4;
        // zoom.w_l_x = WIDTH / zoom.pixel;
        // zoom.w_l_y = HEIGHT / zoom.pixel;
        fractol.zoom = &zoom;

        mlx_key_hook(fractol.win, press_key, &fractol);
        mlx_mouse_hook(fractol.win, mouse_button, &fractol);
        // mlx_hook(vars.win, MotionNotify, PointerMotionMask, mouse_pos, &vars);
        // color_map(&fractol, WIDTH, HEIGHT);

        // mandelbrot_init(&fractol);
        ft_fractol(&fractol);
        mlx_put_image_to_window(fractol.mlx, fractol.win, img.img, 0, 0);
        
        mlx_loop(fractol.mlx);
}