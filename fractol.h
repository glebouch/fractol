
#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "./libft/libft.h"

/*
# define WIDTH 1000
# define ITMAX 250
# define EXIT 54
# define KEYUP 126
# define KEYDOWN 125
# define KEYLEFT 123
# define KEYRIGHT 124
# define KEYMINUS 78
# define KEYPLUS 69
# define KEYDEEPER 33
# define KEYI 34
# define KEYP 35
# define KEYO 31
# define KEYJ 31
# define KEYM 31
# define FDIM 1000
# define R 15
# define V 9
# define B 11
*/

# define HEIGHT 800
# define WIDTH 800
# define ITMAX 155
# define EXIT 65307
# define KEYUP 65362
# define KEYDOWN 65364
# define KEYLEFT 65363
# define KEYRIGHT 65361
# define KEYMINUS 65453
# define KEYPLUS 65451
# define KEYLESSDEEP 65453
# define KEYDEEPER 65451
# define KEYI 105
# define KEYP 112
# define KEYO 111
# define KEYJ 106
# define KEYM 109
# define FDIM 1000
# define R 114
# define V 118
# define B 98


# define KC keycode

typedef struct	s_complex
{
	int			x;
	int			y;
}				t_complex;

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
	double		newR;
	double		newI;
	double		oldR;
	double		oldI;

	double		z_r;
	double		z_i;
	double		c_r;
	double		c_i;
	double		tmp;
	double		zoom_j;
	double		zoom_m;
	double		deep;
	int			fract;
	t_complex	complex;
}				t_s;

int				ft_quit(t_s *t);
void			ft_init(t_s *t);
void			ft_get_color(t_s *t, int x, int y, int i);
int				ft_compare_title(char *str);
void			ft_julia(t_s *t);
void			ft_init_mandelbrot(t_s *t);
void			ft_mandelbrot(t_s *t);

#endif