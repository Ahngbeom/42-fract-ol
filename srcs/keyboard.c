/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:21:08 by bahn              #+#    #+#             */
/*   Updated: 2021/10/07 21:05:20 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	press_key(int key, t_fractol *fractol)
{
	if (key == ESC_KEY) {
                free(fractol->img.addr);
                free(fractol->img.img);
                free(fractol->win);
                free(fractol->mlx);
                exit(0);
        }
        else if (key == R_KEY)
                fractol->f_fractol_init(fractol);
        else if (key >= LEFT_KEY && key <= DOWN_KEY)
                move_centroid(key, fractol);
        else if (key == NUMPAD_2 || key == NUMPAD_4 || key == NUMPAD_6 || key == NUMPAD_8)
                change_rgb(key, fractol);
        else if (key >= OPTION_1 && key <= OPTION_4)
                change_option(key, fractol);
        draw_fractol(fractol);
}