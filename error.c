/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 16:43:20 by myuliia           #+#    #+#             */
/*   Updated: 2019/01/16 16:44:53 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_error(int n)
{
	if (n == 1)
	{
		write(1, ERROR, 50);
		write(1, " / [6] / [7]\n\n", 14);
		write(1, "  1. mandelbrot set\n", 20);
		write(1, "  2. julia\n", 11);
		write(1, "  3. burning ship\n", 18);
		write(1, "  4. burning ship julia\n", 25);
		write(1, "  5. tricorn\n", 13);
		write(1, "  6. tricorn julia\n", 19);
		write(1, "  7. buffalo\n", 13);
		write(1, "  8. bird\x1b[0m\n\n", 15);
	}
	if (n == 2)
		write(1, "\x1b[33mI have no idea what to draw, sorry)\x1b[0m\n", 45);
	exit(0);
}

int	destroy(void)
{
	exit(1);
}
