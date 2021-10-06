/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:21:08 by bahn              #+#    #+#             */
/*   Updated: 2021/10/06 19:38:07 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	press_key(int key, t_fractol *fractol)
{
        // printf("Press Key : %#010X\n", key);
	if (key == ESC_KEY) {
                // free
                exit(0);
        }
        else if (key == R_KEY)
                fractol->f_fractol_init(fractol);
        else if (key >= LEFT_KEY && key <= DOWN_KEY)
                move_centroid(key, fractol);
        else if (key == NUMPAD_2 || key == NUMPAD_4 || key == NUMPAD_6 || key == NUMPAD_8) {
                change_rgb(key, fractol);
        } 
        else if (key >= OPTION_1 && key <= OPTION_4)
                change_option(key, fractol);
        draw_fractol(fractol);
}

void    change_option(int key, t_fractol *fractol)
{
        if (fractol->f_fractol_calc == mandelbrot) {
                if (key == OPTION_1) {
                        fractol->center.x = 0;
	                fractol->center.y = 0;
	                if (WIDTH >= HEIGHT)
		                fractol->pixel = WIDTH / 4;
                        else
                                fractol->pixel = HEIGHT / 4;
                        fractol->complex.x = WIDTH / fractol->pixel;
                        fractol->complex.y = HEIGHT / fractol->pixel;
                }
                else if (key == OPTION_2) {
                        fractol->center.x = -0.194462;
                        fractol->center.y = -0.350859;
                        fractol->pixel = 967.458816;
                        fractol->complex.x = 1.116327;
                        fractol->complex.y = 0.744218;
                }
                else if (key == OPTION_3) {
                        fractol->center.x = -1.261666;
                        fractol->center.y = -0.000292;
                        fractol->pixel = 4991.874990;
                        fractol->complex.x = 0.216352;
                        fractol->complex.y = 0.144234;
                }
                else {
                        fractol->center.x = -1.466811;
                        fractol->center.y = 0.000025;
                        fractol->pixel = 822883.947302;
                        fractol->complex.x = 0.001312;
                        fractol->complex.y = 0.000875;
                }
        }
        else if (fractol->f_fractol_calc == julia) {
                if (key == OPTION_1) {
                        fractol->julia_const.x = -0.1875;
                        fractol->julia_const.y = -1.0944;
                }
                else if (key == OPTION_2) {
                        fractol->julia_const.x = 0.185185;
                        fractol->julia_const.y = 0.644444;
                }
                else if (key == OPTION_3) {
                        fractol->julia_const.x = 0.296296;
                        fractol->julia_const.y = 0.014815;
                }
                else {
                        fractol->julia_const.x = -1.261003;
                        fractol->julia_const.y = 0;
                }
        }
        else {
                if (key == OPTION_1) {
                        fractol->center.x = -0.5;
	                fractol->center.y = -0.5;
	                if (WIDTH >= HEIGHT)
		                fractol->pixel = WIDTH / 4;
                        else
                                fractol->pixel = HEIGHT / 4;
                        fractol->complex.x = WIDTH / fractol->pixel;
                        fractol->complex.y = HEIGHT / fractol->pixel;
                }
                else if (key == OPTION_2) {
                        fractol->center.x = -0.575362;
                        fractol->center.y = -0.812751;
                        fractol->pixel = 967.458816;
                        fractol->complex.x = 1.116327;
                        fractol->complex.y = 0.744218;
                }
                else if (key == OPTION_3) {
                        fractol->center.x = -1.747374;
                        fractol->center.y = -0.033965;
                        fractol->pixel = 7188.299986;
                        fractol->complex.x = 0.150244;
                        fractol->complex.y = 0.100163;
                }
                else {
                        fractol->center.x = -1.761435;
                        fractol->center.y = -0.023273;
                        fractol->pixel = 31547395.556643;
                        fractol->complex.x = 0.000034;
                        fractol->complex.y = 0.000023;
                }
        }
}

void    change_rgb(int key, t_fractol *fractol)
{
        if (key == NUMPAD_2 || key == NUMPAD_8) 
        {
                if (fractol->color.rgb_ptr == NULL) {
                        ft_putendl_fd("First select RGB : [R G B R G B] (NUMPAD 4 or 6)", 1);
                        return (1);
                }
                else if (key == NUMPAD_2) 
                {       
                        if (*fractol->color.rgb_ptr == 0)
                                *fractol->color.rgb_ptr = 255;
                        else if (*fractol->color.rgb_ptr - 16 < 0)
                                *fractol->color.rgb_ptr = 0;
                        else
                                *fractol->color.rgb_ptr -= 16;
                }
                else {
                        if (*fractol->color.rgb_ptr == 255)
                                *fractol->color.rgb_ptr = 0;
                        else if (*fractol->color.rgb_ptr + 16 > 255)
                                *fractol->color.rgb_ptr = 255;
                        else
                                *fractol->color.rgb_ptr += 16;
                }
        }
        else {
                if (key == NUMPAD_4) 
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
                        ft_putendl_fd("Select RGB : [\e[1;31mR\e[0m G B R G B]", 1);
                else if (fractol->color.rgb_ptr == &fractol->color.end.r) 
                        ft_putendl_fd("Select RGB : [R G B \e[1;31mR\e[0m G B]", 1);
                else if (fractol->color.rgb_ptr == &fractol->color.start.g) 
                        ft_putendl_fd("Select RGB : [R \e[1;32mG\e[0m B R G B]", 1);
                else if (fractol->color.rgb_ptr == &fractol->color.end.g) 
                        ft_putendl_fd("Select RGB : [R G B R \e[1;32mG\e[0m B]", 1);
                else if (fractol->color.rgb_ptr == &fractol->color.start.b) 
                        ft_putendl_fd("Select RGB : [R G \e[1;35mB\e[0m R G B]", 1);
                else
                        ft_putendl_fd("Select RGB : [R G B R G \e[1;35mB\e[0m]", 1);
        }
        printf("=> %#08X(%d)\n", *fractol->color.rgb_ptr, *fractol->color.rgb_ptr);
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

void    change_centroid(int key, t_fractol *fractol)
{
        // -1.736972, -0.018942
        if (key == UP_KEY)
                fractol->center.y += 0.1;
        else if (key == DOWN_KEY)
                fractol->center.y += -0.1;
        else if (key == LEFT_KEY)
                fractol->center.x += -0.1;
        else //(key == RIGHT_KEY)
                fractol->center.x += 0.1;
}
