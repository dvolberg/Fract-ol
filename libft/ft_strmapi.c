/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/13 17:38:55 by dvolberg          #+#    #+#             */
/*   Updated: 2014/12/05 20:32:10 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	if (s == NULL || f == NULL)
		return (NULL);
	str = (char *)malloc(ft_strlen(s));
	i = 0;
	if (str)
	{
		ft_strstr(str, s);
		while (s[i])
		{
			str[i] = f(i, s[i]);
			i++;
		}
	}
	return (str);
}
