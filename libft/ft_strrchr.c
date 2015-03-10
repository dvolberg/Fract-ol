/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/13 17:39:58 by dvolberg          #+#    #+#             */
/*   Updated: 2014/12/05 20:28:03 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*chr;

	chr = NULL;
	if (*s == (char)c)
		chr = (char *)s;
	while (*s)
	{
		if (*s == c)
			chr = (char *)s;
		s++;
	}
	if (c == '\0')
		chr = (char *)s;
	return (chr);
}
