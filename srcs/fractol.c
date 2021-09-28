/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:13:57 by bahn              #+#    #+#             */
/*   Updated: 2021/09/28 23:09:42 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int     mandelbrot(t_fractol *fractol, int w, int h, int iter)
{
	double c_re;
	double c_im;
	double x;
	double y;
	double temp;

	c_re = fractol->center.x + (((double)w / fractol->pixel) - (fractol->complex.x / 2)) - 0.5;
	c_im = fractol->center.y + (((double)h / fractol->pixel) - (fractol->complex.y / 2));
    //	mlx-win 기준 각 좌표(w, h)를 fractol 픽셀로 나눈 값을 프렉탈 집합 중심 좌표에 더한다.
	//	프렉탈 집합 중심좌표는 복소평면 기준 (0, 0)에 위치하도록 설정되어있다.
	//	그러므로 매개변수로 넘어온 w, h는 mlx-win 기준 좌표이기 때문에 프렉탈 집합 좌표 기준 총 x, y 길이의 절반 값을 빼주어야
	//	복소평면을 기준으로 올바른 프렉탈 집합을 그릴 수 있다. 
	//  단, 망델브로 집합인 경우에는 중심 x 좌표를 0이 아닌 -0.5인 것으로 감안하여 계산한다.
	
	x = c_re;
	y = c_im;
	while ((pow(x, 2.0) + pow(y, 2.0) <= 4) && (iter < ITER_MAX))
	{
		temp = pow(x, 2.0) - pow(y, 2.0) + c_re;
		y = 2 * x * y + c_im;
		x = temp;
		iter++;
	}
	return (iter);
}

int     julia(t_fractol *fractol, int w, int h, int iter)
{
	double c_re;
	double c_im;
	double x;
	double y;
	double temp;

	c_re = fractol->julia_const.x;
	c_im = fractol->julia_const.y;
        
	x = fractol->center.x + ((double)w / fractol->pixel) - (fractol->complex.x / 2);
	y = fractol->center.y + ((double)h / fractol->pixel) - (fractol->complex.y / 2);
	while ((pow(x, 2.0) + pow(y, 2.0) <= 4) && (iter < ITER_MAX))
	{
		temp = pow(x, 2.0) - pow(y, 2.0) + c_re;
		y = 2 * x * y + c_im;
		x = temp;
		iter++;
	}
	return (iter);
}