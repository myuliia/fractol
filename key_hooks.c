/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 14:36:50 by myuliia           #+#    #+#             */
/*   Updated: 2019/01/17 14:36:51 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move(t_fract *f, int key)
{
	if (f->a->indic != 3 && f->a->indic != 5)
	{
		if (key == 123)
			f->a->min_re += 0.1;
		if (key == 124)
			f->a->min_re -= 0.1;
		if (key == 125)
			f->a->max_im += 0.1;
		if (key == 126)
			f->a->max_im -= 0.1;
	}
}

int		ft_key_hook(int key, t_fract *f)
{
	if (key == 53)
		exit(0);
	if (key == 49)
	{
				system("./fractol 5&");
		change_color(f);
	}
	if (key == 1)
		change_indicator_mouse(f);
	if (key == 116 || key == 121)
		change_iterations(f, key);
	if (key == 126 || key == 123 || key == 124 || key == 125)
		move(f, key);
	choose_fract(*f);
	return (0);
}
