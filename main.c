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

void		ft_change_fract(t_s *t, int KC)
{
	if (KC == KEYJ || t->fract == 1)
	{
		t->fract = 1;
		t->zoom = 200;
		t->var_zoom = 20;
	}
	if (KC == KEYM || t->fract == 2)
	{
		t->fract = 2;
		t->zoom = 300;
		t->var_zoom = 30;
	}
}

int		ft_key(int keycode, t_s *t)
{
	printf("%d\n", keycode);
	printf("%e\n", t->zoom);
	if (KC == EXIT)
		exit(1);
	if (KC == KEYUP || KC == KEYDOWN)
		t->v = (KC == KEYUP) ? t->v + 0.1/t->zoom : t->v - 0.1/t->zoom;
	if (KC == KEYLEFT || KC == KEYRIGHT)
		t->o = (KC == KEYLEFT) ? t->o - 0.1/t->zoom : t->o + 0.1/t->zoom;
	if ((KC == KEYMINUS && t->zoom > 0) || (KC == KEYPLUS))
		t->zoom = (KC == KEYMINUS) ? t->zoom - t->var_zoom : t->zoom + t->var_zoom;
	if (KC == KEYJ || KC == KEYM)
		ft_change_fract(t, KC);
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

/*int		ft_fractol2(t_s *t)
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
	ft_change_fract(t, 1);
	t->mlx = mlx_init();
	t->win = mlx_new_window(t->mlx, HEIGHT, WIDTH, "Fractol");
	mlx_hook(t->win, 2, 1L << 0, ft_key, t);
	mlx_hook(t->win, 17, 1L << 17, ft_quit, t);
	mlx_hook(t->win, 6, 1L < 6, ft_mouse, t);
	mlx_mouse_hook(data->win, mouse_hook, data);
	mlx_loop_hook(t->mlx, ft_fractol2, t);
	mlx_loop(t->mlx);
	return (0);
}*/
void	ft_init_win(t_s *t)
{	
	t->mlx = mlx_init();
	t->win = mlx_new_window(t->mlx, HEIGHT, WIDTH, "Fractol");
	t->img = mlx_new_image(t->mlx, HEIGHT, WIDTH);
	t->ch = mlx_get_data_addr(t->img, &t->bpp, &t->s_line, &t->endian);
}

int		ft_fractol(t_s *t)
{
//	ft_putstr("coucouc on est dans fractol\n");
//	ft_change_fract(t, 1);
	ft_init_win(t);
	ft_init(t);
	mlx_hook(t->win, 6, 1L < 6, ft_mouse, t);
	mlx_hook(t->win, 2, 1L << 0, ft_key, t);
	mlx_hook(t->win, 17, 1L << 17, ft_quit, t);
	mlx_key_hook(t->win, ft_key, t);
//	mlx_loop_hook(t->mlx, ft_fractol2, t);
	mlx_loop(t->mlx);
//	mlx_destroy_image(t->mlx, t->img);
	return (0);
}

int		main(int ac, char **av)
{
	(void)ac;
	ft_putstr("totoro\n");
	t_s t;
	t.o = 0;
	t.v = 0;
	t.cdt_r = 0;
	t.cdt_i = 0;
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
	{
		ft_change_fract(&t, 1);
		ft_fractol(&t);
	}
	ft_putstr("totoro\n");
	return (0);
}