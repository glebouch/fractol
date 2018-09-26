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
			t->newR = 1.5 * (x - HEIGHT / 2) / (0.5 * t->zoom_j * WIDTH) + t->o;
			t->newI = (y - WIDTH / 2) / (0.5 * t->zoom_j * WIDTH) + t->v;
			ft_get_color(t, x, y, ft_calcul_julia(t));
			x++;
		}
		y++;
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