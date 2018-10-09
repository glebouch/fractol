/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 20:27:53 by glebouch          #+#    #+#             */
/*   Updated: 2018/03/19 11:25:14 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_key(int keycode, t_s *t)
{
	if (KC == EXIT)
		exit(1);
	if (KC == KEYR)
		t->radius = (t->radius == 0) ? 1 : 0;
	if (KC == KEYUP || KC == KEYDOWN)
		t->v = (KC == KEYUP) ? t->v + 10 / t->zoom : t->v - 10 / t->zoom;
	if (KC == KEYLEFT || KC == KEYRIGHT)
		t->o = (KC == KEYLEFT) ? t->o - 10 / t->zoom : t->o + 10 / t->zoom;
	if (KC == KEYMINUS && t->zoom > 0)
		ft_zoom(t, 0.9, -1);
	if (KC == KEYPLUS)
		ft_zoom(t, 1.1, 1);
	if (KC == KEYJ || KC == KEYM || KC == KEYB)
		ft_change_fract(t, KC, 1);
	if (KC == KEYLESSDEEP || KC == KEYDEEPER)
		t->it += (KC == KEYLESSDEEP) ? -3 : 3;
	if (KC == KEYC)
		t->color = (t->color == 0) ? 1 : 0;
	return (0);
}

int		ft_mouse_button(int button, int x, int y, t_s *t)
{
	t->x = x;
	t->y = y;
	if (button == 4)
		ft_zoom(t, 1.1, 1);
	if (button == 5)
		ft_zoom(t, 0.9, -1);
	if (button == 1)
		t->radius = (t->radius == 1) ? 0 : 1;
	return (0);
}

int		ft_mouse(int x, int y, t_s *t)
{
	t->x = x;
	t->y = y;
	if (t->fract == 1 && t->radius == 1 &&
		(x >= 0 && x < WIDTH && y >= 0 && y < WIDTH))
	{
		t->cdt_r = (double)(x - 400) / (400);
		t->cdt_i = (double)(y - 400) / (400);
	}
	return (0);
}

int		ft_print_usage(void)
{
	ft_putstr("Change the type of fractal with J, M or B key\n\
Increase or decrease iteration max with [ and ] key\n\
Change colors with C key\n\
Unlock and lock the mouse changes with R key or left click\n\
Zoom in and out with - and + key or the mouse wheel\n\
Move with keyboard arrows\n\
Quit with esc\n");
	return (0);
}
