/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:58:57 by bahn              #+#    #+#             */
/*   Updated: 2021/10/17 17:14:41 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static	void	set_complex_plane(t_fractol *fractol, \
					double pixel, t_point center, t_point complex)
{
	fractol->pixel = pixel;
	fractol->center = center;
	fractol->complex = complex;
}

void	change_scene_mandelb(int key, t_fractol *fractol)
{
	if (key == SCENE_1)
		set_complex_plane(fractol, WIDTH / 4, set_point(-0.5, 0), \
			set_point(WIDTH / (double)(WIDTH / 4), \
					HEIGHT / (double)(WIDTH / 4)));
	else if (key == SCENE_2)
		set_complex_plane(fractol, 4991.874990, \
				set_point(-1.761666, -0.000292), set_point(0.216352, 0.144234));
	else if (key == SCENE_3)
		set_complex_plane(fractol, 967.458816, \
			set_point(-0.694462, -0.350859), set_point(1.116327, 0.744218));
	else
		set_complex_plane(fractol, 476205.988022, \
			set_point(-0.730991, -0.185956), set_point(0.002268, 0.001512));
}

void	change_scene_julia(int key, t_fractol *fractol)
{
	if (key == SCENE_1)
		fractol->julia_const = set_point(-0.1875, -1.0944);
	else if (key == SCENE_2)
		fractol->julia_const = set_point(0.185185, 0.644444);
	else if (key == SCENE_3)
		fractol->julia_const = set_point(0.296296, 0.014815);
	else
		fractol->julia_const = set_point(-0.866667, 0);
}

void	change_scene_burnship(int key, t_fractol *fractol)
{
	if (key == SCENE_1)
		set_complex_plane(fractol, WIDTH / 4, set_point(-0.5, -0.5), \
			set_point(WIDTH / (double)(WIDTH / 4), \
					HEIGHT / (double)(WIDTH / 4)));
	else if (key == SCENE_2)
		set_complex_plane(fractol, 967.458816, \
			set_point(-0.575362, -0.812751), set_point(1.116327, 0.744218));
	else if (key == SCENE_3)
		set_complex_plane(fractol, 4991.874990, \
			set_point(-1.705783, -0.040083), set_point(0.216352, 0.144234));
	else
		set_complex_plane(fractol, 10351.151980, \
			set_point(-1.746212, -0.040321), set_point(0.103622, 0.070098));
}
