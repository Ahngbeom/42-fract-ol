/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:21:08 by bahn              #+#    #+#             */
/*   Updated: 2021/10/18 15:49:49 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	press_key(int key, t_fractol *fractol)
{
	if (key == ESC_KEY)
		ft_free(fractol, EXIT_SUCCESS);
	else if (key == R_KEY)
		fractol->f_fractol_init(fractol);
	else if (key >= 123 && key <= 126)
		move_centroid(key, fractol);
	else if (key == NUMPAD_4 || key == NUMPAD_6)
		change_rgb_ptr(key, fractol);
	else if (key == NUMPAD_2 || key == NUMPAD_8)
		change_rgb_value(key, fractol);
	else if (key >= SCENE_1 && key <= SCENE_4)
	{
		if (fractol->f_fractol_calc == mandelbrot)
			change_scene_mandelb(key, fractol);
		else if (fractol->f_fractol_calc == julia)
			change_scene_julia(key, fractol);
		else
			change_scene_burnship(key, fractol);
	}
	draw_fractol(fractol);
	return (0);
}
