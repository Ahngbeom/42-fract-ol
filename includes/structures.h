/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:56:18 by bahn              #+#    #+#             */
/*   Updated: 2021/10/11 22:05:05 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "fract_ol.h"

typedef struct s_color		t_color;
typedef struct s_point		t_point;
typedef struct s_myimg		t_myimg;
typedef struct s_fractol	t_fractol;

struct	s_color
{
	int		target_idx;
	int		*rgb;
};

struct		s_point
{
	double	x;
	double	y;
};

struct	s_myimg
{
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
};

struct		s_fractol
{
	void		*mlx;
	void		*win;
	t_myimg		img;
	void		(*f_fractol_init)(t_fractol*);
	int			(*f_fractol_calc)(t_fractol*, int, int, int);
	double		pixel;
	t_point		center;
	t_point		complex;
	t_point		julia_const;
	t_point		mouse;
	t_color		color;
};

#endif