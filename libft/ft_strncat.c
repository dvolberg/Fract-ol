/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/13 17:39:03 by dvolberg          #+#    #+#             */
/*   Updated: 2014/12/05 20:32:04 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, char *s2, size_t n)
{
	char	*str;

	str = (char *)s1;
	while (*s1)
		s1++;
	while (n--)
	{
		if (!(*s1++ = *s2++))
			return (str);
	}
	*s1 = '\0';
	return (str);
}
