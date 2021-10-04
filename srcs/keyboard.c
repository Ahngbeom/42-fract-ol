/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:21:08 by bahn              #+#    #+#             */
/*   Updated: 2021/10/05 01:38:09 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	press_key(int key, t_fractol *fractol)
{
        // double *rgb_ptr = &fractol->color.r;
        char *buff[100];
        char *rgb;
        int     i = 0;
        int     *ptr;
        printf("Press Key : %#010X\n", key);
	if (key == ESC_KEY)
                exit(0);
        else if (key == R_KEY) // Reset
        {
                fractol->center.x = 0;
                fractol->center.y = 0;
                // fractol->pixel = WIDTH <= HEIGHT ? WIDTH / 4 : HEIGHT / 4;
                fractol->pixel = WIDTH / 4;
                if (fractol->f_calc_fractol == &julia)
                        fractol->pixel /= 2;
                // fractol->pixel.y = HEIGHT / 2;
                fractol->complex.x = WIDTH / fractol->pixel;
                fractol->complex.y = HEIGHT / fractol->pixel;
                fractol->julia_const.x = -0.1875;
                fractol->julia_const.y = -1.0944;
        }
        else if (key >= LEFT_KEY && key <= DOWN_KEY)
                move_centroid(key, fractol);
        else if (key == NUMPAD_2 || key == NUMPAD_4 || key == NUMPAD_5 || key == NUMPAD_6 || key == NUMPAD_8) {

                if (key == NUMPAD_5) {
                        // reset
                }
                else if (key == NUMPAD_4 || key == NUMPAD_6) 
                {
                        if (fractol->color.rgb_ptr == NULL) {
                                ft_putendl_fd("Select RGB : [R G B R G B] (NUMPAD 2 or 8)", 1);
                                return (1);
                        }
                        else if (key == NUMPAD_4) 
                        {
                                if (*fractol->color.rgb_ptr > 0)
                                        *fractol->color.rgb_ptr -= 16;
                                else
                                        *fractol->color.rgb_ptr = 255;
                        }
                        else {
                                if (*fractol->color.rgb_ptr < 255)
                                        *fractol->color.rgb_ptr += 16;
                                else
                                        *fractol->color.rgb_ptr = 0;
                        }
                }
                else {
                        if (key == NUMPAD_8) 
                        {
                                if (fractol->color.rgb_ptr == NULL)
                                        fractol->color.rgb_ptr = &fractol->color.start.r;
                                else if (fractol->color.rgb_ptr == &fractol->color.start.r)
                                        fractol->color.rgb_ptr = &fractol->color.end.b;
                                else if (fractol->color.rgb_ptr == &fractol->color.start.g)
                                        fractol->color.rgb_ptr = &fractol->color.start.r;
                                else if (fractol->color.rgb_ptr == &fractol->color.start.b)
                                        fractol->color.rgb_ptr = &fractol->color.start.g;
                                else if (fractol->color.rgb_ptr == &fractol->color.end.r)
                                        fractol->color.rgb_ptr = &fractol->color.start.b;
                                else if (fractol->color.rgb_ptr == &fractol->color.end.g)
                                        fractol->color.rgb_ptr = &fractol->color.end.r;
                                else if (fractol->color.rgb_ptr == &fractol->color.end.b)
                                        fractol->color.rgb_ptr = &fractol->color.end.g;
                        }
                        else {
                                if (fractol->color.rgb_ptr == NULL)
                                        fractol->color.rgb_ptr = &fractol->color.start.r;
                                else if (fractol->color.rgb_ptr == &fractol->color.start.r)
                                        fractol->color.rgb_ptr = &fractol->color.start.g;
                                else if (fractol->color.rgb_ptr == &fractol->color.start.g)
                                        fractol->color.rgb_ptr = &fractol->color.start.b;
                                else if (fractol->color.rgb_ptr == &fractol->color.start.b)
                                        fractol->color.rgb_ptr = &fractol->color.end.r;
                                else if (fractol->color.rgb_ptr == &fractol->color.end.r)
                                        fractol->color.rgb_ptr = &fractol->color.end.g;
                                else if (fractol->color.rgb_ptr == &fractol->color.end.g)
                                        fractol->color.rgb_ptr = &fractol->color.end.b;
                                else if (fractol->color.rgb_ptr == &fractol->color.end.b)
                                        fractol->color.rgb_ptr = &fractol->color.start.r;
                        }
                        if (fractol->color.rgb_ptr == &fractol->color.start.r) 
                                printf("Select RGB : [\e[1;31mR\e[0m G B R G B]\n");
                        else if (fractol->color.rgb_ptr == &fractol->color.end.r) 
                                printf("Select RGB : [R G B \e[1;31mR\e[0m G B]\n");
                        else if (fractol->color.rgb_ptr == &fractol->color.start.g) 
                                printf("Select RGB : [R \e[1;32mG\e[0m B R G B]\n");
                        else if (fractol->color.rgb_ptr == &fractol->color.end.g) 
                                printf("Select RGB : [R G B R \e[1;32mG\e[0m B]\n");
                        else if (fractol->color.rgb_ptr == &fractol->color.start.b) 
                                printf("Select RGB : [R G \e[1;35mB\e[0m R G B]\n");
                        else
                                printf("Select RGB : [R G B R G \e[1;35mB\e[0m]\n");
                }
                printf("=> %#08X(%d)\n", *fractol->color.rgb_ptr, *fractol->color.rgb_ptr);
        }
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