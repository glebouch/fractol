/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 20:27:53 by glebouch          #+#    #+#             */
/*   Updated: 2018/03/19 11:25:14 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>
# include <string.h>
# include <math.h>
# include "./libft/libft.h"

# define WIDTH 800
# define HEIGHT 800
# define EXIT 53
# define KEYUP 126
# define KEYDOWN 125
# define KEYLEFT 123
# define KEYRIGHT 124
# define KEYMINUS 78
# define KEYPLUS 69
# define KEYDEEPER 24
# define KEYLESSDEEP 27
# define KEYI 34
# define KEYP 35
# define KEYO 31
# define KEYJ 38
# define KEYM 46
# define KEYB 11
# define KEYR 15

/*
** # define HEIGHT 800
** # define WIDTH 800
** # define EXIT 65307
** # define KEYUP 65362
** # define KEYDOWN 65364
** # define KEYLEFT 65363
** # define KEYRIGHT 65361
** # define KEYMINUS 65453
** # define KEYPLUS 65451
** # define KEYLESSDEEP 45
** # define KEYDEEPER 61
** # define KEYI 105
** # define KEYP 112
** # define KEYO 111
** # define KEYJ 106
** # define KEYM 109
** # define KEYB 98
** # define KEYR 114
*/

# define KC keycode

typedef struct	s_s
{
	void		*mlx;
	void		*win;
	void		*img;
	int			color;
	int			gamme;
	int			proj;
	int			bpp;
	int			s_line;
	int			endian;
	char		*ch;
	double		o;
	double		v;
	double		cdt_r;
	double		cdt_i;
	int			it;
	int			x;
	int			y;
	double		z_r;
	double		z_i;
	double		c_r;
	double		c_i;
	double		radius;
	double		tmp;
	double		zoom;
	int			*color_table;
	int			fract;
}				t_s;

int				ft_compare_title(char *str);
void			ft_change_fract(t_s *t, int keycode, int i);
void			ft_init(t_s *t);
int				ft_quit(t_s *t);
void			ft_init_julia(t_s *t);
void			ft_julia(t_s *t);
void			ft_init_mandelbrot(t_s *t);
void			ft_mandelbrot(t_s *t);
void			ft_init_burningships(t_s *t);
void			ft_burningships(t_s *t);
void			ft_init_color_table(t_s *t);
void			ft_get_color(t_s *t, int x, int y, int i);
int				ft_key(int keycode, t_s *t);
int				ft_mouse(int x, int y, t_s *t);
int				ft_mouse_button(int button, int x, int y, t_s *t);
void			ft_zoom(t_s *t, double i, int j);

#endif
