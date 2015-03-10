/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/06 11:15:52 by dvolberg          #+#    #+#             */
/*   Updated: 2014/12/05 20:25:27 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_tabdup(char **tabl)
{
	char	**res;
	int		i;

	i = 0;
	res = (char **)malloc(sizeof(char *) * (ft_tablen(tabl) + 1));
	while (tabl[i] != '\0')
	{
		res[i] = ft_strdup(tabl[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
