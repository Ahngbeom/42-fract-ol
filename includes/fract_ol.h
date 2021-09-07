/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 14:33:36 by bahn              #+#    #+#             */
/*   Updated: 2021/09/08 00:38:49 by bahn             ###   ########.fr       */
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
#define		HEIGHT				720
#define		ITER_MAX			300

typedef struct s_vars t_vars;
typedef struct s_data t_data;

struct	s_vars {
  void	*mlx;
	void	*win;
	t_data	*img;
};

struct  s_data
{
  void	*img;
  char	*addr;
  int	bits_per_pixel;
  int	line_length;
  int	endian;
};

void  my_mlx_pixel_put(t_data *data, int x, int y, int color);

int press_key(int key, t_vars *vars);
int	mouse_button(int button, int x, int y, t_vars *vars);
int	mouse_pos(int x ,int y, t_vars *vars);
int	create_trgb(int t, int r, int g, int b);
int	color_map(t_vars *vars, int w, int h);
int	set_bgcolor(t_vars *vars, int w, int h, int color);

#endif