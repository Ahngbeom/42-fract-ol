/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:25:01 by bahn              #+#    #+#             */
/*   Updated: 2021/10/08 22:22:33 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static	void	minilibx_init(t_fractol *data)
{
	data->mlx = mlx_init();
	if (data->mlx != NULL)
	{
		data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "bahn's fract-ol");
		if (data->win != NULL)
		{
			data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
			if (data->img.img != NULL)
			{
				data->img.addr = mlx_get_data_addr(data->img.img, \
					&data->img.bpp, &data->img.size_line, &data->img.endian);
				if (data->img.addr == NULL)
					ft_exception_exit("MiniLibX Initialization Error", \
								"img_data_ptr", data);
			}
			else
				ft_exception_exit("MiniLibX Initialization Error", \
							"img_ptr", data);
		}
		else
			ft_exception_exit("MiniLibX Initialization Error", \
						"win_ptr", data);
	}
	else
		ft_exception_exit("MiniLibX Initialization Error", "mlx_ptr", data);
}

void	fractol_init(t_fractol *data, char **argv)
{
	
	minilibx_init(data);
	if (!ft_strncmp(argv[1], "Mandelbrot", ft_strlen("Mandelbrot")))
		data->f_fractol_init = mandelbrot_init;
	else if (!ft_strncmp(argv[1], "Julia", ft_strlen("Julia")))
		data->f_fractol_init = julia_init;
	else if (!ft_strncmp(argv[1], "Burning ship", ft_strlen("Burning ship")))
		data->f_fractol_init = burning_ship_init;
	else
		ft_exception_exit("Fractol Type Error", \
			"\e[92m[Mandelbrot] [Julia] [Burning ship]\e[0m", data);
	
	data->f_fractol_init(data);
	
	// data->color = malloc(sizeof(t_color));
	
	data->color->rgb_ptr = NULL;
}
