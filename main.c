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

# include "fractol.h"


int		ft_key(int keycode, t_s *t)
{
	printf("%d\n", keycode);
	ft_putnbr(t->zoom_m);
	if (KC == EXIT)
		exit(1);
	if (KC == KEYUP || KC == KEYDOWN)
	{
		if (t->fract == 1)
			t->v = (KC == KEYUP) ? t->v + 0.1/t->zoom_j : t->v - 0.1/t->zoom_j;
		else if (t->fract == 2)
			t->v = (KC == KEYUP) ? t->v + 0.1/t->zoom_m : t->v - 0.1/t->zoom_m;
	}
	if (KC == KEYLEFT || KC == KEYRIGHT)
	{
		if (t->fract == 1)
			t->o = (KC == KEYLEFT) ? t->o - 0.1/t->zoom_j : t->o + 0.1/t->zoom_j;
		else if (t->fract == 2)
			t->o = (KC == KEYLEFT) ? t->o - 0.1/t->zoom_m : t->o + 0.1/t->zoom_m;
	}
	if ((t->fract == 1) && ((KC == KEYMINUS && t->zoom_j > 0) || (KC == KEYPLUS && t->zoom_j >= 0)))
		t->zoom_j = (KC == KEYMINUS) ? t->zoom_j - 2 : t->zoom_j + 2;
	if ((t->fract == 2) && ((KC == KEYMINUS && t->zoom_m > 0) || (KC == KEYPLUS && t->zoom_m >= 0)))
		t->zoom_m = (KC == KEYMINUS) ? t->zoom_m - 100 : t->zoom_m + 100;
	if (KC == KEYJ || KC == KEYM)
		t->fract = (KC == KEYJ) ? 1 : 2;
	if (KC == R || KC == V || KC == B)
	{
		if (KC == R)
			t->gamme = 'r';
		else if (KC == V)
			t->gamme = 'v';
		else
			t->gamme = 'b';
	}
	return (0);
}

int		ft_quit(t_s *t)
{
	free(t);
	exit(1);
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
	return (1);
}

int		ft_fractol(t_s *t)
{
	ft_putstr("coucouc on est dans fractol\n");
	t->mlx = mlx_init();
	t->win = mlx_new_window(t->mlx, HEIGHT, WIDTH, "Fractol");
	mlx_hook(t->win, 2, 1L << 0, ft_key, t);
	mlx_hook(t->win, 17, 1L << 17, ft_quit, t);
	mlx_loop_hook(t->mlx, ft_fractol2, t);
	mlx_loop(t->mlx);
	return (0);
}

int		main(int ac, char **av)
{
	(void)ac;
	ft_putstr("totoro\n");
	t_s t;
	t.zoom_j = 2;
	t.zoom_m = 300;
	t.o = 0;
	t.v = 0;
//	ft_bzero((void)t, sizeof(t));
	ft_putstr("totoro\n");
	ft_putstr(av[1]);
	ft_putstr("!\n");
	if ((t.fract = ft_compare_title(av[1])) == 0)
	{
		ft_putstr("out\n");
		return (0);
	}
	else
		ft_fractol(&t);
	ft_putstr("totoro\n");
	return (0);
}