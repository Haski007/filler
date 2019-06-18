/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 20:29:05 by pdemian           #+#    #+#             */
/*   Updated: 2018/11/01 19:38:55 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char *res;

	if (!dst || !src)
		return (0);
	res = dst;
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
	return (res);
}
