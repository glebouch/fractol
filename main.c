/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 20:27:53 by glebouch          #+#    #+#             */
/*   Updated: 2018/03/19 11:25:14 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*for 42 add KEYR rm var_zoom, d, all old and new and useless t elems SRC = main.c hook.c color.c julia.c mandelbrot.c burningships.c*/


#include "fractol.h"

void ft_init_color_table(t_s *t)
{
	int i = 0;

	t->color_table = (int*)malloc(sizeof(int) * t->it);
	while (i < t->it)
	{
		t->color_table[i] = rand() % 0x1000000;
		i++;
	}
}

void		ft_change_fract(t_s *t, int KC, int i)
{
	ft_putstr("passe par change fract\n");
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

void ft_zoom(t_s *t, double i, int j)
{
	t->zoom = t->zoom * i;
	t->o += j * 0.1 * (double)t->x / t->zoom;
	t->v += j * 0.1 * (double)t->y / t->zoom;
//	t->o = (KC == KEYUP) ? t->o + t->d/t->zoom : t->o - t->d/t->zoom;
}

int		ft_quit(t_s *t)
{
	(void)t;
	free (t->color_table);
	free (t->mlx);
	free (t->win);
	free (t->img);
	free (t->ch);
	free(t);
	exit(1);
}

void	ft_init(t_s *t)
{
//	ft_putstr("coucou ici ft_init\n");
	if (t->fract == 1)
		ft_julia(t);
	else if (t->fract == 2)
		ft_mandelbrot(t);
	else if (t->fract == 3)
		ft_burningships(t);
}

int		ft_fractol2(t_s *t)
{
//	ft_putstr("coucouc on est dans fractol2\n");
	t->img = mlx_new_image(t->mlx, HEIGHT, WIDTH);
	t->ch = mlx_get_data_addr(t->img, &t->bpp, &t->s_line, &t->endian);
//	ft_putstr("before ft_init\n");
	ft_init(t);
//	ft_putstr("after ft_init\n");
	mlx_put_image_to_window(t->mlx, t->win, t->img, 0, 0);
	mlx_destroy_image(t->mlx, t->img);
	usleep(1);
	return (1);
}

int		ft_fractol(t_s *t)
{
	ft_putstr("coucouc on est dans fractol\n");
	ft_change_fract(t, 1, 0);
	t->mlx = mlx_init();
	t->win = mlx_new_window(t->mlx, HEIGHT, WIDTH, "Fractol");
	mlx_hook(t->win, 2, 1L << 0, ft_key, t);
	mlx_hook(t->win, 17, 1L << 17, ft_quit, t);
//	mlx_hook(t->win, 6, 1L < 6, ft_mouse, t);
//	mlx_mouse_hook(t->win, ft_mouse, t);
	mlx_hook(t->win, 6, 64, ft_mouse, t);
	mlx_mouse_hook(t->win, ft_mouse_button, t);
	mlx_loop_hook(t->mlx, ft_fractol2, t);
	mlx_loop(t->mlx);
	return (0);
}

int ft_compare_title(char *str)
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

int		main(int ac, char **av)
{
//	ft_putstr("totoro\n");
	t_s t;

	ft_bzero((void *)&t, sizeof(t));
	t.color_table = NULL;
	t.it = 150;
	if (ac != 2 || (t.fract = ft_compare_title(av[1])) == 0)
	{
		ft_putstr("Usage: ./fractol <fractal>\nFractals :\n\tjulia\n\tmandelbrot\n\tburningship\n");
		return (0);
	}
	else
		ft_fractol(&t);
	ft_putstr("totoro\n");
	return (0);
}