/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:20:09 by bahn              #+#    #+#             */
/*   Updated: 2021/09/16 14:29:00 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	mouse_button(int button, int x, int y, t_fractol *fractol)
{
        static  int     num = 0;
        int     color;

        if (button == 1)
                printf("Mouse Click(%d) : %dx%d.\n", button, x, y);
        if (button == 4 || button == 5)
        {
                printf("Mouse Wheel(%s) : %dx%d.\n", button == 4 ? "ZOOM IN" : "ZOOM OUT", x, y);
                // fractol->zoom->mouse_x = (double)x / fractol->zoom->pixel - fractol->zoom->w_l_x / 2;
		// fractol->zoom->mouse_y = (double)y / fractol->zoom->pixel - fractol->zoom->w_l_y / 2;
                // if (button == 4)
                // {
                //         fractol->zoom->point_x += fractol->zoom->mouse_x * (1 - 1 / ZOOM);
                //         fractol->zoom->point_y += fractol->zoom->mouse_y * (1 - 1 / ZOOM);
                //         fractol->zoom->pixel *= ZOOM;
                //         fractol->zoom->w_l_x /= ZOOM;
                //         fractol->zoom->w_l_y /= ZOOM;
                // }
                // else if (button == 5)
                // {
                //         fractol->zoom->point_x += -fractol->zoom->mouse_x * (ZOOM - 1);
                //         fractol->zoom->point_y += -fractol->zoom->mouse_y * (ZOOM - 1);
                //         fractol->zoom->pixel /= ZOOM;
                //         fractol->zoom->w_l_x *= ZOOM;
                //         fractol->zoom->w_l_y *= ZOOM;
	        // }

                if (button == 4)
                {
                        fractol->zoom->mag += 0.1;
                        fractol->zoom->center_x += ((2 * x / WIDTH) - 1) / fractol->zoom->mag;
                        fractol->zoom->center_y += (2 * y - HEIGHT) / fractol->zoom->mag / WIDTH;
                }
                else
                {
                        if (fractol->zoom->mag - 0.1 < 0.5)
                                fractol->zoom->mag = 0.5;
                        else
                                fractol->zoom->mag -= 0.1;
                        fractol->zoom->center_x += ((2 * x / WIDTH) - 1) / fractol->zoom->mag;
                        fractol->zoom->center_y += (2 * y - HEIGHT) / fractol->zoom->mag / WIDTH;
                }
                
                printf("Center (x, y) : (%lf, %lf)\n", fractol->zoom->center_x, fractol->zoom->center_y);

                ft_fractol(fractol);
                mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img->img, 0, 0);
        }
        return (0);
}

int	mouse_pos(int x ,int y, t_fractol *fractol)
{
        printf("Mouse moving %d x %d.\n", x, y);
}