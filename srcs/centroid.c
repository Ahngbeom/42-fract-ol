/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   centroid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:22:59 by bahn              #+#    #+#             */
/*   Updated: 2021/10/11 16:29:22 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	move_centroid(int key, t_fractol *fractol)
{
	if (key == UP_KEY)
		fractol->center.y -= fractol->complex.y / 10;
	else if (key == DOWN_KEY)
		fractol->center.y += fractol->complex.y / 10;
	else if (key == LEFT_KEY)
		fractol->center.x -= fractol->complex.x / 10;
	else
		fractol->center.x += fractol->complex.x / 10;
}
