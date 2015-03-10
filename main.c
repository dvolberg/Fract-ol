/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 01:01:10 by dvolberg          #+#    #+#             */
/*   Updated: 2015/03/09 16:36:57 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	help_menu(void)
{
	ft_putendl("Usage : ./fractol [Julia][Mandelbrot][Tricorn]");
	ft_putendl("");
	ft_putendl("The most commonly used fractol commands are:");
	ft_putendl("	Julia		:	f{c}(z) = z^2 + c");
	ft_putendl("	Mandelbrot	:	P{c}: C -> C");
	ft_putendl("	Tricorn		:	z -> z^2 + c");
	ft_putendl("");
	ft_putendl("Movement:");
	ft_putendl("	Press UP key	:	Move up");
	ft_putendl("	Press DOWN key	:	Move down");
	ft_putendl("	Press LEFT key	:	Move to the left");
	ft_putendl("	Press RIGHT key	:	Move to the right");
	ft_putendl("	Scroll		:	Zoom in/Zoom out");
	ft_putendl("");
	ft_putendl("Option :");
	ft_putendl("	Press r key	:	Red");
	ft_putendl("	Press g key	:	Green");
	ft_putendl("	Press b key	:	Blue");
	ft_putendl("");
	ft_putendl("	Press e key	:	Red -");
	ft_putendl("	Press f key	:	Green -");
	ft_putendl("	Press v key	:	Blue -");
}

int		is_fractal_name(char *arg)
{
	char *argmin;

	argmin = ft_lowstr(arg);
	if (ft_strcmp(argmin, "julia") == 0)
		return (1);
	else if (ft_strcmp(argmin, "mandelbrot") == 0)
		return (2);
	else if (ft_strcmp(argmin, "tricorn") == 0)
		return (3);
	else if (ft_strcmp(argmin, "help") == 0)
		return (4);
	return (0);
}

int		main(int ac, char **av)
{
	int	i;
	int	arg;

	i = 1;
	while (i < ac)
	{
		if ((arg = is_fractal_name(av[1])) != 0)
			ft_fractol(arg);
		else
			ft_putendl("Usage : ./fractol [Julia][Mandelbrot][Tricorn]");
		i++;
	}
	if (i == 1)
		ft_putendl("Usage : ./fractol [Julia][Mandelbrot][Tricorn]");
	return (0);
}
