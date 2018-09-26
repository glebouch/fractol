/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 20:27:53 by glebouch          #+#    #+#             */
/*   Updated: 2018/03/19 11:25:14 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/*
void ft_init_mandelbrot(t_s *t)
{
	t->cdt_r = -2.1;
	t->cdt_i = -1.2;
	ft_mandelbrot(t);
}

int	ft_calcul_mandelbrot(t_s *t, int p_r, int p_i)
{
	unsigned int i = 0;

	t->newI = 0;
	t->newR = 0;
	while (i < ITMAX)
	{	
		t->oldR = t->newR;
		t->oldI = t->newI;
		t->newR = t->oldR * t->oldR - t->oldI * t->oldI + p_r;
		t->newI = 2.0 * t->oldR * t->oldI + p_i;
		if (t->newR * t->newR + t->newI * t->newI >= 4)
		{
//			ft_putstr("i dans mandel ");
//			ft_putnbr(t->newR * t->newR + t->newI * t->newI);
//			ft_putstr("\n");
			return (i);
		}
//		ft_putnbr(t->newR * t->newR + t->newI * t->newI);
//		ft_putstr("fin de boucle\n");
//		ft_putstr("i dans calcul = ");
//		ft_putnbr(i);
//		ft_putstr("\n");
		i++;
	}
	return (i);
}

void	ft_mandelbrot(t_s *t)
{
	unsigned int y;
	unsigned int x;
	double p_r;
	double p_i;

	y = 0;
	while(y < HEIGHT)
	{
		x = 0;
		p_i = y / t->zoom + t->cdt_i + t->v;
		//p_i = (y - HEIGHT / 2.0) / (0.5 * t->zoom * HEIGHT) + t->cdt_i + t->v;
		while(x < WIDTH)
		{
			p_r = x / t->zoom + t->cdt_r + t->o;
			//p_r = 1.5 * (x - WIDTH / 2.0) / (0.5 * t->zoom * WIDTH) + t->cdt_r + t->o;
			ft_get_color(t, x, y, ft_calcul_mandelbrot(t, p_r, p_i));
			x++;
		}
		y++;
	}
}

*/
void	ft_init_mandelbrot(t_s *t)
{
	t->cdt_r = -2.05;
	t->cdt_i = -1.3;
	ft_mandelbrot(t);
}

void	mandelbrot_calc(t_s *t, int x, int y)
{
	int i = 0;
	
	t->c_r = x / t->zoom_m + t->cdt_r + t->o * 30;
	t->c_i = y / t->zoom_m + t->cdt_i + t->v * 30;
	t->z_r = 0;
	t->z_i = 0;
	while (t->z_r * t->z_r + t->z_i * t->z_i < 4 && i < ITMAX)
	{
		t->tmp = t->z_r;
		t->z_r = t->z_r * t->z_r - t->z_i * t->z_i + t->c_r;
		t->z_i = 2 * t->z_i * t->tmp + t->c_i;
		i++;
	}
	ft_get_color(t, x, y, i);
}

void	ft_mandelbrot(t_s *t)
{
	int x = 0;
	int y = 0;

	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			mandelbrot_calc(t, x, y);
			y++;
		}
		x++;
	}
}