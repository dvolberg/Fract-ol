/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lowstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 17:57:36 by dvolberg          #+#    #+#             */
/*   Updated: 2015/03/08 17:58:47 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lowstr(char *str)
{
	char	*tmp;
	int		i;

	tmp = (char *)malloc(sizeof(char) * ft_strlen(str));
	i = 0;
	while (str[i] != '\0')
	{
		tmp[i] = ft_tolower(str[i]);
		i++;
	}
	return (tmp);
}
