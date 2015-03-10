/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/13 17:36:45 by dvolberg          #+#    #+#             */
/*   Updated: 2014/12/05 20:33:08 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*scpy;

	len = ft_strlen(s1) + 1;
	if ((scpy = (char *)malloc(len)) == NULL)
		return (NULL);
	ft_memcpy(scpy, s1, len);
	return (scpy);
}
