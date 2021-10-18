/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:01:40 by bahn              #+#    #+#             */
/*   Updated: 2021/10/18 15:55:31 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "fract_ol.h"

void		my_mlx_pixel_put(t_myimg *img, int x, int y, int color);
t_point		set_point(double x, double y);
void		ft_exception(char *title, char *detail, t_fractol *data);
void		ft_free(t_fractol *fractol, int status);

// Keyboard Hook
int			press_key(int key, t_fractol *fractol);
void		move_centroid(int key, t_fractol *fractol);
void		change_centroid(int key, t_fractol *fractol);

// Mouse Hook
int			mouse_hook(int button, int x, int y, t_fractol *fractol);
int			mouse_motion_hook(int x, int y, t_fractol *fractol);

// Coloring
// void	color_init(t_fractol *fractol, int r_value, int g_value, int b_value);
void		color_init(t_fractol *fractol, char *values);
int			set_color(int iter, t_color *color);
void		change_rgb_ptr(int key, t_fractol *fractol);
void		change_rgb_value(int key, t_fractol *fractol);

// Centroid
void		move_centroid(int key, t_fractol *fractol);

// Scene
void		change_scene_mandelb(int key, t_fractol *fractol);
void		change_scene_julia(int key, t_fractol *fractol);
void		change_scene_burnship(int key, t_fractol *fractol);

// Fractol
void		fractol_init(t_fractol *fractol, char **argv);
void		draw_fractol(t_fractol *fractol);

// Fractol Type
void		mandelbrot_init(t_fractol *fractol);
int			mandelbrot(t_fractol *fractol, int count_w, int count_h, int iter);

void		julia_init(t_fractol *fractol);
int			julia(t_fractol *fractol, int count_w, int count_h, int iter);

void		burning_ship_init(t_fractol *fractol);
int			burning_ship(t_fractol *fractol, int w, int h, int iter);

#endif