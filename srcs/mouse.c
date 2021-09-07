/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:20:09 by bahn              #+#    #+#             */
/*   Updated: 2021/09/07 16:20:27 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	mouse_button(int button, int x, int y, t_vars *vars)
{
        static  int     num = 0;
        int     color;

        printf("Mouse button : %d at %dx%d.\n", button, x, y);
        if (button == 4 || button == 5)
        {
                if (button == 4)
                        num++;
                if (button == 5)
                        num--;
                color = (num << 16) + (num << 8) + num;
                set_bgcolor(vars, 800, 600, color);
        }
}

int	mouse_pos(int x ,int y, t_vars *vars)
{
        printf("Mouse moving %d x %d.\n", x, y);
}