/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:19:05 by myuliia           #+#    #+#             */
/*   Updated: 2019/02/04 17:19:06 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_tricorn(t_fract f, int x, int y)
{
	unsigned	n;
	double		z_im;
	int			color;

	f.a->c_re = f.a->min_re + x * f.a->re_factor;
	f.a->z_re = f.a->c_re;
	z_im = f.a->c_im;
	f.a->isinside = 1;
	n = -1;
	while (++n < f.a->max_iterations)
	{
		f.a->z_re2 = f.a->z_re * f.a->z_re;
		f.a->z_im2 = z_im * z_im;
		if (f.a->z_re2 + f.a->z_im2 > 4)
		{
			color = color_mandelbrot(n, f, x, y);
			*(int *)(f.w->addr + 4 * WIDTH * y + x * 4) = color;
			f.a->isinside = 0;
			break ;
		}
		z_im = -1 * (2 * f.a->z_re * z_im) + f.a->c_im;
		f.a->z_re = f.a->z_re2 - f.a->z_im2 + f.a->c_re;
	}
	if (f.a->isinside)
		*(int *)(f.w->addr + 4 * WIDTH * y + x * 4) = 0;
}

void	draw_tricorn_julia(t_fract f, int x, int y)
{
	unsigned	n;
	double		z_im;
	int			color;

	f.a->c_re = f.a->min_re + x * f.a->re_factor;
	f.a->z_re = f.a->c_re;
	z_im = f.a->c_im;
	f.a->isinside = 1;
	n = -1;
	while (++n < f.a->max_iterations)
	{
		f.a->z_re2 = f.a->z_re * f.a->z_re;
		f.a->z_im2 = z_im * z_im;
		if (f.a->z_re2 + f.a->z_im2 > 4)
		{
			color = color_mandelbrot(n, f, x, y);
			*(int *)(f.w->addr + 4 * WIDTH * y + x * 4) = color;
			f.a->isinside = 0;
			break ;
		}
		z_im = -1 * (2 * f.a->z_re * z_im) + f.a->cj_im;
		f.a->z_re = f.a->z_re2 - f.a->z_im2 + f.a->cj_re;
	}
	if (f.a->isinside)
		*(int *)(f.w->addr + 4 * WIDTH * y + x * 4) = 0;
}

void	draw_ship_julia(t_fract f, int x, int y)
{
	unsigned	n;
	double		z_im;
	int			color;

	f.a->c_re = f.a->min_re + x * f.a->re_factor;
	f.a->z_re = f.a->c_re;
	z_im = f.a->c_im;
	f.a->isinside = 1;
	n = -1;
	while (++n < f.a->max_iterations)
	{
		f.a->z_re2 = f.a->z_re * f.a->z_re;
		f.a->z_im2 = z_im * z_im;
		if (f.a->z_re2 + f.a->z_im2 > 4)
		{
			color = color_mandelbrot(n, f, x, y);
			*(int *)(f.w->addr + 4 * WIDTH * y + x * 4) = color;
			f.a->isinside = 0;
			break ;
		}
		z_im = fabs(2 * f.a->z_re * z_im) - f.a->cj_im;
		f.a->z_re = fabs(f.a->z_re2 - f.a->z_im2 + f.a->cj_re);
	}
	if (f.a->isinside)
		*(int *)(f.w->addr + 4 * WIDTH * y + x * 4) = 0;
}

void	draw_buffalo(t_fract f, int x, int y)
{
	unsigned	n;
	double		z_im;
	int			color;

	f.a->c_re = f.a->min_re + x * f.a->re_factor;
	f.a->z_re = f.a->c_re;
	z_im = f.a->c_im;
	f.a->isinside = 1;
	n = -1;
	while (++n < f.a->max_iterations)
	{
		f.a->z_re2 = f.a->z_re * f.a->z_re;
		f.a->z_im2 = z_im * z_im;
		if (f.a->z_re2 + f.a->z_im2 > 4)
		{
			color = color_mandelbrot(n, f, x, y);
			*(int *)(f.w->addr + 4 * WIDTH * y + x * 4) = color;
			f.a->isinside = 0;
			break ;
		}
		z_im = 2 * fabs(f.a->z_re * z_im) - f.a->c_im;
		f.a->z_re = fabs(f.a->z_re2 - f.a->z_im2) + f.a->c_re;
	}
	if (f.a->isinside)
		*(int *)(f.w->addr + 4 * WIDTH * y + x * 4) = 0;
}
