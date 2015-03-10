/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 10:05:32 by dvolberg          #+#    #+#             */
/*   Updated: 2014/12/05 20:54:38 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_putstr(char const *s)
{
	int		nbr;

	if (s)
	{
		nbr = ft_strlen(s);
		write(1, s, nbr);
		return (nbr);
	}
	else
		return (ft_putstr("(null)"));
}
