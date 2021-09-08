/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:20:09 by bahn              #+#    #+#             */
/*   Updated: 2021/09/08 20:05:24 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	mouse_button(int button, int x, int y, t_vars *vars)
{
        static  int     num = 0;
        int     color;

        if (button = 1)
                printf("Mouse Click(%d) : %dx%d.\n", button, x, y);
        if (button == 4 || button == 5)
        {
                if (button == 4)
                {
                        vars->zoom->max_w -= ZOOM * ((vars->zoom->width - x) / vars->zoom->width);
		        vars->zoom->min_w += ZOOM * (x / vars->zoom->width);
		        vars->zoom->max_h -= ZOOM * ((vars->zoom->height - y) / vars->zoom->height);
		        vars->zoom->min_h += ZOOM * (y / vars->zoom->width);
                }
                else if (button == 5)
                {
                        vars->zoom->max_w += ZOOM * ((vars->zoom->width - x) / vars->zoom->width);
                        vars->zoom->min_w -= ZOOM * (x / vars->zoom->width);
                        vars->zoom->max_h += ZOOM * ((vars->zoom->height - y) / vars->zoom->height);
                        vars->zoom->min_h -= ZOOM * (y / vars->zoom->height);
	        }
                else
		        return (0);
                vars->zoom->width = vars->zoom->max_w - vars->zoom->min_w;
                vars->zoom->height = vars->zoom->max_h - vars->zoom->min_h;
                return (0);
        }
}

int	mouse_pos(int x ,int y, t_vars *vars)
{
        printf("Mouse moving %d x %d.\n", x, y);
}