/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 14:55:11 by bahn              #+#    #+#             */
/*   Updated: 2021/09/04 00:48:32 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
int	press_key(int key, t_vars *vars);
int	mouse_button(int button, int x, int y, t_vars *vars);
int	mouse_pos(int x ,int y, t_vars *vars);
int	create_trgb(int t, int r, int g, int b);
int	color_map(t_vars *vars, int w, int h);
int	set_bgcolor(t_vars *vars, int w, int h, int color);

int	press_key(int key, t_vars *vars)
{
        printf("Key Press : %X\n", key);
	if (key == 0xFF1B)
                exit(0);
}

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

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	color_map(t_vars *vars, int w, int h)
{
        int	x;
        int	y;
        int	color;

        x = w;
        while (x--)
        {
                y = h;
                while (y--)
                {
                        color = (x * 255) / w + ((((w - x) * 255) / w) << 16) + (((y * 255) / h) << 8);
                        mlx_pixel_put(vars->mlx, vars->win, x, y, color);
                        printf("%d x %d Color : %d\n", x, y, color);
                }
        }
}

int	set_bgcolor(t_vars *vars, int w, int h, int color)
{
        int	x;
        int	y;

        x = w;
        while (x--)
        {
                y = h;
                while (y--)
                {
                        mlx_pixel_put(vars->mlx, vars->win, x, y, color);
                }
        }
}

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