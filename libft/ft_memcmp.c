/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/13 17:41:16 by dvolberg          #+#    #+#             */
/*   Updated: 2014/12/05 20:55:58 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*cpy1;
	const unsigned char	*cpy2;
	size_t				i;

	cpy1 = s1;
	cpy2 = s2;
	i = 0;
	while (i < n)
	{
		if (*cpy1 != *cpy2)
		{
			return (*cpy1 - *cpy2);
		}
		else
		{
			cpy1++;
			cpy2++;
		}
		i++;
	}
	return (0);
}
