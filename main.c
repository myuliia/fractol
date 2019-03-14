/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:44:03 by myuliia           #+#    #+#             */
/*   Updated: 2019/01/24 13:44:04 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
int	main(int argc, char **argv)
{
	t_fract f;
	int i;
	time_t t;

	srand((unsigned) time(&t));
	i = rand() % 50;
	printf("%d\n", i);
	if (argc != 2)
		ft_error(1);
	f.w = initialize();
	if (!f.a)
		f.a = filling(argv[1]);
	choose_fract(f);
	mlx_hook(f.w->win_ptr, 17, 0, destroy, NULL);
	mlx_hook(f.w->win_ptr, 2, 0, ft_key_hook, &f);
	mlx_hook(f.w->win_ptr, 4, 0, apply_zoom, &f);
	if (f.a->indic == 2 || f.a->indic == 4 || f.a->indic == 6)
		mlx_hook(f.w->win_ptr, 6, 0, mouse_julia, &f);
	mlx_loop(f.w->mlx_ptr);
	return (0);
}
