/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 15:12:00 by myuliia           #+#    #+#             */
/*   Updated: 2019/02/05 15:12:01 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	titles(t_fract f)
{
	mlx_string_put(f.w->mlx_ptr, f.w->win_ptr, 670, 730, WHITE,
	" Use: 'arrows' to move");
	mlx_string_put(f.w->mlx_ptr, f.w->win_ptr, 660, 750, WHITE,
	"   'S' to stop mouse");
	mlx_string_put(f.w->mlx_ptr, f.w->win_ptr, 660, 770, WHITE,
	"'SPACE' to change color");
}

void	draw_bird_help(t_fract f, int x, int y, int n)
{
	int color;

	color = color_mandelbrot(n, f, x, y);
	*(int *)(f.w->addr + 4 * WIDTH * y + x * 4) = color;
	f.a->isinside = 0;
}

void	draw_bird(t_fract f, int x, int y)
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
			draw_bird_help(f, x, y, n);
			break ;
		}
		z_im = ((f.a->z_re * f.a->z_re * 3) -
			z_im * z_im) * fabs(z_im) - f.a->c_im;
		f.a->z_re = (f.a->z_re2 -
			(f.a->z_im2 * 3)) * fabs(f.a->z_re) - f.a->c_re;
	}
	if (f.a->isinside)
		*(int *)(f.w->addr + 4 * WIDTH * y + x * 4) = 0;
}
