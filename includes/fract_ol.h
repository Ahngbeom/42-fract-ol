/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 14:33:36 by bahn              #+#    #+#             */
/*   Updated: 2021/09/17 01:18:42 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "mlx.h"
# include "mlx_int.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

#define		WIDTH				1280
#define		HEIGHT			720
#define		ITER_MAX		100
#define   ZOOM        1.2

typedef struct s_fractol t_fractol;
typedef struct s_myimg t_myimg;
typedef struct s_zoom t_zoom;

struct s_fractol {
  void	*mlx;
	void	*win;
	void	*win2;
	void	*win3;
  
  t_myimg	*img;
  t_zoom  *zoom;
};

struct  s_myimg
{
  void	*img;
  char	*addr;
  int	bits_per_pixel;
  int	line_length;
  int	endian;
};

struct s_zoom
{
  // double pixel;
  
  double mag;

  double center_x;
  double center_y;

  // double w_l_x;
  // double w_l_y;

  double mouse_x;
  double mouse_y;

  double   min_x;
  double   max_x;
  double   min_y;
  double   max_y;
  double   dx;
  double   dy;

};

void  my_mlx_pixel_put(t_myimg *img, int x, int y, int color);

int press_key(int key, t_fractol *fractol);
int	mouse_button(int button, int x, int y, t_fractol *fractol);
int	mouse_pos(int x ,int y, t_fractol *fractol);

int	create_trgb(int t, int r, int g, int b);
int	color_map(t_fractol *fractol, int w, int h);
int color_set(int iter);
int	set_bgcolor(t_fractol *fractol, int w, int h, int color);
int	rgb_bitset(int brightness);

void    ft_fractol(t_fractol *fractol);
int     mandelbrot(t_fractol *fractol, int count_w, int count_h, int iter);

int	ft_gcd(int a, int b);

#endif