/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/13 17:30:07 by dvolberg          #+#    #+#             */
/*   Updated: 2014/12/05 19:37:37 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalpha(int c)
{
	if ((('a' <= c) && (c <= 'z')) || (('A' <= c) && (c <= 'Z')))
		return (1);
	return (0);
}