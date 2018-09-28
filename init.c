/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 20:27:53 by glebouch          #+#    #+#             */
/*   Updated: 2018/03/19 11:25:14 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*int		ft_mouse(int x, int y, t_s *t)
{
	t->cdt_r = (x - WIDTH/2) / (WIDTH/2);
	t->cdt_i = (y - WIDTH/2) / (WIDTH/2);
	ft_julia(t);
	return (0);
}

void	ft_init_julia(t_s *t)
{
//	ft_putstr("coucou ici ft_init_julia\n");
	t->cdt_r = -0.85;
	t->cdt_i = 0.2;
	ft_julia(t);
}

int	ft_calcul_julia(t_s *t)
{
	int i = 0;
	while (i < ITMAX)
	{	
		t->oldR = t->newR;
		t->oldI = t->newI;
		t->newR = t->oldR * t->oldR - t->oldI * t->oldI + t->cdt_r;
		t->newI = 2 * t->oldR * t->oldI + t->cdt_i;
		if (t->newR * t->newR + t->newI * t->newI > 4)
			return (i);
//		ft_putnbr(t->newR * t->newR + t->newI * t->newI);
//		ft_putstr("fin de boucle\n");
//		ft_putstr("i dans calcul = ");
//		ft_putnbr(i);
//		ft_putstr("\n");
		i++;
	}
	return (i);
	
}

void	ft_julia(t_s *t)
{
//	ft_putstr("coucou ici ft_julia\n");
	int y = 0;
	int x;
	while(y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			t->newR = 1.5 * (x - HEIGHT / 2) / (0.5 * t->zoom * WIDTH) + t->o;
			t->newI = (y - WIDTH / 2) / (0.5 * t->zoom * WIDTH) + t->v;
			ft_get_color(t, x, y, ft_calcul_julia(t));
			x++;
		}
		y++;
	}
}*/

int		ft_mouse(t_s *t, int x, int y)
{
	if (t->fract == 1)
	{
		t->cdt_r = x * 2;
		t->cdt_i = y * 2 - 800;
		printf("%lf %lf\n", t->cdt_i, t->cdt_r);
		ft_julia(t);
	}
	return (0);
}

void	ft_init_julia(t_s *t)
{
//	t->cdt_r = 0.285;
//	t->cdt_i = 0.01;
	ft_julia(t);
}

void	ft_calcul_julia(int x, int y, t_s *t)
{
	double x1 = -2.0;
	double y1 = -1.9;
	int i = 0;

	t->z_r = x / t->zoom + x1 + t->o;
	t->z_i = y / t->zoom + y1 + t->v;
	while (t->z_r * t->z_r + t->z_i * t->z_i < 4 && i < ITMAX)
	{
		t->tmp = t->z_r;
		t->z_r = t->z_r * t->z_r - t->z_i * t->z_i - 0.8 + (t->cdt_r / WIDTH);
		t->z_i = 2 * t->z_i * t->tmp + t->cdt_i / WIDTH;
		i++;
	}
	ft_get_color(t, x, y, i);
	mlx_put_image_to_window(t->mlx, t->win, t->img, 0, 0);
}

void	ft_julia(t_s *t)
{
	int x = 0;
	int y;

	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			ft_calcul_julia(x, y, t);
			y++;
		}
		x++;
	}
}


int ft_compare_title(char *str)
{
	if (str != NULL && ft_strcmp(str, "julia") == 0)
	{
//		ft_putstr("c'est julia\n");
		return (1);
	}
	else if ((strcmp(str, "mandelbrot") == 0) || (ft_strcmp(str, "Mandelbrot") == 0))
		return (2);
	else if ((strcmp(str, "troisieme") == 0) || (ft_strcmp(str, "Troisieme") == 0))
		return (3);
	else
		return 0;
}

void	ft_init(t_s *t)
{
//	ft_putstr("coucou ici ft_init\n");
	if (t->fract == 1)
		ft_init_julia(t);
	else if (t->fract == 2)
		ft_init_mandelbrot(t);
//	else
//		ft_init_fract3(t);
}