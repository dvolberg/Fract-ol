/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 01:03:27 by dvolberg          #+#    #+#             */
/*   Updated: 2015/03/09 16:24:06 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include <mlx.h>
# include <math.h>
# define H 800

/*
** Structures :
*/
typedef struct	s_julia
{
	double	rc;
	double	ic;
	int		oldx;
	int		oldy;
}				t_julia;
typedef struct	s_env
{
	void	*mlx;
	void	*win;
	int		bpp;
	char	*data;
	void	*img;
	double	z;
	double	movex;
	double	movey;
	int		iter;
	int		col;
	int		arg;
	t_julia	*ju;
}				t_env;
typedef struct	s_complexe
{
	double	r;
	double	i;
}				t_complexe;
/*
** Fonction des fractales
*/
void			ft_fractol(int arg);
void			ft_julia(t_env *e);
void			ft_draw_julia(t_env *e);
void			ft_mandel(t_env *e);
void			ft_draw_mandel(t_env *e);
void			ft_mandelbar(t_env *e);
void			ft_draw_mandelbar(t_env *e);
void			help_menu(void);
/*
** Mlx structure et fonctions
*/
int				expose_hook(t_env *e);
void			ft_put_pixel(t_env *e, int x, int y, int col);
int				key_hook(int keycode, t_env *e);
int				reexpose_hook_ju(t_env *e);
int				reexpose_hook_mandel(t_env *e);
int				reexpose_hook_mandelbar(t_env *e);
#endif
