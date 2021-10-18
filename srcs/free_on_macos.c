/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_on_macos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:56:39 by bahn              #+#    #+#             */
/*   Updated: 2021/10/18 15:56:49 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_free(t_fractol *fractol, int status)
{
	if (fractol->color.rgb != NULL)
		free(fractol->color.rgb);
	if (fractol->mlx != NULL)
	{
		if (fractol->win != NULL)
		{
			if (fractol->img.img != NULL)
				mlx_destroy_image(fractol->mlx, fractol->img.img);
			mlx_destroy_window(fractol->mlx, fractol->win);
		}
	}
	exit(status);
}