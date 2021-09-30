/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 14:55:11 by bahn              #+#    #+#             */
/*   Updated: 2021/09/30 15:47:09 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void  my_mlx_pixel_put(t_myimg *img, int x, int y, int color)
{
        char    *dst;

        dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
        *(unsigned int*)dst = color;
}

void    auto_coloring(t_fractol *fractol) {
        double max = *fractol->color.rgb_ptr;
        int i = 0;
        double j = 0;
        while (i < 3) {
                j = 0;
                while (j < 15) {
                        if (fractol->color.rgb_ptr == &fractol->color.r) {
                                fractol->color.g = (double)j;
                                j += 0.5;
                        } else if (fractol->color.rgb_ptr == &fractol->color.g) {
                                // fractol->color.g -= (double)j / 10;
                                fractol->color.b = (double)j;
                                j += 0.5;
                        } else {
                                fractol->color.r = (double)j;
                                j += 0.5;
                        }
                        draw_fractol(fractol);
                        
                }
                if (fractol->color.rgb_ptr == &fractol->color.r) {
                        fractol->color.rgb_ptr = &fractol->color.g;
                        fractol->color.r = 0;
                        fractol->color.g = 255;
                        fractol->color.b = 0;
                } else if (fractol->color.rgb_ptr == &fractol->color.g) {
                        fractol->color.rgb_ptr = &fractol->color.b;
                        fractol->color.r = 0;
                        fractol->color.g = 0;
                        fractol->color.b = 255;
                } else {
                        fractol->color.rgb_ptr = &fractol->color.r;
                        fractol->color.r = 255;
                        fractol->color.g = 0;
                        fractol->color.b = 0;
                }
                i++;
                if (i == 3) 
                        i = 0;
        }
}

void    auto_zoomin(t_fractol *fractol)
{       
        double x = 560.0;
        double y = 300.0;

        while (1){
                fractol->mouse.x = x / fractol->pixel - fractol->complex.x / 2;
                fractol->mouse.y = y / fractol->pixel - fractol->complex.y / 2;
                fractol->center.x += fractol->mouse.x * (ZOOM - 1.0);
                fractol->center.y += fractol->mouse.y * (ZOOM - 1.0);
                fractol->pixel *= ZOOM;
                fractol->complex.x /= ZOOM;
                fractol->complex.y /= ZOOM;
                draw_fractol(fractol);
                x -= 1.80;
                y += 0.55;
        }
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
        // auto_coloring(&fractol);
        // auto_zoomin(&fractol);
        
        // printf("Pixel x, y : %lf, %lf, complex.x : (%lf, %lf)\n", fractol.pixel, fractol.pixel, fractol.complex.x, fractol.complex.y);
        mlx_loop(fractol.mlx);
}