/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 14:33:36 by bahn              #+#    #+#             */
/*   Updated: 2021/09/30 21:01:07 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "mlx.h"
// # include "mlx_int.h"
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>

# define  WIDTH       1280
# define  HEIGHT      720
# define  ITER_MAX    70
# define  ZOOM        1.2
# define  PI          3.14159265359

# define  SCROLL_UP   0X00000004
# define  SCROLL_DOWN 0X00000005

# define  ESC_KEY     0x0000FF1B
# define  LEFT_KEY    0X0000FF51
# define  UP_KEY      0X0000FF52
# define  RIGHT_KEY   0X0000FF53
# define  DOWN_KEY    0X0000FF54
# define  R_KEY       0x00000072

# define  NUMPAD_4    0X0000FF96
# define  NUMPAD_8    0X0000FF97
# define  NUMPAD_6    0X0000FF98
# define  NUMPAD_2    0X0000FF99
# define  NUMPAD_5    0X0000FF9D

typedef struct s_non_diverges t_non_diverges;
typedef struct s_color t_color;
typedef struct s_point t_point;
typedef struct s_myimg t_myimg;
typedef struct s_fractol t_fractol;

struct s_non_diverges
{
  int max_iter;
  double x;
  double y;
};


struct s_color
{
  double *rgb_ptr;
  double r;
  double g;
  double b;
};

struct s_point
{
  double  x;
  double  y;
};

struct  s_myimg
{
  void	*img;
  char	*addr;
  int bits_per_pixel;
  int	line_length;
  int	endian;
};

struct s_fractol {
  void	*mlx;
	void	*win;
  
  int (*f_calc_fractol)(t_fractol*, int, int, int);
  
  double  pixel;
  t_myimg	img;
  t_point center;
  t_point complex;
  t_point mouse;
  t_point julia_const;

  t_color color;

  t_non_diverges non_diverges;
};

void  my_mlx_pixel_put(t_myimg *img, int x, int y, int color);

int press_key(int key, t_fractol *fractol);
void    move_centroid(int key, t_fractol *fractol);

int	mouse_hook(int button, int x, int y, t_fractol *fractol);
int	mouse_motion_hook(int x ,int y, t_fractol *fractol);

int	create_trgb(int t, int r, int g, int b);
int	color_map(t_fractol *fractol, int w, int h);
int set_flexible_color(int iter, t_color *color);
int set_color(int iter);
int set_mapcolor(int iter);
int	set_bgcolor(t_fractol *fractol, int w, int h, int color);
int	rgb_bitset(int brightness);

int     fractol_init(t_fractol *fractol, char **argv);
void    draw_fractol(t_fractol *fractol);

int     mandelbrot(t_fractol *fractol, int count_w, int count_h, int iter);
int     julia(t_fractol *fractol, int count_w, int count_h, int iter);

int	ft_gcd(int a, int b);

#endif