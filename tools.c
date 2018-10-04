/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 20:27:53 by glebouch          #+#    #+#             */
/*   Updated: 2018/03/19 11:25:14 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_color_table(t_s *t)
{
	int i;

	i = 0;
	t->color_table = (int*)malloc(sizeof(int) * t->it);
	while (i < t->it)
	{
		t->color_table[i] = rand() % 0xFFFF + 1;
		i++;
	}
}

void	ft_change_fract(t_s *t, int keycode, int i)
{
	if (i != 0)
		free(t->color_table);
	ft_init_color_table(t);
	if (KC == KEYJ || t->fract == 1)
		ft_init_julia(t);
	if (KC == KEYM || t->fract == 2)
		ft_init_mandelbrot(t);
	if (KC == KEYB || t->fract == 3)
		ft_init_burningships(t);
}

void	ft_zoom(t_s *t, double i, int j)
{
	t->zoom = t->zoom * i;
	t->o += j * 0.1 * (double)t->x / t->zoom;
	t->v += j * 0.1 * (double)t->y / t->zoom;
}

int		ft_compare_title(char *str)
{
	if (str != NULL && ft_strcmp(str, "julia") == 0)
		return (1);
	else if (strcmp(str, "mandelbrot") == 0)
		return (2);
	else if (strcmp(str, "burningship") == 0)
		return (3);
	else
		return (0);
}

void	ft_get_color(t_s *t, int x, int y, int i)
{
	if (i == t->it)
		*(int *)&(t->ch[y * t->s_line + (t->bpp / 8) * x]) = 0;
	else
		*(int *)&(t->ch[y * t->s_line + (t->bpp / 8) * x]) = t->color_table[i];
}
