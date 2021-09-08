/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 14:33:36 by bahn              #+#    #+#             */
/*   Updated: 2021/09/08 20:03:59 by bahn             ###   ########.fr       */
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
#define   ZOOM        1
typedef struct s_vars t_vars;
typedef struct s_data t_data;
typedef struct s_zoom t_zoom;

struct	s_vars {
  void	*mlx;
	void	*win;
	t_data	*img;
  t_zoom  *zoom;
};

struct  s_data
{
  void	*img;
  char	*addr;
  int	bits_per_pixel;
  int	line_length;
  int	endian;
};

struct s_zoom
{
  int max_w;
  int min_w;
  int max_h;
  int min_h;
  int width;
  int height;
};


void  my_mlx_pixel_put(t_data *data, int x, int y, int color);

int press_key(int key, t_vars *vars);
int	mouse_button(int button, int x, int y, t_vars *vars);
int	mouse_pos(int x ,int y, t_vars *vars);
int	create_trgb(int t, int r, int g, int b);
int	color_map(t_vars *vars, int w, int h);
int color_set(int iter);
int	set_bgcolor(t_vars *vars, int w, int h, int color);

#endif