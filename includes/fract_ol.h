/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 14:33:36 by bahn              #+#    #+#             */
/*   Updated: 2021/09/07 16:19:12 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

#include "mlx.h"
#include "mlx_int.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	press_key(int key, t_vars *vars);
int	mouse_button(int button, int x, int y, t_vars *vars);
int	mouse_pos(int x ,int y, t_vars *vars);
int	create_trgb(int t, int r, int g, int b);
int	color_map(t_vars *vars, int w, int h);
int	set_bgcolor(t_vars *vars, int w, int h, int color);

#endif