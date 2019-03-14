/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 16:59:02 by myuliia           #+#    #+#             */
/*   Updated: 2019/02/04 16:42:49 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		color_mandelbrot(int n, t_fract f, unsigned x, unsigned y)
{
	if (n > 0 && n <= f.a->max_iterations)
		return (f.a->color * n);
	return (0);
}

void	choose_fract(t_fract f)
{
	unsigned	y;
	unsigned	x;

	y = -1;
	while (++y < HEIGHT)
	{
		f.a->c_im = f.a->max_im - y * f.a->im_factor;
		x = -1;
		while (++x < WIDTH)
		{
			IF_MANDEL(f.a->indic == 1);
			IF_JULIA(f.a->indic == 2);
			IF_SHIP(f.a->indic == 3);
			IF_JSHIP(f.a->indic == 4);
			IF_BIRD(f.a->indic == 8);
			if (f.a->indic == 5)
				draw_tricorn(f, x, y);
			if (f.a->indic == 6)
				draw_tricorn_julia(f, x, y);
			if (f.a->indic == 7)
				draw_buffalo(f, x, y);
		}
	}
	mlx_put_image_to_window(f.w->mlx_ptr, f.w->win_ptr, f.w->img_ptr, 0, 0);
	titles(f);
}

void	draw_mandelbrot(t_fract f, int x, int y)
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
		z_im = 2 * f.a->z_re * z_im + f.a->c_im;
		f.a->z_re = f.a->z_re2 - f.a->z_im2 + f.a->c_re;
	}
	if (f.a->isinside)
		*(int *)(f.w->addr + 4 * WIDTH * y + x * 4) = 0;
}

void	draw_ship(t_fract f, int x, int y)
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
		z_im = fabs(2 * f.a->z_re * z_im) - f.a->c_im;
		f.a->z_re = fabs(f.a->z_re2 - f.a->z_im2 + f.a->c_re);
	}
	if (f.a->isinside)
		*(int *)(f.w->addr + 4 * WIDTH * y + x * 4) = 0;
}

void	draw_julia(t_fract f, int x, int y)
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
		z_im = 2 * f.a->z_re * z_im + f.a->cj_im;
		f.a->z_re = f.a->z_re2 - f.a->z_im2 + f.a->cj_re;
	}
	if (f.a->isinside)
		*(int *)(f.w->addr + 4 * WIDTH * y + x * 4) = 0;
}
