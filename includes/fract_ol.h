/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 14:33:36 by bahn              #+#    #+#             */
/*   Updated: 2021/10/07 16:53:18 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "mlx.h"
# include "libft.h"
# include "structures.h"
# include "functions.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>

# define  WIDTH       1080
# define  HEIGHT      720

# define  ITER_MAX    50

# define  ZOOM        1.2

// Exit Key
# define  ESC_KEY     0x0000FF1B

// Zoom IN/OUT Key
# define  SCROLL_UP   0X00000004
# define  SCROLL_DOWN 0X00000005

// Moving Centroid Key
# define  LEFT_KEY    0X0000FF51
# define  UP_KEY      0X0000FF52
# define  RIGHT_KEY   0X0000FF53
# define  DOWN_KEY    0X0000FF54

// Reset Key
# define  R_KEY       0x00000072

// Change RGB Key
# define  NUMPAD_4    0X0000FF96
# define  NUMPAD_8    0X0000FF97
# define  NUMPAD_6    0X0000FF98
# define  NUMPAD_2    0X0000FF99
# define  NUMPAD_5    0X0000FF9D

// Change Option Key
# define  OPTION_1    0X00000031
# define  OPTION_2    0X00000032
# define  OPTION_3    0X00000033
# define  OPTION_4    0X00000034

#endif