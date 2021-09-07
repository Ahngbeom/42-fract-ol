/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 14:55:11 by bahn              #+#    #+#             */
/*   Updated: 2021/09/07 16:22:15 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int main(void)
{
        t_vars vars;

        vars.mlx = mlx_init();
        vars.win = mlx_new_window(vars.mlx, 800, 600, "bahn's MiniLibX!");
        mlx_key_hook(vars.win, press_key, &vars);
        mlx_mouse_hook(vars.win, mouse_button, &vars);
        // mlx_hook(vars.win, MotionNotify, PointerMotionMask, mouse_pos, &vars);
        // color_map(&vars, 800, 600);
        mlx_loop(vars.mlx);
}