/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   changes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:10:02 by myuliia           #+#    #+#             */
/*   Updated: 2019/01/31 16:10:03 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		apply_zoom(int button, int x, int y, t_fract *f)
{
	double mouse_re;
	double mouse_im;
	double ind;

	mlx_clear_window(f->w->mlx_ptr, f->w->win_ptr);
	if (button != 2 && button != 1)
	{
		y = HEIGHT - y;
		mouse_re = (double)x / (WIDTH /
			(f->a->max_re - f->a->min_re)) + f->a->min_re;
		mouse_im = (double)y / (HEIGHT /
			(f->a->max_im - f->a->min_im)) + f->a->min_im;
		ind = (button == 5 ? 1.1 : 0.9);
		f->a->min_re = mouse_re + ((f->a->min_re - mouse_re) * (1 / ind));
		f->a->min_im = mouse_im + ((f->a->min_im - mouse_im) * (1 / ind));
		f->a->max_re = mouse_re + ((f->a->max_re - mouse_re) * (1 / ind));
		f->a->max_im = mouse_im + ((f->a->max_im - mouse_im) * (1 / ind));
		f->a->re_factor = (f->a->max_re - f->a->min_re) / (WIDTH - 1);
		f->a->im_factor = (f->a->max_im - f->a->min_im) / (HEIGHT - 1);
	}
	choose_fract(*f);
	return (0);
}

int		mouse_julia(int x, int y, t_fract *f)
{
	mlx_clear_window(f->w->mlx_ptr, f->w->win_ptr);
	if (f->a->indic_mouse_julia == 1)
	{
		f->a->cj_re = (x * 0.006) / 2;
		f->a->cj_im = (x * 0.006) / 2;
	}
	choose_fract(*f);
	return (0);
}

void	change_iterations(t_fract *f, int key)
{
	mlx_clear_window(f->w->mlx_ptr, f->w->win_ptr);
	if (key == 116)
	{
		if (f->a->max_iterations != 3000)
			f->a->max_iterations += 20;
	}
	if (key == 121)
	{
		if (f->a->max_iterations != 0)
			f->a->max_iterations -= 20;
	}
}

void	change_indicator_mouse(t_fract *f)
{
	if (f->a->indic_mouse_julia == 1)
		f->a->indic_mouse_julia = 0;
	else
		f->a->indic_mouse_julia = 1;
}

void	change_color(t_fract *f)
{
	f->a->indic_color += 1;
	if (f->a->indic_color == 8)
		f->a->indic_color = 0;
	f->a->color = choose_color(f->a->indic_color);
}
