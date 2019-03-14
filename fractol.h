/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 16:36:21 by myuliia           #+#    #+#             */
/*   Updated: 2019/01/16 16:36:22 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "./libft/libft.h"
# include <mlx.h>
# include <stdlib.h>
# include <pthread.h>
# define WIDTH 900
# define HEIGHT 800
# define WHITE 16777215
# define GREEN 00010000
# define RED 001400000
# define BLUE 000000010
# define PINK 003000010
# define MARSALA 05000200
# define BLACK 001002004
# define YELLOW 100000000
# define BLU 001001202
# define THREADS 4
# define ERROR "\n\x1b[33musage: ./fractol [1] / [2] / [3] / [4] / [5]"
# define IF_MANDEL(z) {if (z) {draw_mandelbrot(f, x, y);}}
# define IF_JULIA(z) {if (z) {draw_julia(f, x, y);}}
# define IF_SHIP(z) {if (z) {draw_ship(f, x, y);}}
# define IF_JSHIP(z) {if (z) {draw_ship_julia(f, x, y);}}
# define IF_BIRD(z) {if (z) {draw_bird(f, x, y);}}

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*addr;
	int			bits;
	int			line_size;
	int			endian;
}				t_mlx;

typedef struct	s_alg
{
	double		min_re;
	double		max_re;
	double		min_im;
	double		max_im;
	double		re_factor;
	double		im_factor;
	unsigned	max_iterations;
	int			color;
	int			indic;
	int			indic_color;
	int			indic_mouse_julia;
	int			isinside;
	double		cj_re;
	double		cj_im;
	double		c_re;
	double		z_re;
	double		z_re2;
	double		z_im2;
	double		c_im;
}				t_alg;

typedef struct	s_fract
{
	int			s_ind;
	int			ind;
	int			tmp;
	t_mlx		*w;
	t_alg		*a;

}				t_fract;

int				ft_error(int n);
int				destroy(void);
int				ft_key_hook(int key, t_fract *f);
int				color_mandelbrot(int n, t_fract f, unsigned x, unsigned y);
void			draw_mandelbrot(t_fract f, int x, int y);
void			draw_julia(t_fract f, int x, int y);
void			draw_ship(t_fract f, int x, int y);
void			draw_ship_julia(t_fract f, int x, int y);
void			draw_tricorn(t_fract f, int x, int y);
void			draw_tricorn_julia(t_fract f, int x, int y);
void			draw_buffalo(t_fract f, int x, int y);
void			draw_bird(t_fract f, int x, int y);
void			draw_bird_help(t_fract f, int x, int y, int n);
void			fill(t_fract f);
t_mlx			*initialize(void);
t_alg			*filling();
void			choose_fract(t_fract f);
void			titles(t_fract f);
int				mouse_julia(int x, int y, t_fract *f);
int				apply_zoom_down(t_fract *f, double x, double y, double zoom);
int				apply_zoom_up(t_fract *f, double x, double y, double zoom);
int				apply_zoom(int button, int x, int y, t_fract *f);
int				choose_color(int n);
void			change_color(t_fract *f);
void			change_iterations(t_fract *f, int key);
void			change_indicator_mouse(t_fract *f);

#endif
