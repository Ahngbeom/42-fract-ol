/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 14:33:36 by bahn              #+#    #+#             */
/*   Updated: 2021/09/28 20:25:05 by bahn             ###   ########.fr       */
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

# define  WIDTH     1280
# define  HEIGHT    720
# define  ITER_MAX  70
# define  ZOOM      1.2
# define  PI        3.14159265359

# define  LEFT      0X00FF51
# define  UP        0X00FF52
# define  RIGHT     0X00FF53
# define  DOWN      0X00FF54

typedef struct s_point t_point;
typedef struct s_myimg t_myimg;
typedef struct s_fractol t_fractol;

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
  
  int type;

  double  pixel;
  t_myimg	img;
  t_point center;
  // t_point pixel;
  t_point complex;
  t_point mouse;
  t_point julia_const;
};

void  my_mlx_pixel_put(t_myimg *img, int x, int y, int color);

int press_key(int key, t_fractol *fractol);
void    move_centroid(int key, t_fractol *fractol);

int	mouse_hook(int button, int x, int y, t_fractol *fractol);
int	mouse_motion_hook(int x ,int y, t_fractol *fractol);

int	create_trgb(int t, int r, int g, int b);
int	color_map(t_fractol *fractol, int w, int h);
int color_set(int iter);
int	set_bgcolor(t_fractol *fractol, int w, int h, int color);
int	rgb_bitset(int brightness);

void    draw_fractol(t_fractol *fractol);
int     mandelbrot(t_fractol *fractol, int count_w, int count_h, int iter);
int     julia(t_fractol *fractol, int count_w, int count_h, int iter);

int	ft_gcd(int a, int b);

#endif