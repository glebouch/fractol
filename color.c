/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 20:27:53 by glebouch          #+#    #+#             */
/*   Updated: 2018/03/19 11:25:14 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_get_color(t_s *t, int x, int y, int i)
{
//	ft_putstr("coucou on est dans get color\n");
//	ft_putstr("i dans color ");
//	ft_putnbr(i);
//	ft_putstr("\n");
	if (i == ITMAX)
		*(int *)&(t->ch[y * t->s_line + (t->bpp / 8) * x]) = 0;
	else
		*(int *)&(t->ch[y * t->s_line + (t->bpp / 8) * x]) = (i*255)/ITMAX;
//	else 
//		*(int *)&(t->ch[y * t->s_line + (t->bpp / 8) * x]) = 0xFF0000;

}