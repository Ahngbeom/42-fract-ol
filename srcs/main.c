/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 14:55:11 by bahn              #+#    #+#             */
/*   Updated: 2021/09/28 20:42:59 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void  my_mlx_pixel_put(t_myimg *img, int x, int y, int color)
{
        char    *dst;

        dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
        *(unsigned int*)dst = color;
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
                        if (fractol->type == 0)
                                iter = mandelbrot(fractol, w, h, 0);
                        else if (fractol->type == 1)
                                iter = julia(fractol, w, h, 0);
                        
                        if (iter < ITER_MAX)
                                my_mlx_pixel_put(&fractol->img, w, h, color_set(iter));
                        else
                                my_mlx_pixel_put(&fractol->img, w, h, 0x00000000);
                        h++;
                }
                w++;
        }
        mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
        // ft_putendl_fd("Put Color : SUCCESS", 1);
}

int     fractol_init(t_fractol *fractol, char **argv) {
        if (ft_strncmp(argv[1], "Mandelbrot", ft_strlen(argv[1])) == 0)
                fractol->type = 0;
        else if (ft_strncmp(argv[1], "Julia", ft_strlen(argv[1])) == 0)
                fractol->type = 1;
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
        if (fractol->type == 1)
                fractol->pixel /= 2;
        fractol->complex.x = WIDTH / fractol->pixel;
        fractol->complex.y = HEIGHT / fractol->pixel;
        /////////////////////////////////////////////////////////////////////
        fractol->julia_const.x = -0.1875;
        fractol->julia_const.y = -1.0944;
        return (0);
}

int     main(int argc, char **argv)
{
        t_fractol  fractol;
        
        if (argc != 2)
        {
                ft_putendl_fd("Please enter the Fractol Type", 1);
                ft_putendl_fd(">>> [Mandelbrot] [Julia]", 1);
                exit(1);
        } else
                fractol_init(&fractol, argv);
        
        mlx_key_hook(fractol.win, press_key, &fractol);
        mlx_mouse_hook(fractol.win, mouse_hook, &fractol);
        mlx_hook(fractol.win, 6, (1L<<6), mouse_motion_hook, &fractol);
        // color_map(&fractol, WIDTH, HEIGHT);

        draw_fractol(&fractol);
        printf("Pixel x, y : %lf, %lf, complex.x : (%lf, %lf)\n", fractol.pixel, fractol.pixel, fractol.complex.x, fractol.complex.y);
        // int iter = 0;
        // while (iter <= ITER_MAX) {
        //         printf("Color (iter : %d): %#010X\n", iter, color_set(iter));
        //         printf("R : %#010X, %lf\n", (int)(sin(0.3 * (double)iter)) << 16, sin(0.3 * (double)iter));
        //         printf("G : %#010X, %lf\n", (int)(sin(0.3 * (double)iter + 3) * 127 + 128) << 8, \
        //                                                 sin(0.3 * (double)iter + 3));
        //         printf("B : %#010X, %lf\n", (int)(sin(0.3 * (double)iter + 1.5) * 127 + 128), \
        //                                                 sin(0.3 * (double)iter + 3));
        //         iter++;
        // }

        mlx_loop(fractol.mlx);
}