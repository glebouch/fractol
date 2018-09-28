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

void	ft_init_mandelbrot(t_s *t)
{
	t->cdt_r = -2.05;
	t->cdt_i = -1.3;
	ft_mandelbrot(t);
}

void	mandelbrot_calc(t_s *t, int x, int y)
{
	int i = 0;
	
	t->c_r = x / t->zoom + t->cdt_r + t->o * 30;
	t->c_i = y / t->zoom + t->cdt_i + t->v * 30;
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
	mlx_put_image_to_window(t->mlx, t->win, t->img, 0, 0);
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