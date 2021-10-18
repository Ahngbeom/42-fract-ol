/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 14:55:11 by bahn              #+#    #+#             */
/*   Updated: 2021/10/18 16:06:44 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (argc < 2)
		ft_exception("Please enter the Fractol Type", \
				"\e[92m[Mandelbrot] [Julia] [Burning ship]\e[0m", NULL);
	else
		fractol_init(&fractol, argv);
	mlx_key_hook(fractol.win, press_key, &fractol);
	mlx_mouse_hook(fractol.win, mouse_hook, &fractol);
	mlx_hook(fractol.win, 6, (1L << 6), mouse_motion_hook, &fractol);
	draw_fractol(&fractol);
	mlx_loop(fractol.mlx);
}
