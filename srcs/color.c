/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:22:00 by bahn              #+#    #+#             */
/*   Updated: 2021/10/18 16:06:53 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	color_init(t_fractol *fractol, char *values)
{
	int		i;
	char	**rgb;

	rgb = ft_split(values, ' ');
	fractol->color.rgb = malloc(sizeof(int) * 6);
	if (fractol->color.rgb == NULL)
		ft_exception("Color Initialized Error", "malloc", fractol);
	i = 0;
	while (rgb[i] != NULL)
	{
		fractol->color.rgb[i] = ft_atoi(rgb[i]);
		free(rgb[i]);
		i++;
	}
	free(rgb);
	fractol->color.target_idx = -1;
}

int	set_color(int iter, t_color *color)
{
	int	r;
	int	g;
	int	b;

	r = (int)(color->rgb[0] - (color->rgb[0] / 16 * fmod(iter, 16.0))) \
		+ (int)(color->rgb[3] / 16 * fmod(iter, 16.0));
	g = (int)(color->rgb[1] - (color->rgb[1] / 16 * fmod(iter, 16.0))) \
		+ (int)(color->rgb[4] / 16 * fmod(iter, 16.0));
	b = (int)(color->rgb[2] - (color->rgb[2] / 16 * fmod(iter, 16.0))) \
		+ (int)(color->rgb[5] / 16 * fmod(iter, 16.0));
	return (r << 16 | g << 8 | b);
}

static	void	color_info(t_fractol *fractol, int index)
{
	if (index == 0)
		ft_putstr_fd("Select RGB : [\e[1;31mR\e[0m G B R G B]", 1);
	else if (index == 1)
		ft_putstr_fd("Select RGB : [R \e[1;32mG\e[0m B R G B]", 1);
	else if (index == 2)
		ft_putstr_fd("Select RGB : [R G \e[1;35mB\e[0m R G B]", 1);
	else if (index == 3)
		ft_putstr_fd("Select RGB : [R G B \e[1;31mR\e[0m G B]", 1);
	else if (index == 4)
		ft_putstr_fd("Select RGB : [R G B R \e[1;32mG\e[0m B]", 1);
	else
		ft_putstr_fd("Select RGB : [R G B R G \e[1;35mB\e[0m]", 1);
	ft_putstr_fd(" => ", 1);
	ft_putnbr_fd(fractol->color.rgb[index], 1);
	ft_putchar_fd('\n', 1);
}

void	change_rgb_ptr(int key, t_fractol *fractol)
{
	if (fractol->color.target_idx == -1)
		fractol->color.target_idx = 0;
	else if (key == NUMPAD_4)
	{
		if (--fractol->color.target_idx < 0)
			fractol->color.target_idx = 5;
	}
	else
	{
		if (++fractol->color.target_idx > 5)
			fractol->color.target_idx = 0;
	}
	color_info(fractol, fractol->color.target_idx);
}

void	change_rgb_value(int key, t_fractol *fractol)
{
	if (fractol->color.target_idx == -1)
	{
		ft_putendl_fd("First select RGB : [R G B R G B] (NUMPAD 4 or 6)", 1);
		return ;
	}
	else if (key == NUMPAD_2)
	{
		fractol->color.rgb[fractol->color.target_idx] -= 15;
		if (fractol->color.rgb[fractol->color.target_idx] < 0)
			fractol->color.rgb[fractol->color.target_idx] = 255;
	}
	else
	{
		fractol->color.rgb[fractol->color.target_idx] += 15;
		if (fractol->color.rgb[fractol->color.target_idx] > 255)
			fractol->color.rgb[fractol->color.target_idx] = 0;
	}
	color_info(fractol, fractol->color.target_idx);
}
