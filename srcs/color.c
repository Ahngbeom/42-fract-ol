/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:22:00 by bahn              #+#    #+#             */
/*   Updated: 2021/10/08 22:57:13 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	color_init(t_fractol *fractol, t_rgb *dest, int r_value, int g_value, int b_value)
{
	t_rgb *r;
	t_rgb *g;
	t_rgb *b;
	
	r = (t_rgb *)malloc(sizeof(t_rgb));
	if (r == NULL)
		ft_exception_exit("Malloc Error", "Color R Uninitialized", fractol);
	r->value = r_value;

	g = (t_rgb *)malloc(sizeof(t_rgb));
	if (r == NULL)
		ft_exception_exit("Malloc Error", "Color R Uninitialized", fractol);
	g->value = g_value;

	b = (t_rgb *)malloc(sizeof(t_rgb));
	if (r == NULL)
		ft_exception_exit("Malloc Error", "Color R Uninitialized", fractol);
	b->value = b_value;
	
	if (fractol->color->rgb_ptr == fractol->color->start)
	{
		fractol->color->start = r;
		r->prev = NULL;
		r->next = g;
		g->prev = r;
		g->next = b;
		b->prev = g;
		b->next = NULL;
		fractol->color->rgb_ptr = fractol->color->end;
	}
	else if (fractol->color->rgb_ptr == fractol->color->end)
	{
		fractol->color->end = r;
		fractol->color->end->prev = fractol->color->start->next->next;
		fractol->color->start->next->next->next = fractol->color->end;
		r->next = g;
		g->prev = r;
		g->next = b;
		b->prev = g;
		b->next = NULL;

		fractol->color->rgb_ptr = NULL;
	}
}

int	set_color(int iter, t_color *color)
{
	int	r;
	int	g;
	int	b;

	r = (int)(color->start->value - (color->start->value / 16 * fmod(iter, 16.0))) \
		+ (int)(color->end->value / 16 * fmod(iter, 16.0));
	g = (int)(color->start->next->value - (color->start->next->value / 16 * fmod(iter, 16.0))) \
		+ (int)(color->end->next->value / 16 * fmod(iter, 16.0));
	b = (int)(color->start->next->next->value - (color->start->next->next->value / 16 * fmod(iter, 16.0))) \
		+ (int)(color->end->next->next->value / 16 * fmod(iter, 16.0));
	return (r << 16 | g << 8 | b);
}

void    change_rgb_ptr(int key, t_fractol *fractol)
{
	if (fractol->color->rgb_ptr == NULL)
		fractol->color->rgb_ptr = fractol->color->start;
        else if (key == NUMPAD_4)
		fractol->color->rgb_ptr = fractol->color->rgb_ptr->prev;
	else
		fractol->color->rgb_ptr = fractol->color->rgb_ptr->next;

	if (fractol->color->rgb_ptr == fractol->color->start)
		ft_putendl_fd("Select RGB : [\e[1;31mR\e[0m G B R G B]", 1);
	else if (fractol->color->rgb_ptr == fractol->color->start->next)
		ft_putendl_fd("Select RGB : [R \e[1;32mG\e[0m B R G B]", 1);
	else if (fractol->color->rgb_ptr == fractol->color->start->next->next) 
		ft_putendl_fd("Select RGB : [R G \e[1;35mB\e[0m R G B]", 1);
	else if (fractol->color->rgb_ptr == fractol->color->end)
		ft_putendl_fd("Select RGB : [R G B \e[1;31mR\e[0m G B]", 1);
	else if (fractol->color->rgb_ptr == fractol->color->end->next) 
		ft_putendl_fd("Select RGB : [R G B R \e[1;32mG\e[0m B]", 1);
	else
		ft_putendl_fd("Select RGB : [R G B R G \e[1;35mB\e[0m]", 1);
        ft_putstr_fd("=> ", 1);
        ft_putnbr_fd(fractol->color->rgb_ptr->value, 1);
        ft_putchar_fd('\n', 1);
}

void    change_rgb_value(int key, t_fractol *fractol)
{
        if (fractol->color->rgb_ptr == NULL) {
                ft_putendl_fd("First select RGB : [R G B R G B] (NUMPAD 4 or 6)", 1);
                return ;
        }
        else if (key == NUMPAD_2) 
        {       
                if (fractol->color->rgb_ptr->value == 0)
                        fractol->color->rgb_ptr->value = 255;
                else if (fractol->color->rgb_ptr->value - 16 < 0)
                        fractol->color->rgb_ptr->value = 0;
                else
                        fractol->color->rgb_ptr->value -= 16;
        }
        else {
                if (fractol->color->rgb_ptr->value == 255)
                        fractol->color->rgb_ptr->value = 0;
                else if (fractol->color->rgb_ptr->value + 16 > 255)
                        fractol->color->rgb_ptr->value = 255;
                else
                        fractol->color->rgb_ptr->value += 16;
        }
        ft_putstr_fd("=> ", 1);
        ft_putnbr_fd(fractol->color->rgb_ptr->value, 1);
        ft_putchar_fd('\n', 1);
}