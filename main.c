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

#include "fractol.h"

int		ft_quit(t_s *t)
{
	(void)t;
	free(t->color_table);
	exit(1);
}

void	ft_init(t_s *t)
{
	if (t->fract == 1)
		ft_julia(t);
	else if (t->fract == 2)
		ft_mandelbrot(t);
	else if (t->fract == 3)
		ft_burningships(t);
}

int		ft_fractol2(t_s *t)
{
	t->img = mlx_new_image(t->mlx, HEIGHT, WIDTH);
	t->ch = mlx_get_data_addr(t->img, &t->bpp, &t->s_line, &t->endian);
	ft_init(t);
	mlx_put_image_to_window(t->mlx, t->win, t->img, 0, 0);
	mlx_destroy_image(t->mlx, t->img);
	usleep(1);
	return (1);
}

int		ft_fractol(t_s *t)
{
	ft_print_usage();
	ft_change_fract(t, 1, 0);
	t->mlx = mlx_init();
	t->win = mlx_new_window(t->mlx, HEIGHT, WIDTH, "Fractol");
	mlx_hook(t->win, 2, 1L << 0, ft_key, t);
	mlx_hook(t->win, 17, 1L << 17, ft_quit, t);
	mlx_hook(t->win, 6, 64, ft_mouse, t);
	mlx_mouse_hook(t->win, ft_mouse_button, t);
	mlx_loop_hook(t->mlx, ft_fractol2, t);
	mlx_loop(t->mlx);
	return (0);
}

int		main(int ac, char **av)
{
	t_s t;

	srand(time(NULL));
	ft_bzero((void *)&t, sizeof(t));
	t.color = 1;
	t.it = 150;
	if (ac != 2 || (t.fract = ft_compare_title(av[1])) == 0)
	{
		ft_putstr("Usage: ./fractol <fractal>\n \
Fractals :\n\tjulia\n\tmandelbrot\n\tburningship\n");
		return (0);
	}
	else
		ft_fractol(&t);
	return (0);
}
