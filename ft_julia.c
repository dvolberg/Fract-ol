/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 01:27:08 by dvolberg          #+#    #+#             */
/*   Updated: 2015/03/09 16:24:02 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == 4)
	{
		e->z *= 1.1;
		if ((int)e->z % 10 == 0)
			e->iter *= 1.1;
	}
	else if (button == 5)
	{
		e->z /= 1.1;
		if ((int)e->z % 10 == 0)
			e->iter /= 1.1;
	}
	else if (button == 1)
	{
		(e->ju)->rc = -0.7;
		(e->ju)->ic = 0.27015;
	}
	reexpose_hook_ju(e);
	return (0);
}

int			reexpose_hook_ju(t_env *e)
{
	int	size_l;
	int	endian;

	if (e->img)
		mlx_destroy_image(e->mlx, e->img);
	e->img = mlx_new_image(e->mlx, H, H);
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &size_l, &endian);
	ft_draw_julia(e);
	expose_hook(e);
	return (0);
}

void		ft_set_julia(t_julia *ju, t_env *e)
{
	ju->rc = -0.7;
	ju->ic = 0.27015;
	e->z = 1;
	e->movex = 0;
	e->movey = 0;
	e->iter = 150;
	e->col = 0x0000ef;
	ju->oldx = 200;
	ju->oldy = 200;
}

int			hook(int x, int y, t_env *e)
{
	if (x > (e->ju)->oldx)
		(e->ju)->rc += 0.005 / e->z;
	else
		(e->ju)->rc -= 0.005 / e->z;
	if (y > (e->ju)->oldy)
		(e->ju)->ic += 0.005 / e->z;
	else
		(e->ju)->ic -= 0.005 / e->z;
	(e->ju)->oldx = x;
	(e->ju)->oldy = y;
	reexpose_hook_ju(e);
	return (0);
}

void		ft_julia(t_env *e)
{
	t_julia ju;

	ft_set_julia(&ju, e);
	e->ju = &ju;
	reexpose_hook_ju(e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_hook(e->win, 6, (1L << 6), hook, e);
	mlx_loop(e->mlx);
}
