/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:56:21 by bahn              #+#    #+#             */
/*   Updated: 2021/10/18 16:15:59 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	my_mlx_pixel_put(t_myimg *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

t_point	set_point(double x, double y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	return (point);
}

void	ft_exception(char *title, char *detail, t_fractol *fractol)
{
	ft_putstr_fd("\e[91mError >>> \e[0m", 1);
	if (title != NULL)
	{
		ft_putstr_fd("\e[95m", 1);
		ft_putstr_fd(title, 1);
	}
	if (detail != NULL)
	{
		ft_putstr_fd(" : \e[92m", 1);
		ft_putstr_fd(detail, 1);
	}
	ft_putstr_fd("\e[0m\n", 1);
	if (fractol != NULL)
		ft_free(fractol, EXIT_FAILURE);
	else
		exit(EXIT_FAILURE);
}
