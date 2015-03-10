/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 07:40:18 by dvolberg          #+#    #+#             */
/*   Updated: 2015/03/09 16:24:04 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == 4)
	{
		e->z *= 1.1;
		if ((int)e->z % 10 == 0)
			e->iter += 1.1;
	}
	else if (button == 5)
	{
		e->z /= 1.1;
		if ((int)e->z % 10 == 0)
			e->iter /= 1.1;
	}
	reexpose_hook_mandelbar(e);
	return (0);
}

int			reexpose_hook_mandelbar(t_env *e)
{
	int	size_l;
	int	endian;

	if (e->img)
		mlx_destroy_image(e->mlx, e->img);
	e->img = mlx_new_image(e->mlx, H, H);
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &size_l, &endian);
	ft_draw_mandelbar(e);
	expose_hook(e);
	return (0);
}

void		ft_set_mandelbar(t_env *e)
{
	e->z = 1;
	e->movex = -0.5;
	e->movey = 0;
	e->iter = 150;
	e->col = 0x10f0000;
}

void		ft_mandelbar(t_env *e)
{
	ft_set_mandelbar(e);
	reexpose_hook_mandelbar(e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop(e->mlx);
}
