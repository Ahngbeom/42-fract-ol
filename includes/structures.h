/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:56:18 by bahn              #+#    #+#             */
/*   Updated: 2021/10/08 22:11:29 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

typedef struct s_rgb t_rgb;
typedef struct s_color t_color;
typedef struct s_point t_point;
typedef struct s_myimg t_myimg;
typedef struct s_fractol t_fractol;

struct s_rgb2
{
  int r;
  int g;
  int b;
};

struct s_rgb
{
  int value;
  t_rgb *prev;
  t_rgb *next;
};

struct s_color
{
  t_rgb *rgb_ptr;
  t_rgb *start;
  t_rgb *end;
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
  int bpp;
  int	size_line;
  int	endian;
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
  t_color *color;
  t_point julia_const;
};