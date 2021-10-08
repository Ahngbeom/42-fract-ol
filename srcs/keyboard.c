/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:21:08 by bahn              #+#    #+#             */
/*   Updated: 2021/10/08 22:12:30 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	press_key(int key, t_fractol *fractol)
{
	void *temp;
	if (key == ESC_KEY)
	{
		fractol->color->rgb_ptr = fractol->color->start;
		while (fractol->color->rgb_ptr != NULL)
		{
			temp = fractol->color->rgb_ptr->next;
			free(fractol->color->rgb_ptr);
			fractol->color->rgb_ptr = temp;
		}

		mlx_destroy_image(fractol->mlx, fractol->img.img);
		mlx_destroy_window(fractol->mlx, fractol->win);
		mlx_destroy_display(fractol->mlx);
		free(fractol->mlx);
		exit(EXIT_SUCCESS);
	}
	else if (key == R_KEY)
		fractol->f_fractol_init(fractol);
	else if (key >= LEFT_KEY && key <= DOWN_KEY)
		move_centroid(key, fractol);
	else if (key == NUMPAD_4 || key == NUMPAD_6)
		change_rgb_ptr(key, fractol);
	else if (key == NUMPAD_2 || key == NUMPAD_8)
		change_rgb_value(key, fractol);
	else if (key >= OPTION_1 && key <= OPTION_4)
		change_scene(key, fractol);
	draw_fractol(fractol);
}