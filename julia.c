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
	t->o = 0;
	t->v = 0;
	t->radius = 0;
	t->fract = 1;
	t->zoom = 200;
	t->cdt_r = 0;
	t->cdt_i = 0;
	t->it = 150;
}

void	ft_calcul_julia(int x, int y, t_s *t)
{
//	ft_putstr("c'est calcul_julia\n");
	double x1 = -2.0;
	double y1 = -1.9;
	int i = 0;

	t->z_r = x / t->zoom + x1 + t->o;
	t->z_i = y / t->zoom + y1 + t->v;
	while (t->z_r * t->z_r + t->z_i * t->z_i < 4 && i < t->it)
	{
		t->tmp = t->z_r;
		t->z_r = t->z_r * t->z_r - t->z_i * t->z_i + t->cdt_r;
		t->z_i = 2 * t->z_i * t->tmp + t->cdt_i;

		i++;
	}
	ft_get_color(t, x, y, i);
//	mlx_put_image_to_window(t->mlx, t->win, t->img, 0, 0);
}

void	ft_julia(t_s *t)
{
//	ft_putstr("on est dans ft_julia\n");
//	printf("cdtr et i = %lf %lf", t->cdt_r, t->cdt_i);
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