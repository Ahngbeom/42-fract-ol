/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:20:09 by bahn              #+#    #+#             */
/*   Updated: 2021/09/17 16:09:29 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	mouse_button(int button, int x, int y, t_fractol *fractol)
{
        static  int     num = 0;
        int     color;

        // if (button == 1)
        // {
        //         // printf("Mouse Click(%d) : %dx%d.\n", button, x, y);

        //         fractol->zoom->center_x = ((2.0 * (double)x / (double)WIDTH) - 1.0) / fractol->zoom->mag;
        //         fractol->zoom->center_y = (2.0 * (double)y - (double)HEIGHT) / fractol->zoom->mag / (double)WIDTH;
        //         ft_fractol(fractol);
        // }       
        if (button == 4 || button == 5)
        {
                if (button == 4)
                {
                        fractol->zoom->mag += 10.0;
                        fractol->zoom->center_x += ((2.0 * (double)x / WIDTH) - 1.0) / fractol->zoom->mag;
                        fractol->zoom->center_y += (2.0 * (double)y - HEIGHT) / fractol->zoom->mag / WIDTH;
                }
                else
                {
                        if (fractol->zoom->mag < 0.5 + 0.1)
                                fractol->zoom->mag = 0.5;
                        else
                                fractol->zoom->mag -= 10.0;
                        fractol->zoom->center_x += ((2.0 * (double)x / WIDTH) - 1.0) / fractol->zoom->mag;
                        fractol->zoom->center_y += (2.0 * (double)y - HEIGHT) / fractol->zoom->mag / WIDTH;
                }
                
                ft_fractol(fractol);
                mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img->img, 0, 0);
                
        }
        // printf("Center (x, y) : (%lf, %lf)\n", fractol->zoom->center_x, fractol->zoom->center_y);

        return (0);
}

int	mouse_pos(int x ,int y, t_fractol *fractol)
{
        // printf("Mouse moving %d x %d.\n", x, y);
        fractol->zoom->center_x = ((2.0 * (double)x / (double)WIDTH) - 1.0) / fractol->zoom->mag;
        fractol->zoom->center_y = (2.0 * (double)y - (double)HEIGHT) / fractol->zoom->mag / (double)WIDTH;
        // printf("Center (x, y) : (%lf, %lf)\n", fractol->zoom->center_x, fractol->zoom->center_y);
        ft_fractol(fractol);
}