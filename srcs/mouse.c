/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:20:09 by bahn              #+#    #+#             */
/*   Updated: 2021/10/06 19:20:25 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	mouse_hook(int key, int x, int y, t_fractol *fractol)
{       
        int cd_x;
        int cd_y;

        if (key == 0x00000001) {
                // printf("Mouse Click (%lf, %lf)\n",  fractol->center.x + ((double)x / fractol->pixel) - (fractol->complex.x / 2), \
                                                        fractol->center.y + ((double)y / fractol->pixel) - (fractol->complex.y / 2));
        }
        else if (key == SCROLL_UP || key == SCROLL_DOWN)
        {
                fractol->mouse.x = (double)x / fractol->pixel - fractol->complex.x / 2;
                fractol->mouse.y = (double)y / fractol->pixel - fractol->complex.y / 2;
                printf("mouse location (%lf, %lf): %lf, %lf\n", (double)x, (double)y, fractol->mouse.x, fractol->mouse.y);
                if (key == SCROLL_UP)
                {
                        fractol->center.x += fractol->mouse.x * (ZOOM - 1.0);
                        fractol->center.y += fractol->mouse.y * (ZOOM - 1.0);
                        fractol->pixel *= ZOOM;
                        fractol->complex.x /= ZOOM;
                        fractol->complex.y /= ZOOM;
                }
                else
                {
                        fractol->center.x -= fractol->mouse.x * (ZOOM - 1.0);
                        fractol->center.y -= fractol->mouse.y * (ZOOM - 1.0);
                        fractol->pixel /= ZOOM;
                        fractol->complex.x *= ZOOM;
                        fractol->complex.y *= ZOOM;
                }
                // printf("Pixel x, y: %lf, %lf, complex (x, y) : (%lf, %lf)\n", fractol->pixel, fractol->pixel, fractol->complex.x, fractol->complex.y);
                printf("Center (x, y) : (%lf, %lf) | Pixel : %lf | Complex (x, y) : (%lf, %lf)\n", \
                        fractol->center.x, fractol->center.y, fractol->pixel, fractol->complex.x, fractol->complex.y);
                draw_fractol(fractol);
        }
        return (0);
}

int	mouse_motion_hook(int x ,int y, t_fractol *fractol)
{
        // printf("Mouse moving %d x %d.\n", x, y);
        if (fractol->f_fractol_calc == &julia) {

                // 가로 세로 길이가 4인 복소평면(-2, -2) ~ (2, 2)에서  
                // fractol->julia_const.x = -2 + ((double)x / (WIDTH / 4));
                // fractol->julia_const.y = -2 + ((double)y / (HEIGHT / 4));

                fractol->julia_const.x = (double)x / fractol->pixel - fractol->complex.x / 2;
                fractol->julia_const.y = -((double)y / fractol->pixel - fractol->complex.y / 2);
                printf("Julia const : (%lf, %lf)\n", fractol->julia_const.x, fractol->julia_const.y);
                draw_fractol(fractol);
        }
        return (0);
}