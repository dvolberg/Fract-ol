/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_mandel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 07:53:16 by dvolberg          #+#    #+#             */
/*   Updated: 2015/03/09 16:24:00 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_is_mandel(t_complexe *p, t_env *e)
{
	t_complexe	old;
	t_complexe	new;
	int			i;

	i = 0;
	new.r = 0;
	new.i = 0;
	while (i < e->iter)
	{
		old.r = new.r;
		old.i = new.i;
		new.r = old.r * old.r - old.i * old.i + p->r;
		new.i = 2 * old.r * old.i + p->i;
		if ((new.r * new.r + new.i * new.i) > 4)
			break ;
		i++;
	}
	if (i == e->iter)
		return (0);
	return (i);
}

void	ft_draw_mandel(t_env *e)
{
	t_complexe	p;
	int			color;
	int			x;
	int			y;

	x = 0;
	while (x < H)
	{
		y = 0;
		while (y < H)
		{
			p.r = 1.5 * (x - H / 2) / (0.5 * e->z * H) + e->movex;
			p.i = (y - H / 2) / (0.5 * e->z * H) + e->movey;
			color = (e->col * (ft_is_mandel(&p, e) % 0xff));
			ft_put_pixel(e, x, y, color);
			y++;
		}
		x++;
	}
}
