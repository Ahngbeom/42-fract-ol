/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:13:57 by bahn              #+#    #+#             */
/*   Updated: 2021/10/07 16:52:09 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int     fractol_init(t_fractol *fractol, char **argv)
{
        fractol->mlx = mlx_init();
        fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, "bahn's fract-ol");
        fractol->img.img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
        fractol->img.addr = mlx_get_data_addr(fractol->img.img, &fractol->img.bits_per_pixel, \
                                                &fractol->img.line_length, &fractol->img.endian);
        if (fractol->mlx == NULL || fractol->win == NULL || fractol->img.img == NULL || fractol->img.addr == NULL)
                ft_exception_exit("MiniLibX Initialization Error", NULL);
        
        if (ft_strncmp(argv[1], "Mandelbrot", ft_strlen("Mandelbrot")) == 0)
                fractol->f_fractol_init = mandelbrot_init;
        else if (ft_strncmp(argv[1], "Julia", ft_strlen("Julia")) == 0)
                fractol->f_fractol_init = julia_init;
        else if (ft_strncmp(argv[1], "Burning ship", ft_strlen("Burning ship")) == 0)
                fractol->f_fractol_init = burning_ship_init;
        else
                ft_exception_exit("Fractol Type Error", "\e[92m[Mandelbrot] [Julia] [Burning ship]\e[0m");
        fractol->f_fractol_init(fractol);
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
                        iter = fractol->f_fractol_calc(fractol, w, h, 0);
                        if (iter == ITER_MAX)
                                my_mlx_pixel_put(&fractol->img, w, h, 0x00000000);
                        else
                                my_mlx_pixel_put(&fractol->img, w, h, set_color(iter, &fractol->color));
                        h++;
                }
                w++;
        }
        mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
}