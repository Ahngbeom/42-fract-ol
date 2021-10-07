/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:22:59 by bahn              #+#    #+#             */
/*   Updated: 2021/10/07 21:16:12 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static	select_RGB(int key, t_color *color)
{
	if (key == NUMPAD_4) 
	{
			if (color->rgb_ptr == NULL)
					color->rgb_ptr = &color->start.r;
			else if (color->rgb_ptr == &color->start.r)
					color->rgb_ptr = &color->end.b;
			else if (color->rgb_ptr == &color->start.g)
					color->rgb_ptr = &color->start.r;
			else if (color->rgb_ptr == &color->start.b)
					color->rgb_ptr = &color->start.g;
			else if (color->rgb_ptr == &color->end.r)
					color->rgb_ptr = &color->start.b;
			else if (color->rgb_ptr == &color->end.g)
					color->rgb_ptr = &color->end.r;
			else if (color->rgb_ptr == &color->end.b)
					color->rgb_ptr = &color->end.g;
	}
	else {
			if (color->rgb_ptr == NULL)
					color->rgb_ptr = &color->start.r;
			else if (color->rgb_ptr == &color->start.r)
					color->rgb_ptr = &color->start.g;
			else if (color->rgb_ptr == &color->start.g)
					color->rgb_ptr = &color->start.b;
			else if (color->rgb_ptr == &color->start.b)
					color->rgb_ptr = &color->end.r;
			else if (color->rgb_ptr == &color->end.r)
					color->rgb_ptr = &color->end.g;
			else if (color->rgb_ptr == &color->end.g)
					color->rgb_ptr = &color->end.b;
			else if (color->rgb_ptr == &color->end.b)
					color->rgb_ptr = &color->start.r;
	}
	if (color->rgb_ptr == &color->start.r) 
			ft_putendl_fd("Select RGB : [\e[1;31mR\e[0m G B R G B]", 1);
	else if (color->rgb_ptr == &color->end.r) 
			ft_putendl_fd("Select RGB : [R G B \e[1;31mR\e[0m G B]", 1);
	else if (color->rgb_ptr == &color->start.g) 
			ft_putendl_fd("Select RGB : [R \e[1;32mG\e[0m B R G B]", 1);
	else if (color->rgb_ptr == &color->end.g) 
			ft_putendl_fd("Select RGB : [R G B R \e[1;32mG\e[0m B]", 1);
	else if (color->rgb_ptr == &color->start.b) 
			ft_putendl_fd("Select RGB : [R G \e[1;35mB\e[0m R G B]", 1);
	else
			ft_putendl_fd("Select RGB : [R G B R G \e[1;35mB\e[0m]", 1);
}

void    change_rgb(int key, t_fractol *fractol)
{
        if (key == NUMPAD_2 || key == NUMPAD_8) 
        {
                if (fractol->color.rgb_ptr == NULL) {
                        ft_putendl_fd("First select RGB : [R G B R G B] (NUMPAD 4 or 6)", 1);
                        return ;
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
        else
			select_RGB(key, &fractol->color);
        printf("=> %#08X(%d)\n", *fractol->color.rgb_ptr, *fractol->color.rgb_ptr);
}

void    move_centroid(int key, t_fractol *fractol)
{
        if (key == UP_KEY)
                fractol->center.y -= fractol->complex.y / 10;
        else if (key == DOWN_KEY)
                fractol->center.y += fractol->complex.y / 10;
        else if (key == LEFT_KEY)
                fractol->center.x -= fractol->complex.x / 10;
        else //(key == RIGHT_KEY)
                fractol->center.x += fractol->complex.x / 10;
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
                        fractol->julia_const.x = -0.866667;
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