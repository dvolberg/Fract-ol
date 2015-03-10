/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/13 17:40:26 by dvolberg          #+#    #+#             */
/*   Updated: 2014/12/05 20:25:33 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*tmp;
	size_t	len;

	if (s == NULL)
		return (NULL);
	tmp = (char *)s;
	while (ft_isspace(*tmp))
		tmp++;
	len = ft_strlen(tmp);
	if (len)
	{
		while (ft_isspace(tmp[--len]) || *tmp == '\0')
			;
		tmp = ft_strsub(tmp, 0, (len + 1));
	}
	else
	{
		tmp = ft_strnew(1);
	}
	return (tmp);
}
