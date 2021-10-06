/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:56:18 by bahn              #+#    #+#             */
/*   Updated: 2021/10/06 18:59:48 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

typedef struct s_rgb t_rgb;
typedef struct s_color t_color;
typedef struct s_point t_point;
typedef struct s_myimg t_myimg;

typedef struct s_julia t_julia;
typedef struct s_koch t_koch;

typedef struct s_fractol t_fractol;

struct s_rgb
{
  int r;
  int g;
  int b;
};

struct s_color
{
  int *rgb_ptr;

  t_rgb start;
  t_rgb end;
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

struct s_koch
{
  double leg;
  t_point vertex_left;
  t_point vertex_top;
  t_point vertex_right;
};

struct s_julia
{
  t_point julia_const;
};

struct s_fractol {
  void	*mlx;
	void	*win;
  
  int (*f_fractol_init)(t_fractol*);
  int (*f_fractol_calc)(t_fractol*, int, int, int);
  
  double  pixel;
  t_myimg	img;
  t_point center;
  t_point complex;
  t_point mouse;
  t_point julia_const;
  t_koch koch_const;

  t_color color;
};