/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 01:14:28 by dvolberg          #+#    #+#             */
/*   Updated: 2015/03/09 16:24:05 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_put_pixel(t_env *e, int x, int y, int col)
{
	if (0 < x && x < H && 0 < y && y < H)
		ft_memcpy(&e->data[(y * e->bpp / 8) + (x * (e->bpp / 8) * H)], &col, 4);
}

int		expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

void	reexpose_hook(t_env *e)
{
	if (e->arg == 1)
		reexpose_hook_ju(e);
	else if (e->arg == 2)
		reexpose_hook_mandel(e);
	else if (e->arg == 3)
		reexpose_hook_mandelbar(e);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 65307)
		exit(0);
	else if (keycode == 65362)
		e->movex -= 0.05 / e->z;
	else if (keycode == 65364)
		e->movex += 0.05 / e->z;
	else if (keycode == 65361)
		e->movey -= 0.05 / e->z;
	else if (keycode == 65363)
		e->movey += 0.05 / e->z;
	else if (keycode == 'r')
		e->col += 0x100000;
	else if (keycode == 'e')
		e->col -= 0x100000;
	else if (keycode == 'g')
		e->col += 0x001000;
	else if (keycode == 'f')
		e->col -= 0x001000;
	else if (keycode == 'b')
		e->col += 0x000010;
	else if (keycode == 'v')
		e->col -= 0x000010;
	reexpose_hook(e);
	return (0);
}

void	ft_fractol(int arg)
{
	t_env e;

	e.arg = arg;
	if (!(e.mlx = mlx_init()))
	{
		ft_putstr("mlx error\n");
		exit(-1);
	}
	if (!(e.win = mlx_new_window(e.mlx, H, H, "Fractol")))
	{
		ft_putstr("mlx error\n");
		exit (-1);
	}
	e.img = NULL;
	if (arg == 1)
		ft_julia(&e);
	else if (arg == 2)
		ft_mandel(&e);
	else if (arg == 3)
		ft_mandelbar(&e);
	else if (arg == 4)
		help_menu();
}
