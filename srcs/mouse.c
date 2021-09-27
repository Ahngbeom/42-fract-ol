/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:20:09 by bahn              #+#    #+#             */
/*   Updated: 2021/09/27 23:13:56 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	mouse_hook(int key, int x, int y, t_fractol *fractol)
{
        static  int     num = 0;
        int     color;

        if (key == 4 || key == 5)
        {
                fractol->mouse.x = (double)x / fractol->pixel - fractol->w_l.x / 2;
                fractol->mouse.y = (double)y / fractol->pixel - fractol->w_l.y / 2;
                if (key == 4)
                {
                        fractol->center.x += fractol->mouse.x * (1 - 1 / ZOOM);
                        fractol->center.y += fractol->mouse.y * (1 - 1 / ZOOM);
                        fractol->pixel *= ZOOM;
                        fractol->w_l.x /= ZOOM;
                        fractol->w_l.y /= ZOOM;
                }
                else
                {
                        fractol->center.x += -fractol->mouse.x * (ZOOM - 1);
                        fractol->center.y += -fractol->mouse.y * (ZOOM - 1);
                        fractol->pixel /= ZOOM;
                        fractol->w_l.x *= ZOOM;
                        fractol->w_l.y *= ZOOM;
                }
                printf("Pixel : %lf, w_l (x, y) : (%lf, %lf)\n", fractol->pixel, fractol->w_l.x, fractol->w_l.y);
                draw_fractol(fractol);
                mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
        }
        return (0);
}

int	mouse_motion_hook(int x ,int y, t_fractol *fractol)
{
        // printf("Mouse moving %d x %d.\n", x, y);
        // 사분면?
        if (fractol->type == 1) {
                if (x > WIDTH / 2 && y > HEIGHT) {
                        fractol->julia_const.x = -2 + ((double)x / (WIDTH / 4));
                        fractol->julia_const.y = -2 + ((double)x / (HEIGHT / 4));
                } 
                else if (x < WIDTH / 2 && y > HEIGHT) {
                        fractol->julia_const.x = -2 + ((double)x / (WIDTH / 4));
                        fractol->julia_const.y = -2 + ((double)y / (HEIGHT / 4));
                }
                else if (x < WIDTH / 2 && y > HEIGHT) {
                        fractol->julia_const.x = -2 + ((double)x / (WIDTH / 4));
                        fractol->julia_const.y = -2 + ((double)y / (HEIGHT / 4));
                }
                else {
                        fractol->julia_const.x = -2 + ((double)x / (WIDTH / 4));
                        fractol->julia_const.y = -2 + ((double)y / (HEIGHT / 4));
                }
                // printf("Julia const : (%lf, %lf)\n", fractol->julia_const.x, fractol->julia_const.y);
                draw_fractol(fractol);
                mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
        }
        return (0);
}