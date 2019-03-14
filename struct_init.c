/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 15:34:43 by myuliia           #+#    #+#             */
/*   Updated: 2019/01/24 15:34:44 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		choose_color(int n)
{
	int color_c[8];

	color_c[0] = BLACK;
	color_c[1] = BLUE;
	color_c[2] = RED;
	color_c[3] = GREEN;
	color_c[4] = PINK;
	color_c[5] = MARSALA;
	color_c[6] = YELLOW;
	color_c[7] = BLU;
	return (color_c[n]);
}

t_mlx	*initialize(void)
{
	t_mlx	*w;

	w = (t_mlx *)malloc(sizeof(t_mlx));
	w->mlx_ptr = mlx_init();
	w->win_ptr = mlx_new_window(w->mlx_ptr, WIDTH, HEIGHT, "Fractol");
	w->img_ptr = mlx_new_image(w->mlx_ptr, WIDTH, HEIGHT);
	w->addr = mlx_get_data_addr(w->img_ptr,
		&w->bits, &w->line_size, &w->endian);
	return (w);
}

void	indicator_of_fract(t_alg *a, char *argv)
{
	if (!strcmp(argv, "1"))
		a->indic = 1;
	else if (!strcmp(argv, "2"))
		a->indic = 2;
	else if (!strcmp(argv, "3"))
		a->indic = 3;
	else if (!strcmp(argv, "4"))
		a->indic = 4;
	else if (!strcmp(argv, "5"))
		a->indic = 5;
	else if (!strcmp(argv, "6"))
		a->indic = 6;
	else if (!strcmp(argv, "7"))
		a->indic = 7;
	else if (!strcmp(argv, "8"))
		a->indic = 8;
	else
		ft_error(2);
}

t_alg	*filling(char *argv)
{
	t_alg	*a;

	a = (t_alg *)malloc(sizeof(t_alg));
	a->min_re = -2.0;
	a->max_re = 1.0;
	a->min_im = -1.2;
	a->max_im = a->min_im + (a->max_re - a->min_re) * HEIGHT / WIDTH;
	a->re_factor = (a->max_re - a->min_re) / (WIDTH - 1);
	a->im_factor = (a->max_im - a->min_im) / (HEIGHT - 1);
	a->max_iterations = 100;
	a->cj_im = 0;
	a->cj_re = 0;
	a->indic_mouse_julia = 1;
	a->indic_color = 0;
	a->color = BLACK;
	indicator_of_fract(a, argv);
	return (a);
}
