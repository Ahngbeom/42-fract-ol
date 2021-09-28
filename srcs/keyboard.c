/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:21:08 by bahn              #+#    #+#             */
/*   Updated: 2021/09/28 15:37:05 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	press_key(int key, t_fractol *fractol)
{
        printf("Key Press : %#08X\n", key);
	if (key == 0x00FF1B)
                exit(0);
        else if (key == 0x000072) // R key == Reset
        {
                fractol->center.x = -0.5;
                fractol->center.y = 0;
                // fractol->pixel = WIDTH <= HEIGHT ? WIDTH / 4 : HEIGHT / 4;
                fractol->pixel = WIDTH / 4;
                // fractol->pixel.y = HEIGHT / 2;
                fractol->complex.x = WIDTH / fractol->pixel;
                fractol->complex.y = HEIGHT / fractol->pixel;
                fractol->julia_const.x = -0.1875;
                fractol->julia_const.y = -1.0944;
        }
        else if (key >= LEFT && key <= DOWN)
                move_centroid(key, fractol);
        
        draw_fractol(fractol);
}

void    move_centroid(int key, t_fractol *fractol)
{
        if (key == UP)
                fractol->center.y += 0.1;
        else if (key == DOWN)
                fractol->center.y += -0.1;
        else if (key == LEFT)
                fractol->center.x += -0.1;
        else //(key == RIGHT)
                fractol->center.x += 0.1;
}