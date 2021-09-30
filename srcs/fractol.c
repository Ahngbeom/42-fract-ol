/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:13:57 by bahn              #+#    #+#             */
/*   Updated: 2021/09/30 18:21:57 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int     fractol_init(t_fractol *fractol, char **argv)
{
        if (ft_strncmp(argv[1], "Mandelbrot", ft_strlen(argv[1])) == 0)
                fractol->f_calc_fractol = &mandelbrot;
        else if (ft_strncmp(argv[1], "Julia", ft_strlen(argv[1])) == 0)
				fractol->f_calc_fractol = &julia;

        else {
                ft_putendl_fd("Fractol Type Error", 1);
                exit(1);
        }

        fractol->mlx = mlx_init();
        fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, "bahn's fract-ol");
        
        fractol->img.img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
        fractol->img.addr = mlx_get_data_addr(fractol->img.img, &fractol->img.bits_per_pixel, \
                                                &fractol->img.line_length, &fractol->img.endian);
        
        if (fractol->mlx == NULL || fractol->win == NULL || fractol->img.img == NULL || fractol->img.addr == NULL)
        {
                ft_putendl_fd("mlx error", 1);
		exit(1);
        }
        
        fractol->center.x = 0;
        fractol->center.y = 0;
        /////////////////////////////////////////////////////////////////////
        fractol->pixel = WIDTH >= HEIGHT ? WIDTH / 4 : HEIGHT / 4;
        // fractol->pixel.y = HEIGHT / 2 - (HEIGHT / 2 % (int)fractol->pixel.x);
        if (fractol->f_calc_fractol == &julia)
                fractol->pixel /= 2;
        fractol->complex.x = WIDTH / fractol->pixel;
        fractol->complex.y = HEIGHT / fractol->pixel;
        /////////////////////////////////////////////////////////////////////
		
        fractol->julia_const.x = -0.1875;
        fractol->julia_const.y = -1.0944;

        fractol->color.rgb_ptr = &fractol->color.r;
        fractol->color.r = 255;
        fractol->color.g = 15;
        fractol->color.b = 0;

		fractol->non_diverges.max_iter = 0;
        return (0);
}

void    draw_fractol(t_fractol *fractol)
{
        int w;
        int h;
        int iter;
       
        w = 0;
        while (w < WIDTH)
        {
                h = 0;
                while (h < HEIGHT)
                {
                        // if (fractol->type == 0)
                        //         iter = mandelbrot(fractol, w, h, 0);
                        // else if (fractol->type == 1)
                        //         iter = julia(fractol, w, h, 0);
                        iter = fractol->f_calc_fractol(fractol, w, h, 0);
                        if (iter == ITER_MAX)
                                my_mlx_pixel_put(&fractol->img, w, h, 0x00000000);
                        // else if (iter < ITER_MAX && iter > 0)
                        //         // my_mlx_pixel_put(&fractol->img, w, h, set_color(iter));
                        //         my_mlx_pixel_put(&fractol->img, w, h, set_flexible_color(iter, &fractol->color));
                        //         // my_mlx_pixel_put(&fractol->img, w, h, set_mapcolor(iter));
                        //         // my_mlx_pixel_put(&fractol->img, w, h, 0xFFFFFFFF);
                        else
                                my_mlx_pixel_put(&fractol->img, w, h, set_flexible_color(iter, &fractol->color));
                        h++;
                }
                w++;
        }
        mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
        // ft_putendl_fd("Put Color : SUCCESS", 1);
}