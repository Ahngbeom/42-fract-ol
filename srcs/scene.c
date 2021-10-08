/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:58:57 by bahn              #+#    #+#             */
/*   Updated: 2021/10/08 16:03:59 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void    change_scene(int key, t_fractol *fractol)
{
        if (fractol->f_fractol_calc == mandelbrot) {
                if (key == OPTION_1) {
                    fractol->center.x = -0.5;
	                fractol->center.y = 0;
	                if (WIDTH >= HEIGHT)
		                fractol->pixel = WIDTH / 4;
					else
						fractol->pixel = HEIGHT / 4;
					fractol->complex.x = WIDTH / fractol->pixel;
					fractol->complex.y = HEIGHT / fractol->pixel;
                }
                else if (key == OPTION_2) {
                        fractol->center.x = -0.694462;
                        fractol->center.y = -0.350859;
                        fractol->pixel = 967.458816;
                        fractol->complex.x = 1.116327;
                        fractol->complex.y = 0.744218;
                }
                else if (key == OPTION_3) {
                        fractol->center.x = -1.761666;
                        fractol->center.y = -0.000292;
                        fractol->pixel = 4991.874990;
                        fractol->complex.x = 0.216352;
                        fractol->complex.y = 0.144234;
                }
                else {
                        fractol->center.x = -2.166811;
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
        else
        {
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
                else if (key == OPTION_3)
                {
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