/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 02:28:16 by dvolberg          #+#    #+#             */
/*   Updated: 2015/03/09 16:25:48 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_is_julia(t_complexe *new, t_env *e)
{
	t_complexe	old;
	int			i;

	i = 0;
	while (i < e->iter)
	{
		old.r = new->r;
		old.i = new->i;
		new->r = old.r * old.r - old.i * old.i + (e->ju)->rc;
		new->i = 2 * old.r * old.i + (e->ju)->ic;
		if ((new->r * new->r + new->i * new->i) > 4)
			break ;
		i++;
	}
	return (i);
}

void	ft_draw_julia(t_env *e)
{
	t_complexe	n;
	int			color;
	int			x;
	int			y;

	x = 0;
	while (x < H)
	{
		y = 0;
		while (y < H)
		{
			n.r = 1.5 * (x - H / 2) / (0.5 * e->z * H) + e->movex;
			n.i = (y - H / 2) / (0.5 * e->z * H) + e->movey;
			color = (e->col * (ft_is_julia(&n, e) % 0xff));
			ft_put_pixel(e, x, y, color);
			y++;
		}
		x++;
	}
}
