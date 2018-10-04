/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningships.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 20:27:53 by glebouch          #+#    #+#             */
/*   Updated: 2018/03/19 11:25:14 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_burningships(t_s *t)
{
	t->o = 0;
	t->v = -0.53;
	t->cdt_r = -2.05;
	t->cdt_i = -1.3;
	t->fract = 3;
	t->zoom = 220;
	t->it = 150;
}

void	burningships_calc(t_s *t, int x, int y)
{
	int i;

	i = 0;
	t->c_r = x / t->zoom + t->cdt_r + t->o;
	t->c_i = y / t->zoom + t->cdt_i + t->v;
	t->z_r = 0;
	t->z_i = 0;
	while (t->z_r * t->z_r + t->z_i * t->z_i < 4 && i < t->it)
	{
		t->tmp = t->z_r;
		t->z_r = t->z_r * t->z_r - t->z_i * t->z_i + t->c_r;
		t->z_i = fabs(2 * t->z_i * t->tmp) + t->c_i;
		i++;
	}
	ft_get_color(t, x, y, i);
}

void	ft_burningships(t_s *t)
{
	int x;
	int y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			burningships_calc(t, x, y);
			y++;
		}
		x++;
	}
}
