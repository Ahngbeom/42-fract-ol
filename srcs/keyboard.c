/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:21:08 by bahn              #+#    #+#             */
/*   Updated: 2021/09/30 14:08:47 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	press_key(int key, t_fractol *fractol)
{
        double *rgb_ptr = &fractol->color.r;

        printf("Press Key : %#010X\n", key);
	if (key == ESC_KEY)
                exit(0);
        else if (key == R_KEY) // Reset
        {
                fractol->center.x = 0;
                fractol->center.y = 0;
                // fractol->pixel = WIDTH <= HEIGHT ? WIDTH / 4 : HEIGHT / 4;
                fractol->pixel = WIDTH / 4;
                // fractol->pixel.y = HEIGHT / 2;
                fractol->complex.x = WIDTH / fractol->pixel;
                fractol->complex.y = HEIGHT / fractol->pixel;
                fractol->julia_const.x = -0.1875;
                fractol->julia_const.y = -1.0944;
        }
        else if (key >= LEFT_KEY && key <= DOWN_KEY)
                move_centroid(key, fractol);
        else if ((key >= NUMPAD_4 && key <= NUMPAD_2) || key == NUMPAD_5) {

                if (key == NUMPAD_5) {
                        *fractol->color.rgb_ptr = 0;
                }
                else if (key == NUMPAD_4 || key == NUMPAD_6) 
                {
                        if (key == NUMPAD_4) 
                        {
                                if (*fractol->color.rgb_ptr > 0)
                                        *fractol->color.rgb_ptr -= 0.5;
                        }
                        else {
                                if (*fractol->color.rgb_ptr < 255)
                                        *fractol->color.rgb_ptr += 0.5;
                        }
                }
                else {
                        if (key == NUMPAD_8) 
                        {
                                if (fractol->color.rgb_ptr == &fractol->color.r)
                                        fractol->color.rgb_ptr = &fractol->color.b;
                                else if (fractol->color.rgb_ptr == &fractol->color.g)
                                        fractol->color.rgb_ptr = &fractol->color.r;
                                else 
                                        fractol->color.rgb_ptr = &fractol->color.g;
                        }
                        else {
                                if (fractol->color.rgb_ptr == &fractol->color.r)
                                        fractol->color.rgb_ptr = &fractol->color.g;
                                else if (fractol->color.rgb_ptr == &fractol->color.g)
                                        fractol->color.rgb_ptr = &fractol->color.b;
                                else 
                                        fractol->color.rgb_ptr = &fractol->color.r;
                        }
                        
                        if (fractol->color.rgb_ptr == &fractol->color.r)
                                printf("Select RGB : R\n");
                        else if (fractol->color.rgb_ptr == &fractol->color.g)
                                printf("Select RGB : G\n");
                        else
                                printf("Select RGB : B\n");
                }
        }
        // printf("color : %lf, %lf, %lf\n", fractol->color.r, fractol->color.g, fractol->color.b);
        draw_fractol(fractol);
}

void    move_centroid(int key, t_fractol *fractol)
{
        if (key == UP_KEY)
                fractol->center.y += 0.1;
        else if (key == DOWN_KEY)
                fractol->center.y += -0.1;
        else if (key == LEFT_KEY)
                fractol->center.x += -0.1;
        else //(key == RIGHT_KEY)
                fractol->center.x += 0.1;
}