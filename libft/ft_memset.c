/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/13 17:34:12 by dvolberg          #+#    #+#             */
/*   Updated: 2014/12/05 20:55:27 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*tmp;
	size_t	i;

	tmp = (char *)b;
	i = 0;
	while (i < len)
	{
		tmp[i] = c;
		i = i + 1;
	}
	b = tmp;
	return (b);
}
